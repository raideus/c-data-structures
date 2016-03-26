/*****************************************************************************
 **
 ** bst.h
 ** 
 ** Binary search tree definition and interface
 ** 
 ** Author: Sean Butze
 **
 ****************************************************************************/

#include <stdbool.h>

#ifndef BST_H
#define BST_H

// Binary Tree Node Definition
typedef struct BTNode {
    int val;
    void *data;
    struct BTNode *parent;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

/* 
 * Create and return a new BTNode structure
 */
extern BTNode* BTNode_new(int val, void *data);

// Binary Search Tree Definition
typedef struct BST {
    BTNode *head;
} BST;

/*
 * Create and return a new empty BST 
 */
extern BST* BST_new();

/*
 * Search for and return a node with key equal to val
 * within the given BST
 *
 * Returns NULL if no matching node is found
 */
extern BTNode* BST_search(BST *t, int val);

/*
 * Insert a new node into a BST
 *
 * Returns true upon successful insertion,
 * false otherwise.
 */
extern bool BST_insert(BST *t, BTNode *node);


#endif
