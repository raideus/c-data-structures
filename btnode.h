/*
 *  btnode.h
 *
 *  Binary tree node structure
 *
 */
#ifndef BTNODE_H
#define BTNODE_H

typedef struct BTNode {
    int val;
    void *data;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

#endif