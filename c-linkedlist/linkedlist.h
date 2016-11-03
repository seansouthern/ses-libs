#ifndef LINKEDLIST_INC
#define LINKEDLIST_INC

#ifndef NODE_INC
#include "node.h"
#endif

typedef struct  {
	Node * head;
	unsigned int size;
} LinkedList;


void list_insert_node(LinkedList * in_list, Node * node);
int list_delete_node(LinkedList * in_list, Node * node);
LinkedList * list_create( void );
void list_destroy( LinkedList * in_list, int(*t_destructor)(LinkedList*, Node*));
int traverse(LinkedList * in_list, int(*ptr_func)(LinkedList*, Node*));
Node * find_project_by_name(LinkedList * in_list, char * in_term);
Node * list_get_head(LinkedList * in_list);
Node * list_get_tail(LinkedList * in_list);
Node * list_create_node(void * in_data);

#include "linkedlist.c"

#endif // !def LINKEDLIST_INC
