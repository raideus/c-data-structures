/*****************************************************************************
 **
 ** bst.c
 ** 
 ** Binary search tree function implementations
 ** 
 ** Author: Sean Butze
 **
 ****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"

/**********************************************************
 * Private Helper Functions
 *********************************************************/

/*
 * Find and return a node with key equal to val inside the
 * subtree rooted at node n.  Returns NULL if not found
 */
BTNode* find_node(BTNode *n, int val) {
    if (n == NULL || n->val == val) return n;
    if (val < n->val) return find_node(n->left, val);
    return find_node(n->right, val);
}

/*
 * Find and return the node with minimum key value
 * in the subtree rooted at n
 */
BTNode* find_min(BTNode *n) {
    BTNode* node = n;
    while (node->left) {
        node = node->left;
    }
    return node;
}

/*
 * Insert a new node x in the subtree rooted at node n
 *
 * Returns true if node successfully inserted.
 * If a matching key already exists, the node will not be inserted
 * and the function will return false.
 */
bool insert_node(BTNode *n, BTNode *x) {
    if (x->val == n->val) {
        return false; // Value already exists in tree, insertion fails
    }

    // New value is less than n, insert in n's left subtree
    if (x->val < n->val) {
        if (n->left) {
            return insert_node(n->left, x);
        } else {
            n->left = x;
            x->parent = n;
            return true;
        }
    }

    // New value is greater than n, insert in n's right subtree
    if (n->right) {
        return insert_node(n->right, x);
    }

    n->right = x;
    x->parent = n;
    return true;
}


/**********************************************************
 * Public Interface
 *********************************************************/

/* 
 * Create and return a new BTNode structure
 */
BTNode* BTNode_new(int val, void* data) {
    BTNode* node = malloc(sizeof(BTNode));
    node->val = val;
    node->data = data;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/*
 * Create and return a new empty BST 
 */
BST* BST_new() {
    BST *t = malloc(sizeof(BST));
    t->head = NULL;
    return t;
}

/*
 * Search for and return a node with key equal to val
 * within the given BST
 *
 * Returns NULL if no matching node is found
 */
BTNode* BST_search(BST *t, int val) {
    assert(t);
    return find_node(t->head, val);
}

/*
 * Insert a new node into a BST
 *
 * Returns true upon successful insertion,
 * false otherwise.
 */
bool BST_insert(BST *t, BTNode *node) {
    assert(t);
    assert(node);

    if (t->head == NULL) {
        t->head = node;
        return true;
    } else {
        return insert_node(t->head, node);
    }
}

