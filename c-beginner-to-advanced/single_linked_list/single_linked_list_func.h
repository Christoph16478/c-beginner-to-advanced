// List:
// Node: A
// Node: B
// Node: C
// A -> B -> C
// Head (Anfang): A
// Tail (Ende): C
// len: 3

#ifndef SingleLinkedList_H
#define SingleLinkedList_H

typedef struct single_node
{
    struct single_node* next;
    void* val;
} single_node_t;

typedef struct single_list
{
    struct single_node* head;
    struct single_node* tail;
    unsigned int len;
} single_list_t;

inline single_list_t* list_new();
inline single_node_t* node_new(void* val);

inline single_node_t* find_prev_node(single_list_t* list, single_node_t* node);
inline void list_rpush(single_list_t* list, single_node_t* node);
inline void list_rpop(single_list_t* list);
inline single_node_t* list_find(single_list_t* list, void* val);
inline single_node_t* list_at(single_list_t* list, int index);

inline void list_empty(single_list_t* list);
inline void list_remove(single_list_t* list, single_node_t* node);
inline void list_print(single_list_t* list);

#endif
