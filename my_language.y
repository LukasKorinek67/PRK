%{
/* Original EBNF

MyLang ::= expression

expression ::= term,expression2
expression2 ::= "+",term,expression2 
expression2 ::= ""
term ::= factor,term2
term2 ::= "*",factor,term2
term2 ::= ""
factor ::= "~",factor
factor ::= "("expression")"
factor ::= integer
factor ::= binary
factor ::= hexa
factor ::= array
factor ::= rand

digits ::={"0","1","2","3","4","5","6","7","8","9"}
integer ::= digits+
binary ::= "b",("0"|"1")+
hexa ::= "0x",hexdigits+
hexdigits ::= {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f","A","B","C","D","E","F"}
array ::= "[",arrayNumbers,"]"
arrayNumbers ::= integerArray
arrayNumbers ::= binaryArray
arrayNumbers ::= hexaArray
integerArray ::= integer
integerArray ::= integerArray,separator,integer
binaryArray ::= binary
binaryArray ::= binaryArray,separator,binary
hexaArray ::= hexa
hexaArray ::= hexaArray,separator,hexa
separator = ","

rand ::= "rand(",rand_arguments,")"
rand_arguments ::= ""
rand_arguments ::= data_type
rand_arguments ::= integer,separator,integer
rand_arguments ::= integer,separator,integer,separator,data_type
rand_arguments ::= integer
rand_arguments ::= integer,separator,data_type
rand_arguments ::= integer,separator,integer,separator,integer
rand_arguments ::= integer,separator,integer,separator,integer,separator,data_type

data_type ::= "int"
data_type ::= "bin"
data_type ::= "hex"

*/


#include <stdio.h>
//#include "prk-stack.h"
//#include "prints.h"

int yylex();
void yyerror(const char *s);
extern int yylineno, yylval;

%}
%token INTEGER
%token BINARY
%token HEXA
%token ARRAY_START
%token ARRAY_END
%token PLUS
%token MPY
%token TILDE
%token L_BR
%token R_BR
%token RAND
%token SEPARATOR
%token INT_TYPE
%token BIN_TYPE
%token HEX_TYPE
%token LINE_END

%%

MyLang:
    MyLang expression /*LINE_END*/ { printf("Syntax OK, Rule1\n"); } //Rule1
    | expression /*LINE_END*/ { printf("Syntax OK, Rule2\n");} //Rule2 
    ;

expression:
    term expression2 {printf("Rule3\n");} //Rule3
    ;

expression2:
    PLUS term expression2 {printf("Rule4\n");} //Rule4
    | {printf("Rule5\n");} //Rule5
    ;

term:
    factor term2 {printf("Rule6\n");}; //Rule6
    ;

term2:
    MPY factor term2  {printf("Rule7\n");} //Rule7
    | {printf("Rule8\n");} //Rule8
    ;

factor:
    TILDE factor {printf("Rule9\n");} //Rule9
    | L_BR expression R_BR {printf("Rule10\n");} //Rule10
    | INTEGER {printf("Rule11\n");} //Rule11
    | BINARY {printf("Rule12\n");} //Rule12
    | HEXA {printf("Rule13\n");} //Rule13
    | array {printf("Rule14\n");} //Rule14
    | random {printf("Rule15\n");} //Rule15
   ;

array:
    ARRAY_START arrayNumbers ARRAY_END {printf("Rule16\n");}; //Rule16
    ;

arrayNumbers:
    integerArray {printf("Rule17\n");} //Rule17
    | binaryArray {printf("Rule18\n");} //Rule18
    | hexaArray {printf("Rule19\n");} //Rule19
    ;

integerArray:
    INTEGER {printf("Rule20\n");} //Rule20
    | integerArray SEPARATOR INTEGER {printf("Rule21\n");} //Rule21
    ;

binaryArray:
    BINARY {printf("Rule22\n");} //Rule22
    | binaryArray SEPARATOR BINARY {printf("Rule23\n");} //Rule23
    ;

hexaArray:
    HEXA {printf("Rule24\n");} //Rule24
    | hexaArray SEPARATOR HEXA {printf("Rule25\n");} //Rule25
    ;

random:
    RAND rand_args R_BR {printf("Rule26\n");}; //Rule26
    ;

rand_args:
    data_type {printf("Rule27\n");}; //Rule27
    | INTEGER SEPARATOR INTEGER {printf("Rule28\n");} //Rule28
    | INTEGER SEPARATOR INTEGER SEPARATOR data_type {printf("Rule29\n");} //Rule29
    | INTEGER {printf("Rule30\n");} //Rule30
    | INTEGER SEPARATOR data_type {printf("Rule31\n");} //Rule31
    | INTEGER SEPARATOR INTEGER SEPARATOR INTEGER {printf("Rule32\n");} //Rule32
    | INTEGER SEPARATOR INTEGER SEPARATOR INTEGER SEPARATOR data_type {printf("Rule33\n");} //Rule33
    | {printf("Rule34\n");} //Rule34
    ;
  
data_type:
    INT_TYPE {printf("Rule35\n");} //Rule35
    | BIN_TYPE {printf("Rule36\n");} //Rule36
    | HEX_TYPE {printf("Rule37\n");} //Rule37
    ;

%%

/*%%

MyLang:
    MyLang expression LINE_END { debug_print("Syntax OK, Rule1\n"); } //Rule1
    | expression LINE_END { debug_print("Syntax OK, Rule2\n");} //Rule2 
    ;

expression:
    term expression2 {debug_print("Rule3\n");} //Rule3
    ;

expression2:
    PLUS term expression2 {debug_print("Rule4\n");} //Rule4
    | {debug_print("Rule5");} //Rule5
    ;

term:
    factor term2 {debug_print("Rule6\n");}; //Rule6
    ;

term2:
    MPY factor term2  {debug_print("Rule7\n");} //Rule7
    | {debug_print("Rule8\n");} //Rule8
    ;

factor:
    TILDE factor {debug_print("Rule9\n");} //Rule9
    | L_BR expression R_BR {debug_print("Rule10\n");} //Rule10
    | INTEGER {debug_print("Rule11\n");} //Rule11
    | BINARY {debug_print("Rule12\n");} //Rule12
    | HEXA {debug_print("Rule13\n");} //Rule13
    | array {debug_print("Rule14\n");} //Rule14
    | random {debug_print("Rule15\n");} //Rule15
   ;

array:
    ARRAY_START arrayNumbers ARRAY_END {debug_print("Rule16\n");}; //Rule16
    ;

arrayNumbers:
    integerArray {debug_print("Rule17\n");} //Rule17
    | binaryArray {debug_print("Rule18\n");} //Rule18
    | hexaArray {debug_print("Rule19\n");} //Rule19
    ;

integerArray:
    INTEGER {debug_print("Rule20\n");} //Rule20
    | integerArray SEPARATOR INTEGER {debug_print("Rule21\n");} //Rule21
    ;

binaryArray:
    BINARY {debug_print("Rule22\n");} //Rule22
    | binaryArray SEPARATOR BINARY {debug_print("Rule23\n");} //Rule23
    ;

hexaArray:
    HEXA {debug_print("Rule24\n");} //Rule24
    | hexaArray SEPARATOR HEXA {debug_print("Rule25\n");} //Rule25
    ;

random:
    RAND rand_args R_BR {debug_print("Rule26\n");}; //Rule26
    ;

rand_args:
    data_type {debug_print("Rule27\n");}; //Rule27
    | INTEGER SEPARATOR INTEGER {debug_print("Rule28");} //Rule28
    | INTEGER SEPARATOR INTEGER SEPARATOR data_type {debug_print("Rule29");} //Rule29
    | INTEGER {debug_print("Rule30");} //Rule30
    | INTEGER SEPARATOR data_type {debug_print("Rule31");} //Rule31
    | INTEGER SEPARATOR INTEGER SEPARATOR INTEGER {debug_print("Rule32");} //Rule32
    | INTEGER SEPARATOR INTEGER SEPARATOR INTEGER SEPARATOR data_type {debug_print("Rule33");} //Rule33
    | {debug_print("Rule34");} //Rule34
    ;
  
data_type:
    INT_TYPE {debug_print("Rule35\n");} //Rule35
    | BIN_TYPE {debug_print("Rule36\n");} //Rule36
    | HEX_TYPE {debug_print("Rule37\n");} //Rule37
    ;

%%*/


void yyerror(const char* s) {   
    printf("%s\n",s);
}

int main(){
    // yydebug = 1;
    //debug_print("Entering the main");
    printf("Entering the main\n");
    yyparse();   
}
