#ifndef LINKEDLIST_INC
#include "linkedlist.h"
#endif


int list_print_node(LinkedList * list, Node * node)
{
	printf("%p == node->prev\n ", node->prev);
	printf("%p == node\n", node);
	printf("%p == node->next\n", node->next);
	
	return 0;
}

void list_insert_node(LinkedList * list, Node * node)
{
        node->next = list->head;
	if(list->head != NULL){
		list->head->prev = node;
	}
	list->head = node;
	node->prev = NULL;
}

Node * list_create_node(void * in_data)
{
	Node * ptr_node = calloc(1, sizeof(Node));
	if (ptr_node == NULL) {
		printf("calloc failed for Node object\n");
		return((Node*)-1);
	}

        //The pointer argument should already have its memory allocated
	ptr_node->data = in_data;
	ptr_node->prev = NULL;
	ptr_node->next = NULL;
	return ptr_node;
}



int list_delete_node(LinkedList * list, Node * node)
{
	if(node->prev != NULL){
		node->prev->next = node->next;
	}else{
		list->head = node->next;
	}
	if(node->next != NULL){
		node->next->prev = node->prev;
	}
	free(node);
	
	return 0;
}

LinkedList * list_create()
{
	//Allocated memory and initializes list
	LinkedList * ptr_list = calloc(1, sizeof(LinkedList));
	if (NULL == ptr_list) {
		printf("calloc failed for LinkedList object\n");
		return((LinkedList *)-1);
	}
	ptr_list->head = NULL;
	return ptr_list;
}

void list_destroy(LinkedList * in_list, int (*t_destructor)(LinkedList * in_list, Node * in_node))
{
	// Deallocate user data from each node
	traverse(in_list, t_destructor);
	// Deallocate the Node structs themselves
        traverse(in_list, list_delete_node);
	// Deallocate the topmost list struct
	free(in_list);
}


int traverse(LinkedList * in_list, int (*ptr_func)(LinkedList * l, Node * n))
{
	Node * x = list_get_head(in_list);
	while(x != NULL){
		Node * tmp = x->next;
		ptr_func(in_list, x);
		x = tmp;
	}
	return 0;
}

Node * list_get_head(LinkedList * in_list)
{
	return in_list->head;
}

