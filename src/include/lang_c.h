#ifndef BPLATE_C_H_
#define BPLATE_C_H_

#include "common.h"

#include <stdio.h>
#include <stdlib.h>

static boilerplate bplate_c_use_std_yes           = "#include <stdio.h>\n\n";
static boilerplate bplate_c_use_std_no            = "";
static boilerplate bplate_c_main_args_yes         = "int argc, char **argv";
static boilerplate bplate_c_main_args_no          = "void";
static boilerplate bplate_c_comment_greeting_none = "";
static boilerplate bplate_c_comment_greeting_temp = "// C main template.\n";
static boilerplate bplate_c_code_greeting_none    = "";
static boilerplate bplate_c_code_greeting_puts = "puts(\"Hello, world!\");\n";
static boilerplate bplate_c_code_greeting_printf =
	"printf(\"Hello, world;\n\");\n";

typedef struct bplate_c {
	bplate_flag comment_greeting; // *0=none; 1=temp.
	bplate_flag use_std;          // 0=no; *1=yes.
	bplate_flag main_args;        // *0=no; 1=yes.
	bplate_flag code_greeting;    // 0=none; *1=puts; 2=printf.
} bplate_c;

char *bplate_c_comment_greeting(void *bp);
char *bplate_c_use_std(void *bp);
char *bplate_c_main_args(void *bp);
char *bplate_c_code_greeting(void *bp);
char *bplate_c_eof_newline(void *bp);

static const bplate_template c_main = {
	.table_size = 15,

	.table =
		(bplate_instruction[]){
			BPLATE_CALL_CONDITIONAL_UNIQUE, // Comment greeting;
			BPLATE_CALL_CONDITIONAL_UNIQUE, // includes;
			BPLATE_POP_UNIQUE,              // "int main(";
			BPLATE_CALL_CONDITIONAL_UNIQUE, // main's arguments;
			BPLATE_POP_UNIQUE,              // ")";
			BPLATE_BRACE,                   // brace style;
			BPLATE_POP_UNIQUE,              // "{";
			BPLATE_NEWLINE,                 // system newline;
			BPLATE_INDENT,                  // indent style;
			BPLATE_CALL_CONDITIONAL_UNIQUE, // code greeting;
			BPLATE_INDENT,                  // indent style;
			BPLATE_POP_UNIQUE,              // "return 0;";
			BPLATE_NEWLINE,                 // system newline;
			BPLATE_POP_UNIQUE,              // "}";
			BPLATE_CALL_CONDITIONAL_UNIQUE, // EOF newline.
		},

	.uniques =
		(char *[]){
			"int main(",
			")",
			"{",
			"return 0;",
			"}",
		},

	.conditional_functions =
		(bplate_conditional[]){
			bplate_c_comment_greeting,
			bplate_c_use_std,
			bplate_c_main_args,
			bplate_c_code_greeting,
			bplate_c_eof_newline,
		},
};

void print_c_template(bplate_c *bp_c, bplate_template *tmp);

#endif // BPLATE_C_H_
