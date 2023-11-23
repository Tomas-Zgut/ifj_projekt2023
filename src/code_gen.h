#include "utils.h"
#include "symtable.h"
typedef enum conv_type {
    FI,
    IF,
    IC,
    CI,
} conv_type_t;

typedef enum rel_op {
    LT,
    LTE,
    GT,
    GTE,
    EQ,
    NEQ
} rel_op_t;


typedef enum lit_type { 
    INT_LIT, 
    STRING_LIT,
    DOUBLE_LIT,
    NILL
} lit_type_t;


/**
 * 
*/
void gen_expr_binop(const char operator);

/**
 * 
*/
void gen_expr_conv(conv_type_t conversion_type);

/**
 * 
*/
void gen_cond(rel_op_t relation_operator);

void push_var(char *id, bool global);

void push_literal(litValue value, lit_type_t type);

void clear_expr_stack();


void gen_string_op(const char operator);

void gen_write(char *srtring);

void gen_read(char *identifier, bool global, const char *type);

void gen_assignment(char *identifier, bool global);

void gen_def_var(char *id, bool global);

int get_loop_label_num();

int get_cond_label();

void gen_loop_label(int loop_label_num);

void gen_cnd_jump(char *dest_type, int dest_number);

void gen_func_def(char *name);

void gen_func_return();

void gen_func_pre_call(param_t **params);

void add_func_arg(char *name);

void gen_func_call(char *name);

int get_new_var();


void gen_var_copy(awl_t *awl);
// void gen_cond_branch(ast_node_t *ast);
