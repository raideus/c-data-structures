#include <stdlib.h>
#include <assert.h>
#include "bst.h"


BST* BST_new() {
    BST *t = malloc(sizeof(BST));
    t->head = NULL;
    return t;
}

BTNode* find_node(BTNode *n, int val) {
    if (n == NULL || n->val == val) return n;
    if (n->val < val) return find_node(n->left, val);
    return find_node(n->right, val);
}

BTNode* BST_search(BST *t, int val) {
    assert(t);
    return find_node(t->head, val);
}

bool insert_node(BTNode *n, BTNode *x) {
    if (x->val == n->val) {
        return false; // Value already exists in tree, insertion fails
    }

    if (x->val < n->val) {
        if (n->left) {
            return insert_node(n->left, x);
        } else {
            n->left = x;
            return true;
        }
    }

    if (n->right) {
        return insert_node(n->right, x);
    }

    n->right = x;
    return true;
}

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
