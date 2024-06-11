
// Generated from Toy.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ToyParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ToyParser.
 */
class  ToyListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCompilationUnit(ToyParser::CompilationUnitContext *ctx) = 0;
  virtual void exitCompilationUnit(ToyParser::CompilationUnitContext *ctx) = 0;

  virtual void enterFunction(ToyParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(ToyParser::FunctionContext *ctx) = 0;

  virtual void enterParameters(ToyParser::ParametersContext *ctx) = 0;
  virtual void exitParameters(ToyParser::ParametersContext *ctx) = 0;

  virtual void enterParameter(ToyParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(ToyParser::ParameterContext *ctx) = 0;

  virtual void enterFunctionBody(ToyParser::FunctionBodyContext *ctx) = 0;
  virtual void exitFunctionBody(ToyParser::FunctionBodyContext *ctx) = 0;

  virtual void enterStatement(ToyParser::StatementContext *ctx) = 0;
  virtual void exitStatement(ToyParser::StatementContext *ctx) = 0;

  virtual void enterVariableDeclaration(ToyParser::VariableDeclarationContext *ctx) = 0;
  virtual void exitVariableDeclaration(ToyParser::VariableDeclarationContext *ctx) = 0;

  virtual void enterAssignment(ToyParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(ToyParser::AssignmentContext *ctx) = 0;

  virtual void enterWhileStatement(ToyParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(ToyParser::WhileStatementContext *ctx) = 0;

  virtual void enterWhileCondition(ToyParser::WhileConditionContext *ctx) = 0;
  virtual void exitWhileCondition(ToyParser::WhileConditionContext *ctx) = 0;

  virtual void enterWhileBody(ToyParser::WhileBodyContext *ctx) = 0;
  virtual void exitWhileBody(ToyParser::WhileBodyContext *ctx) = 0;

  virtual void enterExpr(ToyParser::ExprContext *ctx) = 0;
  virtual void exitExpr(ToyParser::ExprContext *ctx) = 0;


};

