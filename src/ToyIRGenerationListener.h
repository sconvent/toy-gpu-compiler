#pragma once

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

#include "toy_parser/ToyBaseListener.h"


static std::map<std::string, llvm::Value *> namedValues;
static std::map<std::string, llvm::AllocaInst *> localVariables;
static std::stack<llvm::Value*> currentValueStack;

class ToyIRGenerationListener : public ToyBaseListener {

public:
    const std::vector<std::string>& ruleNames;
    llvm::Module& module;
    llvm::LLVMContext& context;
    llvm::IRBuilder<>& builder;


    ToyIRGenerationListener(const std::vector<std::string>& ruleNames,
                       llvm::LLVMContext& context,
                       llvm::Module& module,
                       llvm::IRBuilder<>& builder)
    : ruleNames(ruleNames), context(context), module(module), builder(builder) { }

    void enterEveryRule(antlr4::ParserRuleContext *ctx) override;

    void exitEveryRule(antlr4::ParserRuleContext *ctx) override;

    void enterVariableDeclaration(ToyParser::VariableDeclarationContext *ctx) override;

    void exitVariableDeclaration(ToyParser::VariableDeclarationContext *ctx) override;

    void enterFunction(ToyParser::FunctionContext *ctx) override;

    void exitFunction(ToyParser::FunctionContext *ctx) override;

    void enterExpr(ToyParser::ExprContext *ctx) override;

    void exitExpr(ToyParser::ExprContext *ctx) override;

    void exitAssignment(ToyParser::AssignmentContext *ctx) override;

    void enterWhileStatement(ToyParser::WhileStatementContext *ctx) override;

    void exitWhileStatement(ToyParser::WhileStatementContext *ctx) override;

    void enterWhileCondition(ToyParser::WhileConditionContext *ctx) override;

    void exitWhileCondition(ToyParser::WhileConditionContext *ctx) override;

    void enterWhileBody(ToyParser::WhileBodyContext *ctx) override;

    void exitWhileBody(ToyParser::WhileBodyContext *ctx) override;
};
