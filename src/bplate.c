#include "include/bplate.h"

void print_c_template(bplate_c *bp_c, bplate_template *tmp) {
	for (size_t i = 0, current_unique = 0, current_conditional = 0; i < tmp->table_size; ++i) {
		switch(tmp->table[i]) {
		case BPLATE_POP_UNIQUE: {
			printf("%s", tmp->uniques[current_unique++]);
		} break;
		case BPLATE_CALL_CONDITIONAL_UNIQUE: {
			printf("%s", tmp->conditional_functions[current_conditional++]((void *)bp_c));
		} break;
		case BPLATE_INDENT: {
			if (indent_style == 0) {
				printf("\t");
			} else {
				for (unsigned int o = 0; o < indent_amount; ++o) {
					printf(" ");
				}
			}
		} break;
		case BPLATE_BRACE: {
			if (brace_style == 0) {
				printf(" ");
			} else {
				printf("\n");
			}
		} break;
		case BPLATE_NEWLINE: {
			printf("\n");
		} break;
		default: {
			fprintf(stderr, "[ERROR] Something went horribly wrong! (sent from %s)\n", __func__);
			exit(1);
		}
		}
	}
}
