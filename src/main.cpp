#include <stdio.h>
#include <iostream>
#include <sstream>
#include <regex>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_os_ostream.h"

#include "toy_parser/ToyBaseListener.h"
#include "antlr4-runtime.h"
#include "toy_parser/ToyParser.h"
#include "toy_parser/ToyLexer.h"
#include "toy_parser/ToyBaseListener.h"

#include "IntrinsicsHelper.h"
#include "ToyIRGenerationListener.h"

static std::unique_ptr<llvm::LLVMContext> globalContext;
static std::unique_ptr<llvm::Module> globalModule;
static std::unique_ptr<llvm::IRBuilder<>> globalBuilder;

int main(int argc, char* argv[]) {
  std::ifstream stream;
  stream.open(argv[1]);
  antlr4::ANTLRInputStream input(stream);
  ToyLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  ToyParser parser(&tokens);

  ToyParser::CompilationUnitContext* tree = parser.compilationUnit();
  
  globalContext = std::make_unique<llvm::LLVMContext>();
  globalModule = std::make_unique<llvm::Module>("test", *globalContext);
  globalBuilder = std::make_unique<llvm::IRBuilder<>>(*globalContext);

    // init intrinsics
    initIntrinsicFunctions(*globalBuilder.get(), *globalModule.get(), *globalContext.get());

    // build the functions
    ToyIRGenerationListener listener(parser.getRuleNames(), *globalContext.get(), *globalModule.get(), *globalBuilder.get());
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

    // Print the LLVM IR code
    std::ostringstream oss;
    llvm::raw_os_ostream ostream(oss);
    globalModule->print(ostream, nullptr);
    std::string moduleIR = oss.str();

    std::cout << "target datalayout = \"e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v16:16:16-v32:32:32-v64:64:64-v128:128:128-n16:32:64\"" << std::endl;
    std::cout << "target triple = \"nvptx64-nvidia-cuda\"" << std::endl << std::endl;
    
    std::cout << moduleIR << std::endl;

    std::cout << "!nvvm.annotations = !{!0}" << std::endl;
    std::cout << "!0 = !{i32 ()* @kernel, !\"kernel\", i32 1}" << std::endl;

  return 0;
}
