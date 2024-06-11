
// Generated from Toy.g4 by ANTLR 4.13.1


#include "ToyListener.h"

#include "ToyParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ToyParserStaticData final {
  ToyParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ToyParserStaticData(const ToyParserStaticData&) = delete;
  ToyParserStaticData(ToyParserStaticData&&) = delete;
  ToyParserStaticData& operator=(const ToyParserStaticData&) = delete;
  ToyParserStaticData& operator=(ToyParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

//::antlr4::internal::OnceFlag toyParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ToyParserStaticData *toyParserStaticData = nullptr;

void toyParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (toyParserStaticData != nullptr) {
    return;
  }
#else
  assert(toyParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ToyParserStaticData>(
    std::vector<std::string>{
      "compilationUnit", "function", "parameters", "parameter", "functionBody", 
      "statement", "variableDeclaration", "assignment", "whileStatement", 
      "whileCondition", "whileBody", "expr"
    },
    std::vector<std::string>{
      "", "'('", "')'", "'{'", "'}'", "','", "';'", "'*'", "'='", "'while('", 
      "'+'", "'-'", "'/'", "'<'", "'>'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "Type", 
      "NAME", "INT", "CONSTANT_FLOAT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,19,106,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,5,0,26,8,0,10,0,12,0,29,
  	9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,5,2,43,8,2,10,2,12,
  	2,46,9,2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,5,4,55,8,4,10,4,12,4,58,9,4,1,5,
  	1,5,1,5,3,5,63,8,5,1,6,1,6,1,6,1,7,3,7,69,8,7,1,7,1,7,1,7,1,7,1,8,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,3,11,88,8,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,3,11,96,8,11,1,11,1,11,1,11,5,11,101,8,11,10,11,12,
  	11,104,9,11,1,11,0,1,22,12,0,2,4,6,8,10,12,14,16,18,20,22,0,1,2,0,7,7,
  	10,14,103,0,27,1,0,0,0,2,32,1,0,0,0,4,44,1,0,0,0,6,47,1,0,0,0,8,56,1,
  	0,0,0,10,62,1,0,0,0,12,64,1,0,0,0,14,68,1,0,0,0,16,74,1,0,0,0,18,81,1,
  	0,0,0,20,83,1,0,0,0,22,95,1,0,0,0,24,26,3,2,1,0,25,24,1,0,0,0,26,29,1,
  	0,0,0,27,25,1,0,0,0,27,28,1,0,0,0,28,30,1,0,0,0,29,27,1,0,0,0,30,31,5,
  	0,0,1,31,1,1,0,0,0,32,33,5,15,0,0,33,34,5,16,0,0,34,35,5,1,0,0,35,36,
  	3,4,2,0,36,37,5,2,0,0,37,38,5,3,0,0,38,39,3,8,4,0,39,40,5,4,0,0,40,3,
  	1,0,0,0,41,43,3,6,3,0,42,41,1,0,0,0,43,46,1,0,0,0,44,42,1,0,0,0,44,45,
  	1,0,0,0,45,5,1,0,0,0,46,44,1,0,0,0,47,48,5,15,0,0,48,49,5,16,0,0,49,50,
  	5,5,0,0,50,7,1,0,0,0,51,52,3,10,5,0,52,53,5,6,0,0,53,55,1,0,0,0,54,51,
  	1,0,0,0,55,58,1,0,0,0,56,54,1,0,0,0,56,57,1,0,0,0,57,9,1,0,0,0,58,56,
  	1,0,0,0,59,63,3,12,6,0,60,63,3,14,7,0,61,63,3,16,8,0,62,59,1,0,0,0,62,
  	60,1,0,0,0,62,61,1,0,0,0,63,11,1,0,0,0,64,65,5,15,0,0,65,66,5,16,0,0,
  	66,13,1,0,0,0,67,69,5,7,0,0,68,67,1,0,0,0,68,69,1,0,0,0,69,70,1,0,0,0,
  	70,71,5,16,0,0,71,72,5,8,0,0,72,73,3,22,11,0,73,15,1,0,0,0,74,75,5,9,
  	0,0,75,76,3,18,9,0,76,77,5,2,0,0,77,78,5,3,0,0,78,79,3,20,10,0,79,80,
  	5,4,0,0,80,17,1,0,0,0,81,82,3,22,11,0,82,19,1,0,0,0,83,84,3,8,4,0,84,
  	21,1,0,0,0,85,87,6,11,-1,0,86,88,5,7,0,0,87,86,1,0,0,0,87,88,1,0,0,0,
  	88,89,1,0,0,0,89,96,5,16,0,0,90,96,5,17,0,0,91,92,5,1,0,0,92,93,3,22,
  	11,0,93,94,5,2,0,0,94,96,1,0,0,0,95,85,1,0,0,0,95,90,1,0,0,0,95,91,1,
  	0,0,0,96,102,1,0,0,0,97,98,10,4,0,0,98,99,7,0,0,0,99,101,3,22,11,5,100,
  	97,1,0,0,0,101,104,1,0,0,0,102,100,1,0,0,0,102,103,1,0,0,0,103,23,1,0,
  	0,0,104,102,1,0,0,0,8,27,44,56,62,68,87,95,102
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  toyParserStaticData = staticData.release();
}

}

ToyParser::ToyParser(TokenStream *input) : ToyParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ToyParser::ToyParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ToyParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *toyParserStaticData->atn, toyParserStaticData->decisionToDFA, toyParserStaticData->sharedContextCache, options);
}

ToyParser::~ToyParser() {
  delete _interpreter;
}

const atn::ATN& ToyParser::getATN() const {
  return *toyParserStaticData->atn;
}

std::string ToyParser::getGrammarFileName() const {
  return "Toy.g4";
}

const std::vector<std::string>& ToyParser::getRuleNames() const {
  return toyParserStaticData->ruleNames;
}

const dfa::Vocabulary& ToyParser::getVocabulary() const {
  return toyParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ToyParser::getSerializedATN() const {
  return toyParserStaticData->serializedATN;
}


//----------------- CompilationUnitContext ------------------------------------------------------------------

ToyParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ToyParser::CompilationUnitContext::EOF() {
  return getToken(ToyParser::EOF, 0);
}

std::vector<ToyParser::FunctionContext *> ToyParser::CompilationUnitContext::function() {
  return getRuleContexts<ToyParser::FunctionContext>();
}

ToyParser::FunctionContext* ToyParser::CompilationUnitContext::function(size_t i) {
  return getRuleContext<ToyParser::FunctionContext>(i);
}


size_t ToyParser::CompilationUnitContext::getRuleIndex() const {
  return ToyParser::RuleCompilationUnit;
}

void ToyParser::CompilationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnit(this);
}

void ToyParser::CompilationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnit(this);
}

ToyParser::CompilationUnitContext* ToyParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, ToyParser::RuleCompilationUnit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ToyParser::Type) {
      setState(24);
      function();
      setState(29);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(30);
    match(ToyParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

ToyParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ToyParser::FunctionContext::Type() {
  return getToken(ToyParser::Type, 0);
}

tree::TerminalNode* ToyParser::FunctionContext::NAME() {
  return getToken(ToyParser::NAME, 0);
}

ToyParser::ParametersContext* ToyParser::FunctionContext::parameters() {
  return getRuleContext<ToyParser::ParametersContext>(0);
}

ToyParser::FunctionBodyContext* ToyParser::FunctionContext::functionBody() {
  return getRuleContext<ToyParser::FunctionBodyContext>(0);
}


size_t ToyParser::FunctionContext::getRuleIndex() const {
  return ToyParser::RuleFunction;
}

void ToyParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void ToyParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

ToyParser::FunctionContext* ToyParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, ToyParser::RuleFunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(32);
    match(ToyParser::Type);
    setState(33);
    match(ToyParser::NAME);
    setState(34);
    match(ToyParser::T__0);
    setState(35);
    parameters();
    setState(36);
    match(ToyParser::T__1);
    setState(37);
    match(ToyParser::T__2);
    setState(38);
    functionBody();
    setState(39);
    match(ToyParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

ToyParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ToyParser::ParameterContext *> ToyParser::ParametersContext::parameter() {
  return getRuleContexts<ToyParser::ParameterContext>();
}

ToyParser::ParameterContext* ToyParser::ParametersContext::parameter(size_t i) {
  return getRuleContext<ToyParser::ParameterContext>(i);
}


size_t ToyParser::ParametersContext::getRuleIndex() const {
  return ToyParser::RuleParameters;
}

void ToyParser::ParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameters(this);
}

void ToyParser::ParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameters(this);
}

ToyParser::ParametersContext* ToyParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 4, ToyParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(44);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ToyParser::Type) {
      setState(41);
      parameter();
      setState(46);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

ToyParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ToyParser::ParameterContext::Type() {
  return getToken(ToyParser::Type, 0);
}

tree::TerminalNode* ToyParser::ParameterContext::NAME() {
  return getToken(ToyParser::NAME, 0);
}


size_t ToyParser::ParameterContext::getRuleIndex() const {
  return ToyParser::RuleParameter;
}

void ToyParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void ToyParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}

ToyParser::ParameterContext* ToyParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 6, ToyParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(47);
    match(ToyParser::Type);
    setState(48);
    match(ToyParser::NAME);
    setState(49);
    match(ToyParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionBodyContext ------------------------------------------------------------------

ToyParser::FunctionBodyContext::FunctionBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ToyParser::StatementContext *> ToyParser::FunctionBodyContext::statement() {
  return getRuleContexts<ToyParser::StatementContext>();
}

ToyParser::StatementContext* ToyParser::FunctionBodyContext::statement(size_t i) {
  return getRuleContext<ToyParser::StatementContext>(i);
}


size_t ToyParser::FunctionBodyContext::getRuleIndex() const {
  return ToyParser::RuleFunctionBody;
}

void ToyParser::FunctionBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionBody(this);
}

void ToyParser::FunctionBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionBody(this);
}

ToyParser::FunctionBodyContext* ToyParser::functionBody() {
  FunctionBodyContext *_localctx = _tracker.createInstance<FunctionBodyContext>(_ctx, getState());
  enterRule(_localctx, 8, ToyParser::RuleFunctionBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 98944) != 0)) {
      setState(51);
      statement();
      setState(52);
      match(ToyParser::T__5);
      setState(58);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ToyParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ToyParser::VariableDeclarationContext* ToyParser::StatementContext::variableDeclaration() {
  return getRuleContext<ToyParser::VariableDeclarationContext>(0);
}

ToyParser::AssignmentContext* ToyParser::StatementContext::assignment() {
  return getRuleContext<ToyParser::AssignmentContext>(0);
}

ToyParser::WhileStatementContext* ToyParser::StatementContext::whileStatement() {
  return getRuleContext<ToyParser::WhileStatementContext>(0);
}


size_t ToyParser::StatementContext::getRuleIndex() const {
  return ToyParser::RuleStatement;
}

void ToyParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void ToyParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

ToyParser::StatementContext* ToyParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 10, ToyParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(62);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ToyParser::Type: {
        enterOuterAlt(_localctx, 1);
        setState(59);
        variableDeclaration();
        break;
      }

      case ToyParser::T__6:
      case ToyParser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(60);
        assignment();
        break;
      }

      case ToyParser::T__8: {
        enterOuterAlt(_localctx, 3);
        setState(61);
        whileStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

ToyParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ToyParser::VariableDeclarationContext::Type() {
  return getToken(ToyParser::Type, 0);
}

tree::TerminalNode* ToyParser::VariableDeclarationContext::NAME() {
  return getToken(ToyParser::NAME, 0);
}


size_t ToyParser::VariableDeclarationContext::getRuleIndex() const {
  return ToyParser::RuleVariableDeclaration;
}

void ToyParser::VariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclaration(this);
}

void ToyParser::VariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclaration(this);
}

ToyParser::VariableDeclarationContext* ToyParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 12, ToyParser::RuleVariableDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    match(ToyParser::Type);
    setState(65);
    match(ToyParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

ToyParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ToyParser::AssignmentContext::NAME() {
  return getToken(ToyParser::NAME, 0);
}

ToyParser::ExprContext* ToyParser::AssignmentContext::expr() {
  return getRuleContext<ToyParser::ExprContext>(0);
}


size_t ToyParser::AssignmentContext::getRuleIndex() const {
  return ToyParser::RuleAssignment;
}

void ToyParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void ToyParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}

ToyParser::AssignmentContext* ToyParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 14, ToyParser::RuleAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ToyParser::T__6) {
      setState(67);
      match(ToyParser::T__6);
    }
    setState(70);
    match(ToyParser::NAME);
    setState(71);
    match(ToyParser::T__7);
    setState(72);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

ToyParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ToyParser::WhileConditionContext* ToyParser::WhileStatementContext::whileCondition() {
  return getRuleContext<ToyParser::WhileConditionContext>(0);
}

ToyParser::WhileBodyContext* ToyParser::WhileStatementContext::whileBody() {
  return getRuleContext<ToyParser::WhileBodyContext>(0);
}


size_t ToyParser::WhileStatementContext::getRuleIndex() const {
  return ToyParser::RuleWhileStatement;
}

void ToyParser::WhileStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStatement(this);
}

void ToyParser::WhileStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStatement(this);
}

ToyParser::WhileStatementContext* ToyParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 16, ToyParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    match(ToyParser::T__8);
    setState(75);
    whileCondition();
    setState(76);
    match(ToyParser::T__1);
    setState(77);
    match(ToyParser::T__2);
    setState(78);
    whileBody();
    setState(79);
    match(ToyParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileConditionContext ------------------------------------------------------------------

ToyParser::WhileConditionContext::WhileConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ToyParser::ExprContext* ToyParser::WhileConditionContext::expr() {
  return getRuleContext<ToyParser::ExprContext>(0);
}


size_t ToyParser::WhileConditionContext::getRuleIndex() const {
  return ToyParser::RuleWhileCondition;
}

void ToyParser::WhileConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileCondition(this);
}

void ToyParser::WhileConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileCondition(this);
}

ToyParser::WhileConditionContext* ToyParser::whileCondition() {
  WhileConditionContext *_localctx = _tracker.createInstance<WhileConditionContext>(_ctx, getState());
  enterRule(_localctx, 18, ToyParser::RuleWhileCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(81);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileBodyContext ------------------------------------------------------------------

ToyParser::WhileBodyContext::WhileBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ToyParser::FunctionBodyContext* ToyParser::WhileBodyContext::functionBody() {
  return getRuleContext<ToyParser::FunctionBodyContext>(0);
}


size_t ToyParser::WhileBodyContext::getRuleIndex() const {
  return ToyParser::RuleWhileBody;
}

void ToyParser::WhileBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileBody(this);
}

void ToyParser::WhileBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileBody(this);
}

ToyParser::WhileBodyContext* ToyParser::whileBody() {
  WhileBodyContext *_localctx = _tracker.createInstance<WhileBodyContext>(_ctx, getState());
  enterRule(_localctx, 20, ToyParser::RuleWhileBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    functionBody();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ToyParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ToyParser::ExprContext::NAME() {
  return getToken(ToyParser::NAME, 0);
}

tree::TerminalNode* ToyParser::ExprContext::INT() {
  return getToken(ToyParser::INT, 0);
}

std::vector<ToyParser::ExprContext *> ToyParser::ExprContext::expr() {
  return getRuleContexts<ToyParser::ExprContext>();
}

ToyParser::ExprContext* ToyParser::ExprContext::expr(size_t i) {
  return getRuleContext<ToyParser::ExprContext>(i);
}


size_t ToyParser::ExprContext::getRuleIndex() const {
  return ToyParser::RuleExpr;
}

void ToyParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void ToyParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ToyListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


ToyParser::ExprContext* ToyParser::expr() {
   return expr(0);
}

ToyParser::ExprContext* ToyParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ToyParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ToyParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, ToyParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(95);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ToyParser::T__6:
      case ToyParser::NAME: {
        setState(87);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ToyParser::T__6) {
          setState(86);
          match(ToyParser::T__6);
        }
        setState(89);
        match(ToyParser::NAME);
        break;
      }

      case ToyParser::INT: {
        setState(90);
        match(ToyParser::INT);
        break;
      }

      case ToyParser::T__0: {
        setState(91);
        match(ToyParser::T__0);
        setState(92);
        expr(0);
        setState(93);
        match(ToyParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(102);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(97);

        if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
        setState(98);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 31872) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(99);
        expr(5); 
      }
      setState(104);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ToyParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ToyParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

void ToyParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  toyParserInitialize();
#else
  toyParserInitialize();
  //::antlr4::internal::call_once(toyParserOnceFlag, toyParserInitialize);
#endif
}
