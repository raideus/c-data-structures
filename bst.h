/*
 * bst.h
 *
 * Binary search tree definition and interface
 *
 */

#include <stdbool.h>
#include "btnode.h"

#ifndef BST_H
#define BST_H

typedef struct BST {
    BTNode *head;
} BST;

extern BST* BST_new();
extern BTNode* BST_search(BST *t, int val);
extern bool BST_insert(BST *t, BTNode *node);

// TODO
// extern void BST_remove(BST *t, int val);
// extern void BST_delete(BST *t);

#endif