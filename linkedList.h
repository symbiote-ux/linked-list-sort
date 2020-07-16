#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  Failure,
  Success
} Status;

typedef struct node {
  int value;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct {
  Node *head;
  Node *last;
  int count;
} List;
	
typedef List *List_ptr;

Node_ptr create_node(int value);
List_ptr create_list(void);
void display(List_ptr);

Status add_to_list(List_ptr,int);
Node_ptr get_position(List_ptr, int);
void update_linked_list(Node_ptr,Node_ptr,List_ptr,int);
Status add_to_list( List_ptr list, int value); 
Status insert_at(List_ptr, int value, int position);

void swap(Node_ptr current, Node_ptr next);
void arrange(List_ptr src, int to, int from);
void selection_sort(List_ptr);
void bubble_sort(List_ptr src );
void insertion_sort(List_ptr src );
#endif