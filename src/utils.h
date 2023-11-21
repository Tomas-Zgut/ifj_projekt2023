#include <stdbool.h>

#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Buffet ADT implementation
*/
#define BUFFER_CAP_S 256
typedef struct buffer_t {
    char *bytes;
    int cap;
    int length;
} BufferT;


typedef enum buffer_ret{
    BUFF_INIT_FAIL,
    BUFF_INIT_SUCCES,
    BUFF_APPEND_SUCCES,
    BUFF_APPEND_FAIL
    } buff_ret_t;


/**
 * @brief Initilaize ADT buffer
 * 
 * @param buffer pointer to buffer
 * @retval ret_t BUFF_INIT_SUCCES if succesfull
 * @retval ret_t BUFF_INIT_FAIL if failed
 */
buff_ret_t buffer_init(BufferT *buffer);

/**
 * @brief Appends chr to the end of buffer 
 * 
 * @param buffer pointer to buffer
 * @param chr character to be appended
 * @retval ret_t BUFF_APPEND_SUCCES if succesfull
 * @retval ret_t BUFF_APPEND_FAIL if failed
 */

buff_ret_t buffer_append(BufferT *buffer,const char chr);

/**
 * @brief Clears buffer
 * 
 * @param buffer pointer to buffer
 */
void buffer_clear(BufferT *buffer);


/**
 * @brief exports buffer to char* (chars needs to be freed after use)
 * 
 * @param buffer pointer to buffer
 * @retval char* pointer to char array
 */
char *buffer_export(const BufferT *buffer);

/**
 * @brief frees buffer from memory
 * 
 * @param buffer pointer to buffer
 */
void buffer_detor (BufferT *buffer);

typedef union {
    char* str;
    double d;
    int i;
} litValue;

typedef enum tokentype_e {
    TOKEN_ZERO,
    TOKEN_IDENTIFIER,
    TOKEN_KEYWORD,
    TOKEN_DATATYPE,

    TOKEN_STRING, 
    TOKEN_INTEGER, 
    TOKEN_DECIMAL,
    TOKEN_NIL,

    TOKEN_LET,
    TOKEN_VAR,

    TOKEN_COLON, //:
    TOKEN_ASSIGN, //=
    TOKEN_LC_BRACKET, //{
    TOKEN_RC_BRACKET, //}
    TOKEN_L_BRACKET, //(
    TOKEN_R_BRACKET, //)

    TOKEN_RETURN,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_WHILE,
    TOKEN_FUNC,
    TOKEN_TERM,
    TOKEN_OPERATOR,
    TOKEN_LINE_COMMENT,
    TOKEN_BLOCK_COMMENT,
    TOKEN_ASSIGNMENT,
    TOKEN_LEFT_ROUND_BRACKET,
    TOKEN_RIGHT_ROUND_BRACKET,
    TOKEN_LEFT_CURLY_BRACKET,
    TOKEN_RIGHT_CURLY_BRACKET,
    TOKEN_COLON,
    TOKEN_COMMA,
    TOKEN_EOF
} TokenType;

typedef enum token_ret{
    INT_CONVERSION_SUCCES,
    DOUBLE_CONVERTION_SUCCES,
    VALUE_ASSIGNMENT_FAIL,
    VALUE_ASSIGNMENT_SUCCES,
} token_ret_t;

typedef struct token{
    TokenType type;
    litValue value;
} TokenT;

/**
 * @brief Stack impementation
 * 
 */

#define STACK_SIZE 100 

<<<<<<< HEAD
typedef struct {
	TokenT *array;
=======
typedef struct stack{
	TokenT **array;
>>>>>>> a2729a9 (code zakladny code gen pomocou ast + zopar fcii na vytvaranie ast)
	int topIndex;
} Stack;

typedef enum stack_ret{
    STACK_INIT_SUCCES,
    STACK_INIT_FAIL,
    STACK_POP_SUCCES,
    STACK_POP_FAIL,
    STACK_PUSH_SUCCES,
    STACK_PUSH_FAIL,
    } stack_ret_t;

/**
 * @brief Initialize stack
 * 
 * @param Stack pointer to stack
 * @retval stack_ret_t STACK_INIT_SUCCES succesfull initialization of stack sturcture
 * @retval stack_ret_t STACK_INIT_FAIL failed initialization of stack structure
 */
stack_ret_t Stack_Init(Stack *);

/**
 * @brief If stack is empty return true, returns false otherwise
 * 
 * @param stack pointer to stack
 * @retval true if empty
 * @retval false if not empty
 */
bool Stack_IsEmpty(const Stack *);

/**
 * @brief Returns true if stack is full, false otherwise
 * @param stack pointer to stack
 * @retval true if full
 * @retval false if not full
 */
bool Stack_IsFull(const Stack *);

TokenT Stack_peak(){
    
}
/**
 * @brief Assigns value of the top element of stack to dataPtr
 * 
 * @param stack pointer to stack
 * @param dataPtr pointer to TokenT
 */
void Stack_Top(const Stack *, TokenT *);

/**
 * @brief Pops element from stack
 * 
 * @param stack pointer to stack
 * @retval stack_ret_t STACK_POP_SUCCES if succesfull
 * @retval stack_ret_t STACK_POP_FAIL if failed
 */
stack_ret_t Stack_Pop(Stack *);

/**
 * @brief Stack push operation
 * 
 * @param stack pointer to stack
 * @param TokenT token to be pushed
 * @return stack_ret_t STACK_PUSH_SUCCES if succesfull
 * @return stack_ret_t STACK_PUSH_FAIL if failed
 */

stack_ret_t Stack_Push(Stack *, TokenT*);


/**
 * @brief Cleans up stack from memory
 * 
 * @param stack pointer to stack
 */
void Stack_Dispose(Stack *);

/**
 * @brief ADT Token implementation
*/

/**
 * @brief TokenT initialization
 * 
 * @param token: pointer to a token
 * @param type: type of token
 * @param buff: pointer to a buffer
*/
token_ret_t token_init(TokenT *token,TokenType type, BufferT *buff);


/**
 * @brief Clears token from memory
 * 
 * @param token: pointer to a token
*/
void token_dtor(TokenT *token);


typedef enum ast_node_type {
    BINARY_OPERATOR,
    EXPRESION,
    CONDITION,
    ASSIGNEMENT,
    DECLARATION,
    FUNCTION_CALL,
    CONVERSION,
    IF_ELSE,
    WHILE_LOOP,
    INT_LITERAL,
    DOUBLE_LITERAL,
    STRING_LITERAL,
    NILL,
    PROGRAM,
    VARIABLE,
    STRING_OP,
} ast_node_type_t;

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

typedef struct ast_node {
    ast_node_type_t node_type; //type of node
    litValue value; //value of literal
    char *identifier; //identifier of a variable
    char operator; //arithmetic operator 
    conv_type_t conversion_type; //type of conversoin necesary
    rel_op_t relation_operator; //reation operator
    bool has_else; //flag if_branch containing else
    struct ast_node *next; 
    struct ast_node *last;
    struct ast_node *left; 
    struct ast_node *right;
    struct ast_node *child;

} ast_node_t;


#define New_node(name) ast_node_t *name = calloc(1,sizeof(ast_node_t)); \
    \
    if (name == NULL) { \
        return NULL;     \
    }                     \

void ast_dispose(ast_node_t *ast);
ast_node_t *create_cond(rel_op_t rel_op, ast_node_t *left, ast_node_t *right);
ast_node_t *create_conversion(conv_type_t conv_type, ast_node_t* to_convert);
ast_node_t *create_bin_op(char operator, ast_node_t *left, ast_node_t *right);
ast_node_t *create_leaf(char *identifier, litValue value, ast_node_type_t val_type);



#endif