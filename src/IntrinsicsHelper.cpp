#include "IntrinsicsHelper.h"

static std::map<std::string, llvm::Function*> intrinsicFunctions;

void initIntrinsicFunctions(llvm::IRBuilder<>& builder, llvm::Module& module, llvm::LLVMContext& context) {
    // nvvm intrinsics
    llvm::Function* getThreadXIdFunc = getIntrinsicFunction(builder, module, context, "llvm.nvvm.read.ptx.sreg.tid.x");
    llvm::Function* getThreadYIdFunc = getIntrinsicFunction(builder, module, context, "llvm.nvvm.read.ptx.sreg.tid.y");
    llvm::Function* getThreadZIdFunc = getIntrinsicFunction(builder, module, context, "llvm.nvvm.read.ptx.sreg.tid.z");

    llvm::Function* getBlockXDimFunc = getIntrinsicFunction(builder, module, context, "llvm.nvvm.read.ptx.sreg.ntid.x");
    llvm::Function* getBlockYDimFunc = getIntrinsicFunction(builder, module, context, "llvm.nvvm.read.ptx.sreg.ntid.y");
    llvm::Function* getBlockZDimFunc = getIntrinsicFunction(builder, module, context, "llvm.nvvm.read.ptx.sreg.ntid.z");

    llvm::Function* getBlockXIdFunc = getIntrinsicFunction(builder, module, context, "llvm.nvvm.read.ptx.sreg.ctaid.x");
    llvm::Function* getBlockYIdFunc = getIntrinsicFunction(builder, module, context, "llvm.nvvm.read.ptx.sreg.ctaid.y");
    llvm::Function* getBlockZIdFunc = getIntrinsicFunction(builder, module, context, "llvm.nvvm.read.ptx.sreg.ctaid.z");

    llvm::Function* getGridXDimFunc = getIntrinsicFunction(builder, module, context, "llvm.nvvm.read.ptx.sreg.nctaid.x");
    llvm::Function* getGridYDimFunc = getIntrinsicFunction(builder, module, context, "llvm.nvvm.read.ptx.sreg.nctaid.y");
    llvm::Function* getGridZDimFunc = getIntrinsicFunction(builder, module, context, "llvm.nvvm.read.ptx.sreg.nctaid.z");

    intrinsicFunctions.insert(std::make_pair("getThreadXId", getThreadXIdFunc));
    intrinsicFunctions.insert(std::make_pair("getThreadYId", getThreadYIdFunc));
    intrinsicFunctions.insert(std::make_pair("getThreadZId", getThreadZIdFunc));

    intrinsicFunctions.insert(std::make_pair("getBlockXDim", getBlockXDimFunc));
    intrinsicFunctions.insert(std::make_pair("getBlockYDim", getBlockYDimFunc));
    intrinsicFunctions.insert(std::make_pair("getBlockZDim", getBlockZDimFunc));

    intrinsicFunctions.insert(std::make_pair("getBlockXId", getBlockXIdFunc));
    intrinsicFunctions.insert(std::make_pair("getBlockYId", getBlockYIdFunc));
    intrinsicFunctions.insert(std::make_pair("getBlockZId", getBlockZIdFunc));

    intrinsicFunctions.insert(std::make_pair("getGridXDim", getGridXDimFunc));
    intrinsicFunctions.insert(std::make_pair("getGridYDim", getGridYDimFunc));
    intrinsicFunctions.insert(std::make_pair("getGridZDim", getGridZDimFunc));
}

std::map<std::string, llvm::Value*> declareVariables(llvm::IRBuilder<>& builder, llvm::Module& module, llvm::LLVMContext& context){
    // thread variables
    llvm::Value* threadXId = builder.CreateCall(intrinsicFunctions["getThreadXId"]);
    llvm::Value* threadYId = builder.CreateCall(intrinsicFunctions["getThreadYId"]);
    llvm::Value* threadZId = builder.CreateCall(intrinsicFunctions["getThreadZId"]);

    // block variables
    llvm::Value* blockXDim = builder.CreateCall(intrinsicFunctions["getBlockXDim"]);
    llvm::Value* blockYDim = builder.CreateCall(intrinsicFunctions["getBlockYDim"]);
    llvm::Value* blockZDim = builder.CreateCall(intrinsicFunctions["getBlockZDim"]);

    llvm::Value* blockXId = builder.CreateCall(intrinsicFunctions["getBlockXId"]);
    llvm::Value* blockYId = builder.CreateCall(intrinsicFunctions["getBlockYId"]);
    llvm::Value* blockZId = builder.CreateCall(intrinsicFunctions["getBlockZId"]);

    // grid variables
    llvm::Value* gridXDim = builder.CreateCall(intrinsicFunctions["getGridXDim"]);
    llvm::Value* gridYDim = builder.CreateCall(intrinsicFunctions["getGridYDim"]);
    llvm::Value* gridZDim = builder.CreateCall(intrinsicFunctions["getGridZDim"]);

    // return map of variables
    std::map<std::string, llvm::Value*> variables;
    variables.insert(std::make_pair("threadIdX", threadXId));
    variables.insert(std::make_pair("threadIdY", threadYId));
    variables.insert(std::make_pair("threadIdZ", threadZId));
    variables.insert(std::make_pair("blockDimX", blockXDim));
    variables.insert(std::make_pair("blockDimY", blockYDim));
    variables.insert(std::make_pair("blockDimZ", blockZDim));
    variables.insert(std::make_pair("blockIdX", blockXId));
    variables.insert(std::make_pair("blockIdY", blockYId));
    variables.insert(std::make_pair("blockIdZ", blockZId));
    variables.insert(std::make_pair("gridDimX", gridXDim));
    variables.insert(std::make_pair("gridDimY", gridYDim));
    variables.insert(std::make_pair("gridDimZ", gridZDim));

    return variables;
}

llvm::Function* getIntrinsicFunction(llvm::IRBuilder<>& builder, llvm::Module& module, llvm::LLVMContext& context, std::string name) {
    llvm::FunctionType *funcType = llvm::FunctionType::get(
        llvm::Type::getInt32Ty(context),
        {},
        false
    );
    llvm::Function *function = llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        name,
        module
    );
    return function;
}
