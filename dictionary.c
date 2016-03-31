/*****************************************************************************
 **
 ** dictionary.c
 ** 
 ** Function implementations for Dictionary, a string-based key-value store
 **
 ** Utilizes a basic hash table implementation to provide constant time O(1)
 ** lookup and assignment
 **
 ** Author: Sean Butze
 **
 ****************************************************************************/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"

/**********************************************************
 * Private Helper Functions
 *********************************************************/

/*
 * Hash function for hashing a string to an integer value
 *
 * Modified version of the djb2 hash function by Dan Bernstein
 * (http://www.cse.yorku.ca/~oz/hash.html)
 *
 * Limits the range of output to between (0, DICT_SIZE)
 */
unsigned hash_string(unsigned char *str) {
    unsigned hash = 5381;
    int c;
 
    while ((c = (*str++)))
        hash = ((hash << 5) + hash) + c;
 
    return hash % DICT_SIZE;
}

/*
 * Delete all entries in an Entry list starting at 'head'
 */
void delete_entries(Entry *head) {
    Entry *i1, *i2;
    for (i1 = headvalgri; i1; i1 = i2) {
        i2 = i1->next;
        free(i1);
    }
}

/*
 * Create and return a new Entry object
 */
Entry* Entry_create(char *key, char *value) {
    Entry *e = malloc(sizeof(Entry));
    e->key = key;
    e->value = value;
    e->next = NULL;
    return e;    
}

/**********************************************************
 * Public Interface
 *********************************************************/

/*
 * Create and return a new Dictionary object
 */
Dictionary* Dictionary_new() {
    Dictionary *d = malloc(sizeof(Dictionary));
    for (int i = 0; i < DICT_SIZE; i++)
        d->table[i] = NULL;
    return d;
}

/*
 * Bind value to a given key in the dictionary
 *
 * If the specified key already exists, the existing bound
 * value is replaced with the new value
 */
void Dictionary_put(Dictionary *d, char *key, char *value) {
    assert(d);
    unsigned hash = hash_string((unsigned char *) key);

    if (! d->table[hash]) {
        d->table[hash] = Entry_create(key, value);
        return;
    } 

    for (Entry *i = d->table[hash]; i; i = i->next) {
        if (strcmp(key, i->key) == 0) {
            i->value = value;
            return;
        }
        if (i->next == NULL) {
            i->next = Entry_create(key, value);
            return;
        }        
    }

}

/*
 * Get and return the string value stored at
 * a given key
 *
 * Returns NULL if key is not found
 */
char* Dictionary_get(Dictionary *d, char *key) {
    assert(d);
    unsigned hash = hash_string((unsigned char *) key);
    for (Entry *i = d->table[hash]; i; i = i->next) {
        if (strcmp(key, i->key) == 0) 
            return i->value;
    }
    return NULL;
}

/*
 * Delete a Dictionary object, freeing all memory
 * associated with it
 */ 
void Dictionary_delete(Dictionary *d) {
    assert(d);
    Node *i1, *i2;

    for (int i=0; i<DICT_SIZE; i++) {
        if (d->table[i]) {
            delete_entries(d->table[i]);
        }
    }

    free(d);
}