#ifndef BPLATE_COMMON_H_
#define BPLATE_COMMON_H_

#include <stdint.h>
#include <sys/types.h>

typedef const char *const boilerplate;
typedef int               bplate_flag;

// What to print next.
typedef enum bplate_instruction {
	BPLATE_POP_UNIQUE = 0, // Print the next string from the unique string list.
	BPLATE_CALL_CONDITIONAL_UNIQUE, // Call the next unique function in the
	                                // unique function pointer list.
	BPLATE_INDENT,  // Simply print the user's indent preference.
	BPLATE_BRACE,   // Print the user's brace preference.
	BPLATE_NEWLINE, // Print system newline.
	BPLATE_NUM_INSTRUCTIONS,
} bplate_instruction;

typedef char *(*bplate_conditional)(void *);

typedef struct bplate_template {
	size_t              table_size;
	bplate_instruction *table;
	char              **uniques;
	bplate_conditional *conditional_functions;
} bplate_template;

#endif // BPLATE_COMMON_H_
