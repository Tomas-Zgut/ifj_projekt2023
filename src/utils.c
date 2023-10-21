#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

buff_ret_t buffer_init(BufferT *buffer) {
    buffer->length = 0;
    buffer->cap = BUFFER_CAP_S;

    buffer->bytes = (char *) calloc(buffer->cap,1);
    
    if (buffer->bytes == NULL) 
        return BUFF_INIT_FAIL;

    return BUFF_INIT_SUCCES;
}


buff_ret_t buffer_append(BufferT *buffer, const char chr) {
    if (buffer->length >= buffer->cap) {
        buffer->bytes = realloc(buffer->bytes,buffer->cap * 2);
        if (buffer->bytes == NULL)
            return BUFF_APPEND_FAIL;
        buffer->cap <<= 1; // buffer->cap *= 2;
    }

    buffer->bytes[buffer->length++] = chr;
    return BUFF_APPEND_SUCCES;  

}

void buffer_clear(BufferT *buffer) {
    buffer->length = 0;
}

char *buffer_export(const BufferT *buffer) {
    char * dst = (char * ) malloc(buffer->length);

    if (dst == NULL)
        return NULL;

    memcpy(dst,buffer->bytes,buffer->length);
    
    return dst;
}

void buffer_detor (BufferT *buffer) {
    free(buffer->bytes);
    buffer->bytes = NULL;
    buffer->cap = 0;
    buffer->length = 0;
}



stack_ret_t Stack_Init( Stack *stack ) {
	if (stack == NULL){
		return STACK_INIT_FAIL;
	}
	stack->array = malloc(STACK_SIZE*sizeof(char));
	if (stack->array == NULL){
		return STACK_INIT_FAIL;
	}
	stack -> topIndex = -1;
    return STACK_INIT_SUCCES;
}

bool Stack_IsEmpty( const Stack *stack ) {
	return stack->topIndex == -1;
}

bool Stack_IsFull( const Stack *stack ) {
	if (stack->topIndex == STACK_SIZE-1){
		return true;
	}
	return false;
}

stack_ret_t Stack_Pop( Stack *stack, char * dataPtr) {
	if (!Stack_IsEmpty(stack)){
        *dataPtr = stack->array[stack->topIndex];
		stack->topIndex--;
        return STACK_POP_SUCCES;
	}
    return STACK_POP_FAIL;
}

stack_ret_t Stack_Push( Stack *stack, char data ) {
	if (!Stack_IsFull(stack)) {
		stack->topIndex++;
		stack->array[stack->topIndex] = data;
        return STACK_PUSH_SUCCES;
	}
	else{
		return STACK_PUSH_FAIL;
	}
}

void Stack_Dispose( Stack *stack ) {
	stack->topIndex = -1;
	free(stack->array);
	stack->array = NULL;
}