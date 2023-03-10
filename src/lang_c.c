#include "include/bplate.h"

char *bplate_c_comment_greeting(void *bp) {
	if (!bp) {
		fprintf(stderr,
		        "[ERROR] Something went horribly wrong! (sent from %s)\n",
		        __func__);
		exit(-1);
	}

	// Throw type safety out the window.
	bplate_c *bp_c = (bplate_c *)bp;

	switch (bp_c->comment_greeting) {
	case 0:
		return bplate_c_comment_greeting_none;
	case 1:
		return bplate_c_comment_greeting_temp;
	default: {
		fprintf(stderr,
		        "[ERROR] Something went horribly wrong! (sent from %s)\n",
		        __func__);
		exit(-1);
	}
	}
}

char *bplate_c_use_std(void *bp) {
	if (!bp) {
		fprintf(stderr,
		        "[ERROR] Something went horribly wrong! (sent from %s)\n",
		        __func__);
		exit(-1);
	}

	// Throw type safety out the window.
	bplate_c *bp_c = (bplate_c *)bp;

	switch (bp_c->use_std) {
	case 0:
		return bplate_c_use_std_no;
	case 1:
		return bplate_c_use_std_yes;
	default: {
		fprintf(stderr,
		        "[ERROR] Something went horribly wrong! (sent from %s)\n",
		        __func__);
		exit(-1);
	}
	}
}
char *bplate_c_main_args(void *bp) {
	if (!bp) {
		fprintf(stderr,
		        "[ERROR] Something went horribly wrong! (sent from %s)\n",
		        __func__);
		exit(-1);
	}

	// Throw type safety out the window.
	bplate_c *bp_c = (bplate_c *)bp;

	switch (bp_c->comment_greeting) {
	case 0:
		return bplate_c_main_args_no;
	case 1:
		return bplate_c_main_args_yes;
	default: {
		fprintf(stderr,
		        "[ERROR] Something went horribly wrong! (sent from %s)\n",
		        __func__);
		exit(-1);
	}
	}
}
char *bplate_c_code_greeting(void *bp) {
	if (!bp) {
		fprintf(stderr,
		        "[ERROR] Something went horribly wrong! (sent from %s)\n",
		        __func__);
		exit(-1);
	}

	// Throw type safety out the window.
	bplate_c *bp_c = (bplate_c *)bp;

	if (bp_c->use_std == 0) return bplate_c_code_greeting_none;

	switch (bp_c->comment_greeting) {
	case 0:
		return bplate_c_code_greeting_none;
	case 1:
		return bplate_c_code_greeting_puts;
	case 2:
		return bplate_c_code_greeting_printf;
	default: {
		fprintf(stderr,
		        "[ERROR] Something went horribly wrong! (sent from %s)\n",
		        __func__);
		exit(-1);
	}
	}
}
char *bplate_c_eof_newline(void *bp) {
	if (!bp) {
		fprintf(stderr,
		        "[ERROR] Something went horribly wrong! (sent from %s)\n",
		        __func__);
		exit(-1);
	}

	// Throw type safety out the window.
	bplate_c *bp_c = (bplate_c *)bp;

	switch (eof_newline) {
	case 0:
		return bplate_newline_no;
	case 1:
		return bplate_newline_yes;
	default: {
		fprintf(stderr,
		        "[ERROR] Something went horribly wrong! (sent from %s)\n",
		        __func__);
		exit(-1);
	}
	}
}
