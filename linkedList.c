#include "linkedList.h"

void swap(Node_ptr current, Node_ptr next) {
  int temp = current->value;
  current->value = next->value;
  next->value = temp;
};

void arrange(List_ptr src, int to, int from) {
  Node_ptr p_walk = src->head;
  for(size_t i = 0; i < from; i++)
   p_walk = p_walk->next;
  for(size_t j = from; j < to; j++)
   swap(p_walk,p_walk->next);
};

void insertion_sort(List_ptr src) {
  Node_ptr initial_p_walk = src->head,p_walk;
  for(size_t i = 0; i < src->count; i++) {
    p_walk = src->head;
    for(size_t j = 0; j <= i; j++) {
      if(p_walk->value > initial_p_walk->value) {
        arrange(src,i,j);
        break;
      }
      p_walk = p_walk->next;
    }
    initial_p_walk = initial_p_walk->next;
  }
};

void bubble_sort(List_ptr src){
  Node_ptr p_walk = src->head, next_p_walk = p_walk->next;
  for(size_t i = 0; i < src->count; i++) {
    while(next_p_walk != NULL) {
      if(p_walk->value > next_p_walk->value) swap(p_walk,next_p_walk);
      p_walk = next_p_walk;
      next_p_walk = next_p_walk->next;
    }
  }
};

void selection_sort(List_ptr src ) {
  Node_ptr min_p_walk = src->head,p_walk;
  for(size_t i = 0; i < src->count; i++) {
    p_walk = min_p_walk;
    while(p_walk != NULL) {
      if(min_p_walk->value > p_walk->value) swap(min_p_walk,p_walk);
      p_walk = p_walk->next;
    }
    min_p_walk = min_p_walk->next;
  }
};

Status add_to_list( List_ptr list, int value) {
  return insert_at(list, value, list->count);
};

void update_linked_list(Node_ptr p_walk,Node_ptr node,List_ptr list,int position) {
  Node_ptr next_pos = p_walk->next;
  p_walk->next = node;
  node->next = next_pos;
  list->count++;
  if(list->count == position + 1) list->last = node;
};

Node_ptr get_position(List_ptr list, int position) {
  Node_ptr p_walk = list->head;
  int curr_pos = 1;
  while(curr_pos != position) {
    p_walk = p_walk->next;
    curr_pos++;
  }
  return p_walk;
};

Status insert_at(List_ptr list, int value, int position) {
  if(position > list->count || position < 0) return Failure;
  Node_ptr new_node = create_node(value);
  if(list->head == NULL) {
    list->head = new_node;
    list->last = new_node;
    list->count++;
    return Success;
  }
  if(position == 0) {
    Node_ptr prev_head = list->head;
    list->head = new_node;
    new_node->next = prev_head;
    list->count++;
    return Success;
  }      
    Node_ptr p_walk = get_position(list,position);
    update_linked_list(p_walk,new_node,list,position);
    return Success;
};

void display(List_ptr list) {
  Node_ptr p_walk = list->head;
  while(p_walk != NULL) {
    printf("%d \n",p_walk->value);
    p_walk = p_walk->next;
  }
};

Node_ptr create_node(int value) {
  Node_ptr node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node; 
};

List_ptr create_list() {
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
};