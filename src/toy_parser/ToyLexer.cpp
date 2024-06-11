
// Generated from Toy.g4 by ANTLR 4.13.1


#include "ToyLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ToyLexerStaticData final {
  ToyLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ToyLexerStaticData(const ToyLexerStaticData&) = delete;
  ToyLexerStaticData(ToyLexerStaticData&&) = delete;
  ToyLexerStaticData& operator=(const ToyLexerStaticData&) = delete;
  ToyLexerStaticData& operator=(ToyLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

//::antlr4::internal::OnceFlag toylexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ToyLexerStaticData *toylexerLexerStaticData = nullptr;

void toylexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (toylexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(toylexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ToyLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "Type", "NAME", "INT", 
      "CONSTANT_FLOAT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,19,158,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,1,0,1,1,1,1,1,2,1,2,
  	1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,
  	9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,129,8,14,1,15,4,15,
  	132,8,15,11,15,12,15,133,1,16,4,16,137,8,16,11,16,12,16,138,1,17,4,17,
  	142,8,17,11,17,12,17,143,1,17,1,17,4,17,148,8,17,11,17,12,17,149,1,18,
  	4,18,153,8,18,11,18,12,18,154,1,18,1,18,0,0,19,1,1,3,2,5,3,7,4,9,5,11,
  	6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,
  	37,19,1,0,3,3,0,65,90,95,95,97,122,1,0,48,57,3,0,9,10,13,13,32,32,170,
  	0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,
  	0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,
  	0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,
  	1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,1,39,1,0,0,0,3,41,1,0,0,0,5,43,1,0,
  	0,0,7,45,1,0,0,0,9,47,1,0,0,0,11,49,1,0,0,0,13,51,1,0,0,0,15,53,1,0,0,
  	0,17,55,1,0,0,0,19,62,1,0,0,0,21,64,1,0,0,0,23,66,1,0,0,0,25,68,1,0,0,
  	0,27,70,1,0,0,0,29,128,1,0,0,0,31,131,1,0,0,0,33,136,1,0,0,0,35,141,1,
  	0,0,0,37,152,1,0,0,0,39,40,5,40,0,0,40,2,1,0,0,0,41,42,5,41,0,0,42,4,
  	1,0,0,0,43,44,5,123,0,0,44,6,1,0,0,0,45,46,5,125,0,0,46,8,1,0,0,0,47,
  	48,5,44,0,0,48,10,1,0,0,0,49,50,5,59,0,0,50,12,1,0,0,0,51,52,5,42,0,0,
  	52,14,1,0,0,0,53,54,5,61,0,0,54,16,1,0,0,0,55,56,5,119,0,0,56,57,5,104,
  	0,0,57,58,5,105,0,0,58,59,5,108,0,0,59,60,5,101,0,0,60,61,5,40,0,0,61,
  	18,1,0,0,0,62,63,5,43,0,0,63,20,1,0,0,0,64,65,5,45,0,0,65,22,1,0,0,0,
  	66,67,5,47,0,0,67,24,1,0,0,0,68,69,5,60,0,0,69,26,1,0,0,0,70,71,5,62,
  	0,0,71,28,1,0,0,0,72,73,5,118,0,0,73,74,5,111,0,0,74,75,5,105,0,0,75,
  	129,5,100,0,0,76,77,5,105,0,0,77,78,5,110,0,0,78,79,5,116,0,0,79,80,5,
  	51,0,0,80,129,5,50,0,0,81,82,5,105,0,0,82,83,5,110,0,0,83,84,5,116,0,
  	0,84,85,5,54,0,0,85,129,5,52,0,0,86,87,5,102,0,0,87,88,5,108,0,0,88,89,
  	5,111,0,0,89,90,5,97,0,0,90,91,5,116,0,0,91,92,5,51,0,0,92,129,5,50,0,
  	0,93,94,5,102,0,0,94,95,5,108,0,0,95,96,5,111,0,0,96,97,5,97,0,0,97,98,
  	5,116,0,0,98,99,5,54,0,0,99,129,5,52,0,0,100,101,5,105,0,0,101,102,5,
  	110,0,0,102,103,5,116,0,0,103,104,5,51,0,0,104,105,5,50,0,0,105,129,5,
  	42,0,0,106,107,5,105,0,0,107,108,5,110,0,0,108,109,5,116,0,0,109,110,
  	5,54,0,0,110,111,5,52,0,0,111,129,5,42,0,0,112,113,5,102,0,0,113,114,
  	5,108,0,0,114,115,5,111,0,0,115,116,5,97,0,0,116,117,5,116,0,0,117,118,
  	5,51,0,0,118,119,5,50,0,0,119,129,5,42,0,0,120,121,5,102,0,0,121,122,
  	5,108,0,0,122,123,5,111,0,0,123,124,5,97,0,0,124,125,5,116,0,0,125,126,
  	5,54,0,0,126,127,5,52,0,0,127,129,5,42,0,0,128,72,1,0,0,0,128,76,1,0,
  	0,0,128,81,1,0,0,0,128,86,1,0,0,0,128,93,1,0,0,0,128,100,1,0,0,0,128,
  	106,1,0,0,0,128,112,1,0,0,0,128,120,1,0,0,0,129,30,1,0,0,0,130,132,7,
  	0,0,0,131,130,1,0,0,0,132,133,1,0,0,0,133,131,1,0,0,0,133,134,1,0,0,0,
  	134,32,1,0,0,0,135,137,7,1,0,0,136,135,1,0,0,0,137,138,1,0,0,0,138,136,
  	1,0,0,0,138,139,1,0,0,0,139,34,1,0,0,0,140,142,7,1,0,0,141,140,1,0,0,
  	0,142,143,1,0,0,0,143,141,1,0,0,0,143,144,1,0,0,0,144,145,1,0,0,0,145,
  	147,5,46,0,0,146,148,7,1,0,0,147,146,1,0,0,0,148,149,1,0,0,0,149,147,
  	1,0,0,0,149,150,1,0,0,0,150,36,1,0,0,0,151,153,7,2,0,0,152,151,1,0,0,
  	0,153,154,1,0,0,0,154,152,1,0,0,0,154,155,1,0,0,0,155,156,1,0,0,0,156,
  	157,6,18,0,0,157,38,1,0,0,0,7,0,128,133,138,143,149,154,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  toylexerLexerStaticData = staticData.release();
}

}

ToyLexer::ToyLexer(CharStream *input) : Lexer(input) {
  ToyLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *toylexerLexerStaticData->atn, toylexerLexerStaticData->decisionToDFA, toylexerLexerStaticData->sharedContextCache);
}

ToyLexer::~ToyLexer() {
  delete _interpreter;
}

std::string ToyLexer::getGrammarFileName() const {
  return "Toy.g4";
}

const std::vector<std::string>& ToyLexer::getRuleNames() const {
  return toylexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ToyLexer::getChannelNames() const {
  return toylexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ToyLexer::getModeNames() const {
  return toylexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ToyLexer::getVocabulary() const {
  return toylexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ToyLexer::getSerializedATN() const {
  return toylexerLexerStaticData->serializedATN;
}

const atn::ATN& ToyLexer::getATN() const {
  return *toylexerLexerStaticData->atn;
}




void ToyLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  toylexerLexerInitialize();
#else
  toylexerLexerInitialize();
  //::antlr4::internal::call_once(toylexerLexerOnceFlag, toylexerLexerInitialize);
#endif
}
