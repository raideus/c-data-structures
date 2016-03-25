#include "node.h"

#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    unsigned size;
    Node *head;
} Stack;

extern Stack* Stack_new();
extern void Stack_push(Stack *s, void *el);
extern void* Stack_pop(Stack *s);
extern void* Stack_peek(Stack *s);
extern unsigned Stack_size(Stack *s);
extern void Stack_delete(Stack *s);

#endif