
// Generated from Toy.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ToyListener.h"


/**
 * This class provides an empty implementation of ToyListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ToyBaseListener : public ToyListener {
public:

  virtual void enterCompilationUnit(ToyParser::CompilationUnitContext * /*ctx*/) override { }
  virtual void exitCompilationUnit(ToyParser::CompilationUnitContext * /*ctx*/) override { }

  virtual void enterFunction(ToyParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(ToyParser::FunctionContext * /*ctx*/) override { }

  virtual void enterParameters(ToyParser::ParametersContext * /*ctx*/) override { }
  virtual void exitParameters(ToyParser::ParametersContext * /*ctx*/) override { }

  virtual void enterParameter(ToyParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(ToyParser::ParameterContext * /*ctx*/) override { }

  virtual void enterFunctionBody(ToyParser::FunctionBodyContext * /*ctx*/) override { }
  virtual void exitFunctionBody(ToyParser::FunctionBodyContext * /*ctx*/) override { }

  virtual void enterStatement(ToyParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(ToyParser::StatementContext * /*ctx*/) override { }

  virtual void enterVariableDeclaration(ToyParser::VariableDeclarationContext * /*ctx*/) override { }
  virtual void exitVariableDeclaration(ToyParser::VariableDeclarationContext * /*ctx*/) override { }

  virtual void enterAssignment(ToyParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(ToyParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterWhileStatement(ToyParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(ToyParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterWhileCondition(ToyParser::WhileConditionContext * /*ctx*/) override { }
  virtual void exitWhileCondition(ToyParser::WhileConditionContext * /*ctx*/) override { }

  virtual void enterWhileBody(ToyParser::WhileBodyContext * /*ctx*/) override { }
  virtual void exitWhileBody(ToyParser::WhileBodyContext * /*ctx*/) override { }

  virtual void enterExpr(ToyParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(ToyParser::ExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

