#pragma once

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

#include <map>

void initIntrinsicFunctions(llvm::IRBuilder<>& builder, llvm::Module& module, llvm::LLVMContext& context);

std::map<std::string, llvm::Value*> declareVariables(llvm::IRBuilder<>& builder, llvm::Module& module, llvm::LLVMContext& context);

llvm::Function* getIntrinsicFunction(llvm::IRBuilder<>& builder, llvm::Module& module, llvm::LLVMContext& context, std::string name);
