/*
 * queue.h
 *
 * A polymorphic queue data structure
 *
 */

#include "node.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue {
    unsigned size;
    Node *head;
    Node *tail;
} Queue;

extern Queue* Queue_new();
extern void Queue_add(Queue *q, void *el);
extern void* Queue_remove(Queue *q);
extern void* Queue_front(Queue *q);
extern unsigned Queue_size(Queue *q);
extern void Queue_delete(Queue *q);

#endif