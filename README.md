# C Data Structures

*Author: Sean Butze (github.com/bootsz)*

A library of standard data structure implementations for C.  Most implementations are polymorphic, supporting the use of any data type through the use of void pointers.  Thus memory allocation/management of the internal data is left as the responsibility of the client.

#### bst.h

Implements a binary search tree, which consists of nodes indexed by integer values which can hold arbitrary data (represented as void pointers).
Insertion and lookup run in the standard O(logn) time.

#### dictionary.h

A Dictionary data structure for storing string-based key-value mappings.  Uses a basic hash table implementation to provide O(1) constant lookup and assignment. 

#### queue.h

A polymorphic FIFO queue structure with constant O(1) add, remove, and front operations.  Implemented as a linked list.

#### stack.h

A polymorphic LIFO stack structure with constant O(1) push, pop, and peek operations.  Implemented as a linked list.

