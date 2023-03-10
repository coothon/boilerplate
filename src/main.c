#include "include/bplate.h"
#include "include/common.h"

#include <stdio.h>
#include <stdlib.h>

bplate_flag  indent_style  = 0;
unsigned int indent_amount = 2;
bplate_flag  brace_style   = 0;
bplate_flag  eof_newline   = 1;

int main(void) {

	bplate_c my_c = {
		.comment_greeting = 1,
		.use_std          = 1,
		.main_args        = 0,
		.code_greeting    = 1,
	};

	print_c_template(&my_c, &c_main);

	return 0;
}
