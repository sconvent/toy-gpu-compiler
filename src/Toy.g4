grammar Toy;

compilationUnit
    : function* EOF
    ;

function
    : Type NAME '(' parameters ')' '{' functionBody '}'
    ;

Type
    : 'void'
    | 'int32'
    | 'int64'
    | 'float32'
    | 'float64'
    | 'int32*'
    | 'int64*'
    | 'float32*'
    | 'float64*'
    ;

NAME
    : [a-zA-Z_]+
    ;

parameters
    : parameter*
    ;

parameter
    : Type NAME ','
    ;

functionBody
    : (statement ';')*
    ;

statement
    : variableDeclaration
    | assignment
    | whileStatement
    ;

variableDeclaration
    : Type NAME
    ;

assignment
    : '*'? NAME '=' expr
    ;

whileStatement
    : 'while(' whileCondition ')' '{' whileBody '}'
    ;

whileCondition
    : expr
    ;

whileBody
    : functionBody
    ;

expr:	expr ('+' | '-' | '*' | '/' | '<' | '>') expr
    | '*'? NAME
    |	INT
    |	'(' expr ')'
    ;

INT : [0-9]+ ;

CONSTANT_FLOAT : [0-9]+ '.' [0-9]+ ;

WS : [ \t\r\n]+ -> skip ;
