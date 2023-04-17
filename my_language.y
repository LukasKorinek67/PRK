%{
/* Original EBNF

MyLang ::= expression

expression ::= term,expression2
expression2 ::= "+",term,expression2 
expression2 ::= ""
term ::= term2,term3
term2 ::= factor,operation
term3 ::= "*", term, term3
term3 ::= ""
operation ::= "~",factor,operation
operation ::= ""

term2 ::= "*",factor,term2
term2 ::= term3
term2 ::= ""
term3 ::= "~",factor,term3
term3 ::= ""
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
    MyLang expression LINE_END { printf("----- Syntax OK, Rule1 -----\n"); } //Rule1
    | expression LINE_END { printf("----- Syntax OK, Rule2 -----\n");} //Rule2
    ;

expression:
    term expression2 {printf("Rule3\n");} //Rule3
    ;

expression2:
    PLUS term expression2 {printf("Rule4 - operator +\n");} //Rule4
    | {printf("Rule5\n");} //Rule5
    ;

term:
    term2 term3 {printf("Rule6\n");}; //Rule6
    ;

term2:
    factor operation {printf("Rule7\n");}; //Rule7
    ;

term3:
    MPY term term3  {printf("Rule8 - operator * \n");} //Rule8
    | {printf("Rule9\n");} //Rule9
    ;

operation:
    TILDE factor operation  {printf("Rule10 - operator ~ \n");} //Rule10
    | {printf("Rule11\n");} //Rule11
    ;

factor:
    L_BR expression R_BR {printf("Rule12 - závorky\n");} //Rule12
    | INTEGER {printf("Rule13 - INTEGER\n");} //Rule13
    | BINARY {printf("Rule14 - BINARY\n");} //Rule14
    | HEXA {printf("Rule15 - HEXA\n");} //Rule15
    | array {printf("Rule16\n");} //Rule16
    | random {printf("Rule17 - random\n");} //Rule17
   ;

array:
    ARRAY_START arrayNumbers ARRAY_END {printf("Rule18\n");}; //Rule18
    ;

arrayNumbers:
    integerArray {printf("Rule19 - int array\n");} //Rule19
    | binaryArray {printf("Rule20 - bin array\n");} //Rule20
    | hexaArray {printf("Rule21 - hexarray\n");} //Rule21
    ;

integerArray:
    INTEGER {printf("Rule22\n");} //Rule22
    | integerArray SEPARATOR INTEGER {printf("Rule23\n");} //Rule23
    ;

binaryArray:
    BINARY {printf("Rule24\n");} //Rule24
    | binaryArray SEPARATOR BINARY {printf("Rule25\n");} //Rule25
    ;

hexaArray:
    HEXA {printf("Rule26\n");} //Rule26
    | hexaArray SEPARATOR HEXA {printf("Rule27\n");} //Rule27
    ;

random:
    RAND rand_args R_BR {printf("Rule28\n");}; //Rule28
    ;

rand_args:
    data_type {printf("Rule29 - rand(type)\n");}; //Rule29
    | INTEGER SEPARATOR INTEGER {printf("Rule30 - rand(x,y)\n");} //Rule30
    | INTEGER SEPARATOR INTEGER SEPARATOR data_type {printf("Rule31 - rand(x,y,type)\n");} //Rule31
    | INTEGER {printf("Rule32 - rand(n)\n");} //Rule32
    | INTEGER SEPARATOR data_type {printf("Rule33 - rand(n,type)\n");} //Rule33
    | INTEGER SEPARATOR INTEGER SEPARATOR INTEGER {printf("Rule34 - rand(x,y,n)\n");} //Rule34
    | INTEGER SEPARATOR INTEGER SEPARATOR INTEGER SEPARATOR data_type {printf("Rule35 - rand(x,y,n,type)\n");} //Rule35
    | {printf("Rule36 - rand()\n");} //Rule36
    ;
  
data_type:
    INT_TYPE {printf("Rule37 - type int\n");} //Rule37
    | BIN_TYPE {printf("Rule38 - type bin\n");} //Rule38
    | HEX_TYPE {printf("Rule39 - type hex\n");} //Rule39
    ;

%%



void yyerror(const char* s) {   
    printf("%s\n",s);
}

int main(){
    // yydebug = 1;
    //debug_print("Entering the main");
    printf("Entering the main\n");
    yyparse();
    printf("Out of main.\n");
}
