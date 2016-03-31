/*****************************************************************************
 **
 ** dictionary.h
 ** 
 ** Structure and interface definitions for Dictionary, a string-based
 ** key-value store
 **
 ** Utilizes a basic hash table implementation to provide constant time O(1)
 ** lookup and assignment
 ** 
 ** Author: Sean Butze
 **
 ****************************************************************************/


#include "node.h"

#ifndef DICTIONARY_H
#define DICTIONARY_H

#define DICT_SIZE 501 

typedef struct Entry {
    char *key;
    char *value;
    struct Entry *next;
} Entry;

typedef struct Dictionary {
    unsigned size;
    Entry *table[DICT_SIZE];
} Dictionary;

extern Dictionary* Dictionary_new();
extern char* Dictionary_get(Dictionary *d, char *key);
extern void Dictionary_put(Dictionary *d, char *key, char *value);
extern void Dictionary_delete(Dictionary *s);

#endif