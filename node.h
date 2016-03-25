/*
 *  node.h
 *
 *  A polymorphic Linked-list Node Structure
 *
 */
#ifndef NODE_H
#define NODE_H

typedef struct Node {
    void *val;
    struct Node *next;
} Node;

#endif