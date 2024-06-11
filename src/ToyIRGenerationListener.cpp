#include "ToyIRGenerationListener.h"

#include "IntrinsicsHelper.h"

int uniqueCounter = 0;

void ToyIRGenerationListener::enterEveryRule(antlr4::ParserRuleContext *ctx) {
        std::string ruleName = ruleNames[ctx->getRuleIndex()];
        //std::cout << "Entering: " << ruleName << std::endl;
        //std::cout << "Entering: " << ctx->getText() << std::endl;
}

void ToyIRGenerationListener::exitEveryRule(antlr4::ParserRuleContext *ctx) {
    //std::cout << "Exiting: " << ctx->getText() << std::endl;
}

void ToyIRGenerationListener::enterVariableDeclaration(ToyParser::VariableDeclarationContext *ctx) {
    if(ctx->Type()->getText() == "int32") {
        llvm::Type *type = llvm::Type::getInt32Ty(context);
        llvm::AllocaInst *alloc = builder.CreateAlloca(type, nullptr, ctx->NAME()->getText());
        localVariables[ctx->NAME()->getText()] = alloc;
    } else if (ctx->Type()->getText() == "int64") {
        llvm::Type *type = llvm::Type::getInt64Ty(context);
        llvm::AllocaInst *alloc = builder.CreateAlloca(type, nullptr, ctx->NAME()->getText());
        localVariables[ctx->NAME()->getText()] = alloc;
    }
    else if (ctx->Type()->getText() == "float32") {
        llvm::Type *type = llvm::Type::getFloatTy(context);
        llvm::AllocaInst *alloc = builder.CreateAlloca(type, nullptr, ctx->NAME()->getText());
        localVariables[ctx->NAME()->getText()] = alloc;
    }
    else if (ctx->Type()->getText() == "float64") {
        llvm::Type *type = llvm::Type::getDoubleTy(context);
        llvm::AllocaInst *alloc = builder.CreateAlloca(type, nullptr, ctx->NAME()->getText());
        localVariables[ctx->NAME()->getText()] = alloc;
    }
    else if (ctx->Type()->getText() == "int32*") {
        llvm::Type *type = llvm::Type::getInt32PtrTy(context);
        llvm::AllocaInst *alloc = builder.CreateAlloca(type, nullptr, ctx->NAME()->getText());
        localVariables[ctx->NAME()->getText()] = alloc;
    } else if(ctx->Type()->getText() == "int64*") {
        llvm::Type *type = llvm::Type::getInt64PtrTy(context);
        llvm::AllocaInst *alloc = builder.CreateAlloca(type, nullptr, ctx->NAME()->getText());
        localVariables[ctx->NAME()->getText()] = alloc;
    }
    else if (ctx->Type()->getText() == "float32*") {
        llvm::Type *type = llvm::Type::getFloatPtrTy(context);
        llvm::AllocaInst *alloc = builder.CreateAlloca(type, nullptr, ctx->NAME()->getText());
        localVariables[ctx->NAME()->getText()] = alloc;
    }
    else if (ctx->Type()->getText() == "float64*") {
        llvm::Type *type = llvm::Type::getDoublePtrTy(context);
        llvm::AllocaInst *alloc = builder.CreateAlloca(type, nullptr, ctx->NAME()->getText());
        localVariables[ctx->NAME()->getText()] = alloc;
    }
    else {
        std::cout << "Unknown type: " << ctx->Type()->getText() << std::endl;
    }
}

void ToyIRGenerationListener::exitVariableDeclaration(ToyParser::VariableDeclarationContext *ctx) {
    
}

void ToyIRGenerationListener::enterFunction(ToyParser::FunctionContext *ctx) {
    auto argTypes = std::vector<llvm::Type *>();
    for(auto &arg : ctx->parameters()->parameter()) {
        if(arg->Type()->getText() == "int32") {
            argTypes.push_back(llvm::Type::getInt32Ty(context));
        } else if (arg->Type()->getText() == "int64") {
            argTypes.push_back(llvm::Type::getInt64Ty(context));
        }
        else if (arg->Type()->getText() == "float32") {
            argTypes.push_back(llvm::Type::getFloatTy(context));
        }
        else if (arg->Type()->getText() == "float64") {
            argTypes.push_back(llvm::Type::getDoubleTy(context));
        }
        else if (arg->Type()->getText() == "int32*") {
            argTypes.push_back(llvm::Type::getInt32PtrTy(context));
        } else if(arg->Type()->getText() == "int64*") {
            argTypes.push_back(llvm::Type::getInt64PtrTy(context));
        }
        else if (arg->Type()->getText() == "float32*") {
            argTypes.push_back(llvm::Type::getFloatPtrTy(context));
        }
        else if (arg->Type()->getText() == "float64*") {
            argTypes.push_back(llvm::Type::getDoublePtrTy(context));
        }
        else {
            std::cout << "Unknown type: " << arg->Type()->getText() << std::endl;
        }
        
        //std::cout << "Arg: " << arg->Type()->getText() << " " << arg->NAME()->getText() << std::endl;
    }

    llvm::FunctionType *funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),
        argTypes,
        false
    );

    llvm::Function *func = llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        ctx->NAME()->getText(),
        module
    );

    llvm::BasicBlock *entryBlock = llvm::BasicBlock::Create(context, "entry" + std::to_string(uniqueCounter++), func);
    builder.SetInsertPoint(entryBlock);

    uint counter = 0;
    for(auto &arg : func->args()) {
        arg.setName(ctx->parameters()->parameter(counter)->NAME()->getText());
        namedValues[std::string(arg.getName())] = &arg;
        counter++;
    }

    // create local variables from parameters
    int i = 0;
    for (auto &arg : func->args()) {
        //std::cout << "Storing Arg: " << std::string(arg.getName()) << std::endl;
        localVariables[std::string(arg.getName())] = builder.CreateAlloca(argTypes[i], nullptr, arg.getName());
        builder.CreateStore(&arg, localVariables[std::string(arg.getName())]);
        i++;
    }

    // intrinsics
    auto intrinsicVariables = declareVariables(builder, module, context);
    namedValues.insert(intrinsicVariables.begin(), intrinsicVariables.end());
    for(auto &intrinsic : intrinsicVariables) {
        localVariables[intrinsic.first] = builder.CreateAlloca(intrinsic.second->getType(), nullptr, intrinsic.first);
        builder.CreateStore(intrinsic.second, localVariables[intrinsic.first]);
    }
}

void ToyIRGenerationListener::exitFunction(ToyParser::FunctionContext *ctx) {
    builder.CreateRetVoid();
}

void ToyIRGenerationListener::enterExpr(ToyParser::ExprContext *ctx) {
    if(!ctx->expr().empty()) {

    }
    else if (ctx->INT() != nullptr)
    {
        //std::cout << "INT: " << std::stoi(ctx->INT()->getText()) << std::endl;
        currentValueStack.push(builder.getInt32(std::stoi(ctx->INT()->getText())));
    }
    else if (ctx->NAME() != nullptr)
    {
        //std::cout << "Trying to get: " << ctx->NAME()->getText() << " and is " << localVariables[ctx->NAME()->getText()] << std::endl;
        llvm::Value* value = builder.CreateLoad(localVariables[ctx->NAME()->getText()]->getAllocatedType(), localVariables[ctx->NAME()->getText()]);
        if(ctx->getText()[0] == '*') {
            //std::cout << "Pointer load" << std::endl;
            value = builder.CreateLoad(llvm::Type::getFloatTy(context), value);
        }
        namedValues[ctx->NAME()->getText()] = value;
        currentValueStack.push(value);
    }
    else
    {
        std::cout << "Unknown expression" << std::endl << ctx->INT() << " " << ctx->NAME() << std::endl;
    }
}

void ToyIRGenerationListener::exitExpr(ToyParser::ExprContext *ctx) {
    //std::cout << "Exiting Expr: " << ctx->getText() << std::endl;
    if(!ctx->expr().empty()) {
        llvm::Value *a = currentValueStack.top();
        currentValueStack.pop();
        llvm::Value *b = currentValueStack.top();
        currentValueStack.pop();
        if(ctx->getText().find("+") != std::string::npos) {
            if(b->getType()->isPointerTy()) {
                //std::cout << "Pointer addition" << std::endl;
                // llvm::Value *result = builder.CreateGEP(b->getType()->getPointerElementType(), b, a);
                llvm::Value *result = builder.CreateGEP(llvm::Type::getFloatTy(context), b, a);
                currentValueStack.push(result);
            }
            else if(b->getType()->isFloatTy()) {
                llvm::Value *result = builder.CreateFAdd(a, b);
                currentValueStack.push(result);
            } else {
                llvm::Value *result = builder.CreateAdd(a, b);
                currentValueStack.push(result);
            }
        }
        else if(ctx->getText().find("-") != std::string::npos) {
            llvm::Value *result = builder.CreateSub(a, b);
            currentValueStack.push(result);
        }
        else if(ctx->getText().find("*") != std::string::npos) {
            if(a->getType()->isFloatTy()) {
                llvm::Value *result = builder.CreateFMul(a, b);
                currentValueStack.push(result);
            } else {
                llvm::Value *result = builder.CreateMul(a, b);
                currentValueStack.push(result);
            }
        }
        else if(ctx->getText().find("/") != std::string::npos) {
            llvm::Value *result = builder.CreateSDiv(a, b);
            currentValueStack.push(result);
        }
        else if(ctx->getText().find("<") != std::string::npos) {
            llvm::Value *result = builder.CreateICmpSLT(a, b);
            currentValueStack.push(result);
        }
        else if(ctx->getText().find(">") != std::string::npos) {
            llvm::Value *result = builder.CreateICmpSGT(a, b);
            currentValueStack.push(result);
        }
        else {
            std::cout << "Unknown expression" << std::endl << ctx->getText() << std::endl;
        }
    }
}

void ToyIRGenerationListener::exitAssignment(ToyParser::AssignmentContext *ctx) {
    if(ctx->getText()[0] == '*') {
        //std::cout << "Pointer assignment" << std::endl;
        llvm::Value *ptr = builder.CreateLoad(localVariables[ctx->NAME()->getText()]->getAllocatedType(), localVariables[ctx->NAME()->getText()]);
        llvm::Value *value = currentValueStack.top();
        currentValueStack.pop();
        builder.CreateStore(value, ptr);
    }
    else {
        //std::cout << "Assignment" << std::endl;
        namedValues[ctx->NAME()->getText()] = currentValueStack.top();
        currentValueStack.pop();
        builder.CreateStore(namedValues[ctx->NAME()->getText()], localVariables[ctx->NAME()->getText()]);
    }
}

void ToyIRGenerationListener::enterWhileStatement(ToyParser::WhileStatementContext *ctx) {
    //std::cout << "While statement" << std::endl;
    llvm::BasicBlock *conditionBlock = llvm::BasicBlock::Create(context, "condition" + std::to_string(uniqueCounter++), builder.GetInsertBlock()->getParent());
    llvm::BasicBlock *loopBodyBlock = llvm::BasicBlock::Create(context, "loopBody" + std::to_string(uniqueCounter++), builder.GetInsertBlock()->getParent());
    llvm::BasicBlock *afterLoopBlock = llvm::BasicBlock::Create(context, "afterloop" + std::to_string(uniqueCounter++), builder.GetInsertBlock()->getParent());
    builder.CreateBr(conditionBlock);
    builder.SetInsertPoint(conditionBlock);
    // llvm::Value *condition = namedValues[ctx->NAME()->getText()];
    //llvm::Value *condition = currentValueStack.top();
    //currentValueStack.pop();
    //builder.CreateCondBr(condition, loopBlock, afterLoopBlock);
}

void ToyIRGenerationListener::exitWhileStatement(ToyParser::WhileStatementContext *ctx) {
}


void ToyIRGenerationListener::enterWhileCondition(ToyParser::WhileConditionContext *ctx) {
}

void ToyIRGenerationListener::exitWhileCondition(ToyParser::WhileConditionContext *ctx) {
    llvm::Value *condition = currentValueStack.top();
    currentValueStack.pop();
    builder.CreateCondBr(condition, builder.GetInsertBlock()->getNextNode(), builder.GetInsertBlock()->getNextNode()->getNextNode());
    builder.SetInsertPoint(builder.GetInsertBlock()->getNextNode());

}

void ToyIRGenerationListener::enterWhileBody(ToyParser::WhileBodyContext *ctx) {
    
}

void ToyIRGenerationListener::exitWhileBody(ToyParser::WhileBodyContext *ctx) {
    builder.CreateBr(builder.GetInsertBlock()->getPrevNode());
    builder.SetInsertPoint(builder.GetInsertBlock()->getNextNode());
}
