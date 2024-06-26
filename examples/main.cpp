#include <iostream>
#include <fstream>
#include <cassert>
#include "cuda.h"

// Inspired by an LLVM User Guide: https://llvm.org/docs/NVPTXUsage.html

void checkCudaErrors(CUresult err) {
  assert(err == CUDA_SUCCESS);
}

void executeAdditionExample(CUcontext *context) {
  // Executes C = A + B for float arrays A, B, C; Each thread only executes one addition

  CUmodule    cudaModule;
  CUfunction  function;

  // Load function from file
  std::ifstream t("./addition.ptx");
  if (!t.is_open()) {
    std::cerr << "addition.ptx not found\n";
    return;
  }
  std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
  checkCudaErrors(cuModuleLoadDataEx(&cudaModule, str.c_str(), 0, 0, 0));
  checkCudaErrors(cuModuleGetFunction(&function, cudaModule, "kernel"));

  // Setup
  uint32_t size = 32;

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

  // Check results
  bool correct = true;
  for (unsigned i = 0; i < size && correct; i++) {
    if(hostC[i] - (hostA[i] + hostB[i]) > 0.0000001f) { // Equality check for floats
      correct = false;
      std::cout << hostA[i] << " + " << hostB[i] << " = " << hostC[i] << " is incorrect!\n";
    }
  }

  if (correct) {
    std::cout << "Addition results (only the first 5 of 32):\n";
    for (unsigned i = 0; i < 5; i++) {
      std::cout << hostA[i] << " + " << hostB[i] << " = " << hostC[i] << "\n";
    }
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

void executeSaxpyExample(CUcontext *context) {
  // Executes Z = alpha * X + Y for float arrays X, Y, Z and float scalar alpha; Each thread calculates a chunk of the array

  CUmodule    cudaModule;
  CUfunction  function;

  // Load function from file
  std::ifstream t("./saxpy.ptx");
  if (!t.is_open()) {
    std::cerr << "saxpy.ptx not found\n";
    return;
  }
  std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
  checkCudaErrors(cuModuleLoadDataEx(&cudaModule, str.c_str(), 0, 0, 0));
  checkCudaErrors(cuModuleGetFunction(&function, cudaModule, "kernel"));

  // Setup
  uint32_t size = 104857600; // 100 * 2^20

  CUdeviceptr devBufferX;
  CUdeviceptr devBufferY;
  CUdeviceptr devBufferZ;

  checkCudaErrors(cuMemAlloc(&devBufferX, sizeof(float)*size));
  checkCudaErrors(cuMemAlloc(&devBufferY, sizeof(float)*size));
  checkCudaErrors(cuMemAlloc(&devBufferZ, sizeof(float)*size));

  float* hostX = new float[size];
  float* hostY = new float[size];
  float* hostZ = new float[size];

  // Example inputs
  float alpha = 12.345;
  for (unsigned i = 0; i < size; i++) {
    hostX[i] = ((float) rand()) / 10000000;
    hostY[i] = ((float) rand()) / 10000000;
    hostZ[i] = 0.0f;
  }

  // Copy input to device
  checkCudaErrors(cuMemcpyHtoD(devBufferX, &hostX[0], sizeof(float)*size));
  checkCudaErrors(cuMemcpyHtoD(devBufferY, &hostY[0], sizeof(float)*size));

  unsigned blockSizeX = 32;
  unsigned blockSizeY = 1;
  unsigned blockSizeZ = 1;
  unsigned gridSizeX  = 1;
  unsigned gridSizeY  = 1;
  unsigned gridSizeZ  = 1;

  int elementsPerThread = 32;
  void *KernelParams[] = { &alpha, &devBufferX, &devBufferY, &devBufferZ, &elementsPerThread };

  // Execute kernel
  checkCudaErrors(cuLaunchKernel(function, gridSizeX, gridSizeY, gridSizeZ,
                                 blockSizeX, blockSizeY, blockSizeZ,
                                 0, NULL, KernelParams, NULL));

  // Retrieve results
  checkCudaErrors(cuMemcpyDtoH(&hostZ[0], devBufferZ, sizeof(float)*size));

  std::cout << "Saxpy results (only the first 5):\n";
  for (unsigned i = 0; i < 5; i++) {
    std::cout << alpha << " * " << hostX[i] << " + " << hostY[i] << " = " << hostZ[i] << "\n";
  }

  // Cleanup
  delete [] hostX;
  delete [] hostY;
  delete [] hostZ;

  checkCudaErrors(cuMemFree(devBufferX));
  checkCudaErrors(cuMemFree(devBufferY));
  checkCudaErrors(cuMemFree(devBufferZ));
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

  // Create driver context
  checkCudaErrors(cuCtxCreate(&context, 0, device));

  executeAdditionExample(&context);

  executeSaxpyExample(&context);

  return 0;
}
