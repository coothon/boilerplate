#include <stdio.h>
#include <stdlib.h>

#include "include/common.h"
#include "include/bplate.h"

bplate_flag indent_style = 0; // *0=tabs; 1=spaces.
unsigned int indent_amount = 2; // Only used if spaces.
bplate_flag brace_style = 0; // *0=hanging; 1=fallen.
bplate_flag eof_newline = 1; // 0=no; *1=yes;

int main(void) {

	bplate_c my_c = {
		.comment_greeting = 1,
		.use_std = 1,
		.main_args = 0,
		.code_greeting = 1,
	};

	print_c_template(&my_c, &c_main);

	return 0;
}
