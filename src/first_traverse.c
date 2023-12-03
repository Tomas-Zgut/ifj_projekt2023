#include <stdbool.h>
#include "errors.h"
#include "syntax_rules.h"
#include "symtable.h"
#include "parser.h"
#include "first_traverse.h"

bool is_token_data_type(TokenT *token) {
    return TOKEN_DT_DOUBLE <= token->type  && token->type <= TOKEN_DT_STRING_NIL;
}


Error get_param_def(Parser_t *parser, symtable_entry_t *entry) {
    TokenT *token;

    do {
        GET_NEXT_AND_CHEK_TOKEN(TOKEN_IDENTIFIER)
        printf("\t param Name\n");
        GET_NEXT_AND_CHEK_TOKEN(TOKEN_IDENTIFIER)
        printf("\t param id\n");
        GET_NEXT_AND_CHEK_TOKEN(TOKEN_COLON)
        printf("\t borng :\n");
        NEXT_TOKEN

        if (!is_token_data_type(token)) {
            return SYNTAX_ERROR;
        }
        printf("\t param type\n");
        NEXT_TOKEN
        if (token->type == TOKEN_COMMA) {
            printf("\t more params!!\n");
            ADD_AND_CHECK_PARAM
            continue;
        }

        CHECK_TOKEN(TOKEN_R_BRACKET)
        printf("\t all params\n");
        ADD_AND_CHECK_PARAM
        entry->params = param_buffer_export(parser->buffer);
        return SUCCESS;

    } while (1);
}   



Error find_allFuncDef(Parser_t* parser) {
    TokenT* token;
    Error err;

    NEXT_TOKEN

    while (token->type != TOKEN_EOF) {
        if (token->type != TOKEN_FUNC) {
            printf("\tskip!\n");
            NEXT_TOKEN
            continue;
        }
        printf("\t function!!!\n");
        GET_NEXT_AND_CHEK_TOKEN(TOKEN_IDENTIFIER)
        printf("\t func_id\n");
        symtable_entry_t* entry;

        if (table_search_global(parser->symtable, token->value.str, &entry)) {
            return UNDEFINED_FUNCTION_ERROR;
        }
        
        table_insert_global(parser->symtable, token->value.str, &entry);
        entry->type = TOKEN_FUNC;

        GET_NEXT_AND_CHEK_TOKEN(TOKEN_L_BRACKET)
        printf("\t bracket\n");
        if ((err = get_param_def(parser,entry)) != SUCCESS) {
            return err;
        }

        NEXT_TOKEN
        if (token->type == TOKEN_LC_BRACKET) {
            entry->return_type = TOKEN_NIL;
            printf("\t void func\n");
            return SUCCESS;
        }

        CHECK_TOKEN(TOKEN_ARROW)
        printf("\t non void func\n");
        NEXT_TOKEN
        if (!is_token_data_type(token)) {
            return SYNTAX_ERROR;
        }
        printf("\t ret type\n");

        entry->return_type = token->type;
        NEXT_TOKEN
    }
    printf("\n");
    return SUCCESS;
}