/*****************************************************************************
 **
 ** stack.c
 ** 
 ** Function implementations for Stack, a polymorphic LIFO data structure
 ** 
 ** Author: Sean Butze
 **
 ****************************************************************************/


#include <assert.h>
#include <stdlib.h>
#include "stack.h"


Stack* Stack_new() {
    Stack *s = malloc(sizeof(Stack));
    s->size = 0;
    s->head = NULL;
    return s;
}

void Stack_push(Stack *s, void *el) {
    Node *temp = s->head;
    Node *new_head = malloc(sizeof(Node));
    new_head->val = el;
    new_head->next = temp;
    s->head = new_head;
    s->size++;
}

void* Stack_peek(Stack *s) {
    assert(s && s->size > 0);
    return (s->head->val);
}

void* Stack_pop(Stack *s) {
    assert(s && s->size > 0);
    Node *head = s->head;
    void *headval = head->val;
    s->head = head->next;
    s->size--;
    free(head);
    return (headval);
}

unsigned Stack_size(Stack *s) {
    assert(s);
    return(s->size);
}

void Stack_delete(Stack *s) {
    assert(s);
    Node *i1, *i2;

    for (i1 = s->head; i1; i1 = i2) {
        i2 = i1->next;
        free(i1);
    }

    free(s);
}