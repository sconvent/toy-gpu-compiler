#include <iostream>
#include <fstream>
#include <cassert>
#include "cuda.h"

// Inspired by an LLVM User Guide: https://llvm.org/docs/NVPTXUsage.html

void checkCudaErrors(CUresult err) {
  assert(err == CUDA_SUCCESS);
}

void executeAdditionExample(CUcontext *context, std::string *str) {
  // Executes C = A + B for float arrays A, B, C

  CUmodule    cudaModule;
  CUfunction  function;
  // Load function from string
  checkCudaErrors(cuModuleLoadDataEx(&cudaModule, str->c_str(), 0, 0, 0));
  checkCudaErrors(cuModuleGetFunction(&function, cudaModule, "kernel"));

  uint32_t size = 256;

  CUdeviceptr devBufferA;
  CUdeviceptr devBufferB;
  CUdeviceptr devBufferC;

  checkCudaErrors(cuMemAlloc(&devBufferA, sizeof(float)*size));
  checkCudaErrors(cuMemAlloc(&devBufferB, sizeof(float)*size));
  checkCudaErrors(cuMemAlloc(&devBufferC, sizeof(float)*size));

  float* hostA = new float[size];
  float* hostB = new float[size];
  float* hostC = new float[size];

  // Example inputs
  for (unsigned i = 0; i < size; i++) {
    hostA[i] = (float) (i*2);
    hostB[i] = (float) (i*4);
    hostC[i] = 0.0f;
  }

  // Copy input to device
  checkCudaErrors(cuMemcpyHtoD(devBufferA, &hostA[0], sizeof(float)*size));
  checkCudaErrors(cuMemcpyHtoD(devBufferB, &hostB[0], sizeof(float)*size));

  unsigned blockSizeX = 32;
  unsigned blockSizeY = 1;
  unsigned blockSizeZ = 1;
  unsigned gridSizeX  = 1;
  unsigned gridSizeY  = 1;
  unsigned gridSizeZ  = 1;

  void *KernelParams[] = { &devBufferA, &devBufferB, &devBufferC };

  // Execute kernel
  checkCudaErrors(cuLaunchKernel(function, gridSizeX, gridSizeY, gridSizeZ,
                                 blockSizeX, blockSizeY, blockSizeZ,
                                 0, NULL, KernelParams, NULL));

  // Retrieve results
  checkCudaErrors(cuMemcpyDtoH(&hostC[0], devBufferC, sizeof(float)*size));

  std::cout << "Results:\n";
  for (unsigned i = 0; i != size; ++i) {
    std::cout << hostA[i] << " + " << hostB[i] << " = " << hostC[i] << "\n";
  }

  // Cleanup
  delete [] hostA;
  delete [] hostB;
  delete [] hostC;

  checkCudaErrors(cuMemFree(devBufferA));
  checkCudaErrors(cuMemFree(devBufferB));
  checkCudaErrors(cuMemFree(devBufferC));
  checkCudaErrors(cuModuleUnload(cudaModule));
}

int main(int argc, char **argv) {
  CUdevice    device;
  CUcontext   context;
  int         devCount;

  // CUDA init
  checkCudaErrors(cuInit(0));
  checkCudaErrors(cuDeviceGetCount(&devCount));
  checkCudaErrors(cuDeviceGet(&device, 0));

  char name[128];
  checkCudaErrors(cuDeviceGetName(name, 128, device));
  std::cout << "Using CUDA Device [0]: " << name << "\n";

  int devMajor, devMinor;
  checkCudaErrors(cuDeviceComputeCapability(&devMajor, &devMinor, device));
  std::cout << "Device Compute Capability: "
            << devMajor << "." << devMinor << "\n";
  if (devMajor < 2) {
    std::cerr << "ERROR: Device 0 is not SM 2.0 or greater\n";
    return 1;
  }

  std::ifstream t("./addition.ptx");
  if (!t.is_open()) {
    std::cerr << "addition.ptx not found\n";
    return 1;
  }
  std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());

  // Create driver context
  checkCudaErrors(cuCtxCreate(&context, 0, device));

/*
  // Create module for object
  checkCudaErrors(cuModuleLoadDataEx(&cudaModule, str.c_str(), 0, 0, 0));

  // Get kernel function
  checkCudaErrors(cuModuleGetFunction(&function, cudaModule, "kernel"));

  executeAdditionExample(&context, &str)

  uint32_t size = 256;

  float factor = 2.0f;


  // Device data
  CUdeviceptr devBufferA;
  CUdeviceptr devBufferB;
  CUdeviceptr devBufferC;

  checkCudaErrors(cuMemAlloc(&devBufferA, sizeof(float)*size));
  checkCudaErrors(cuMemAlloc(&devBufferB, sizeof(float)*size));
  checkCudaErrors(cuMemAlloc(&devBufferC, sizeof(float)*size));

  float* hostA = new float[size];
  float* hostB = new float[size];
  float* hostC = new float[size];

  // Populate input
  for (unsigned i = 0; i != size; ++i) {
    hostA[i] = (float)i;
    hostB[i] = (float)(2*i);
    hostC[i] = 0.0f;
  }

  checkCudaErrors(cuMemcpyHtoD(devBufferA, &hostA[0], sizeof(float)*size));
  checkCudaErrors(cuMemcpyHtoD(devBufferB, &hostB[0], sizeof(float)*size));


  unsigned blockSizeX = 32;
  unsigned blockSizeY = 1;
  unsigned blockSizeZ = 1;
  unsigned gridSizeX  = 1;
  unsigned gridSizeY  = 1;
  unsigned gridSizeZ  = 1;

  // Kernel parameters
  void *KernelParams[] = { &factor, &devBufferA, &devBufferB, &devBufferC , &size};

  std::cout << "Launching kernel\n";

  // Kernel launch
  checkCudaErrors(cuLaunchKernel(function, gridSizeX, gridSizeY, gridSizeZ,
                                 blockSizeX, blockSizeY, blockSizeZ,
                                 0, NULL, KernelParams, NULL));

  // Retrieve device data
  checkCudaErrors(cuMemcpyDtoH(&hostC[0], devBufferC, sizeof(float)*size));


  std::cout << "Results:\n";
  for (unsigned i = 0; i != size; ++i) {
    std::cout << factor  << "*" << hostA[i] << " + " << hostB[i] << " = " << hostC[i] << "\n";
  }

  // Cleanup
  delete [] hostA;
  delete [] hostB;
  delete [] hostC;

  checkCudaErrors(cuMemFree(devBufferA));
  checkCudaErrors(cuMemFree(devBufferB));
  checkCudaErrors(cuMemFree(devBufferC));
  checkCudaErrors(cuModuleUnload(cudaModule));
  checkCudaErrors(cuCtxDestroy(context));
*/
  checkCudaErrors(cuCtxDestroy(context));

  return 0;
}
