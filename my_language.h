//#define VERBOSE 1 
#undef VERBOSE 

#define _CPP_IOSTREAMS y



/* Define constants for patterns - used in process_pattern function */

#define PATT_NO 0 /* No pattern will be sent to parser */

#define PATT_INT 1 /* Integer number detected */
#define PATT_BIN 2 /* Binary number detected */
#define PATT_HEX 3 /* Hexadecimal number detected */
#define PATT_ARRAY_START 4 /* Array detected */
#define PATT_ARRAY_END 5 /* Array detected */
#define PATT_PLUS 6 /* Plus operator */
#define PATT_MPY 7  /* Multiplication operator */
#define PATT_TIL 8  /* Tilde ~ operator */
#define PATT_L_BR 9 /* Left bracket */
#define PATT_R_BR 10 /* Close bracket */
#define PATT_RAND 11 /* Random function */
#define PATT_SEPARATOR 12 /* Separator */
#define PATT_TYPE_INT 13 /* Data type int */
#define PATT_TYPE_BIN 14 /* Data type bin */
#define PATT_TYPE_HEX 15 /* Data type hex */

#define PATT_ERR 100 /* Error in patterns: exit on errors! */


#define ERR_PATTERN 1 /* Lexer: an error pattern detected. */

char *ErrMsgMain = "Error detected with code:";

char Err_Messages[][255] = {"No Error","Lexer: Wrong character detected. Exiting."};
