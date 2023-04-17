%{
/* Variable declaration */
int lines_done=0;
int void_lines_done=0;
int lines_comment=0;
int add_ops=0;
int mpy_ops=0;
int til_ops=0;
int br_left=0;
int br_right=0;
int int_values=0;
int bin_values=0;
int hex_values=0;
int array_start=0;
int array_end=0;
int rand_function=0;
int separator=0;
int type_int=0;
int type_bin=0;
int type_hex=0;
int errors_detected=0;

#include "my_language.h"
#include "y.tab.h"


/* Function prototypes */

int process_pattern(int number, char *Message, int Pattern);
void print_error(int ERRNO);
void print_msg(char *msg);

%}

%%
^#.*\n {lines_comment=process_pattern(lines_comment,"Comment deleted.\n",PATT_NO);}
\+     {
        add_ops=process_pattern(add_ops,"Add operator detected.",PATT_PLUS);        
        return PLUS; 
        }
\*     {
        mpy_ops=process_pattern(mpy_ops,"Multiplication operator detected.",PATT_MPY);
        return MPY;
        }
"~"     {
        til_ops=process_pattern(til_ops,"Tilde operator detected.",PATT_TIL);
        return TILDE;
        }
\(      {
        br_left=process_pattern(br_left,"Opening bracket detected.",PATT_L_BR);
        return L_BR;
        }
\)      {
        br_right=process_pattern(br_right,"Closing bracket detected.", PATT_R_BR);
        return R_BR;
        } 
[0-9]+  {
        int_values=process_pattern(int_values,"Integer number detected.", PATT_INT);   
        yylval.int_value = atoi(yytext);              
        return INTEGER;
        }
b[01]+  {
        bin_values=process_pattern(bin_values,"Binary number detected.", PATT_BIN);   
        yylval.str_value = strdup(yytext);            
        return BINARY;
        }
"0x"[0-9a-fA-F]+ {
        hex_values=process_pattern(hex_values,"Hexadecimal number detected.", PATT_HEX);   
        yylval.str_value = strdup(yytext);        
        return HEXA;
        }
\[      {
        array_start=process_pattern(array_start,"Start of array detected.", PATT_ARRAY_START);                 
        return ARRAY_START;
        }
\]      {
        array_end=process_pattern(array_end,"End of array detected.", PATT_ARRAY_END);                 
        return ARRAY_END;
        }
rand\(  {
        rand_function=process_pattern(rand_function,"Random function detected.", PATT_RAND);                 
        return RAND;
        }
,       {
        separator=process_pattern(separator,"Separator detected.", PATT_SEPARATOR);                
        return SEPARATOR;
        }
"int"   {
        type_int=process_pattern(type_int,"Data type int detected.", PATT_TYPE_INT);              
        return INT_TYPE;
        }
"bin"   {
        type_bin=process_pattern(type_bin,"Data type bin detected.", PATT_TYPE_BIN);               
        return BIN_TYPE;
        }
"hex"   {
        type_hex=process_pattern(type_hex,"Data type hex detected.", PATT_TYPE_HEX);            
        return HEX_TYPE;
        }
^\n    {        
        void_lines_done++;        
        //print_msg("Void line detected.\n");
        printf("Void line detected.\n");}   

\n     {
        lines_done++;
        //print_msg("Line detected.\n");
        printf("Line detected.\n");
        return LINE_END;
        }

[ \t]+ ; /*Skip whitespace*/

.      {errors_detected=process_pattern(errors_detected,"An error detected.\n",PATT_ERR);} /* What is not from alphabet: lexer error  */
%%


/* Function declaration */

int yywrap(void) {
return 1;
}
/*int main()
    {
        yylex();
        printf("%d of total errors detected in input file.\n",errors_detected);
        printf("%d of binary numbers detected.\n",bin_values);
        printf("%d of comment lines canceled.\n",lines_comment);
        printf("%d of add operators detected.\n",add_ops);
        printf("%d of multiplication operators detected.\n",mpy_ops);
        printf("%d of void lines ignored.\nFile processed sucessfully.\n",void_lines_done);
        printf("Totally %d of valid code lines in file processed.\nFile processed sucessfully.\n",lines_done);
        
    }*/


void print_msg(char *msg){
        #ifdef VERBOSE
                printf("%s",msg);
        #endif
}

void print_error(int ERRNO){
    #ifdef VERBOSE
        char *message = Err_Messages[ERRNO];
        printf("%s - %d - %s\n",ErrMsgMain,ERR_PATTERN,message);
    #endif
}

int process_pattern(int number,char* Message, int Pattern) {
    if (Pattern == PATT_ERR) {       
        print_error(ERR_PATTERN);        
        exit(ERR_PATTERN);
    }    

    print_msg(Message);
    
    number++;
    return number;
}
