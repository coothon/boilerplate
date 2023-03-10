#ifndef BPLATE_H_
#define BPLATE_H_

#include "common.h"
#include "lang_c.h"

// Language-independent boilerplate.
static boilerplate bplate_tab = "\t";
static boilerplate bplate_tab_soft = " ";
static boilerplate bplate_hanging_brace = " "; // Inserted between function brackets and the opening curly brace.
static boilerplate bplate_fallen_brace = "\n"; // ^
static boilerplate bplate_newline_no = "";
static boilerplate bplate_newline_yes = "\n";

extern bplate_flag indent_style; // *0=tabs; 1=spaces.
extern unsigned int indent_amount; // Only used if spaces.
extern bplate_flag brace_style; // *0=hanging; 1=fallen.
extern bplate_flag eof_newline; // 0=no; *1=yes;

#endif // BPLATE_H_
