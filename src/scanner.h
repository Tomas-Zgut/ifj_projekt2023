#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include "errors.h"
#include "utils.h"

#ifndef SCANNER_H
#define SCANNER_H

typedef enum fsm_state_e {
    STATE_START,
    STATE_TEXT,
    STATE_SLASH,
    STATE_LINE_COMMENT,
    STATE_BLOCK_COMMENT,
    STATE_END_BLOCK_COMMENT,
    STATE_STRING,
    STATE_MULTILINE_STRING,
    STATE_TWO_DOUBLE_QUOTES,
    STATE_EQUALS,
    STATE_EXCLAMATION,
    STATE_QUESTION,
    STATE_RELATIONAL_OPERATOR,
    STATE_NUMBER,
    STATE_DECIMAL,
    STATE_DECIMAL_POINT
} ScannerState;

#define NOF_KEYWORDS 8
#define NOF_DATATYPES 3
#define MAX_DTT_KWD_LEN 10

TokenT *generate_token();

#endif