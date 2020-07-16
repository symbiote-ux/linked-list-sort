#include "linkedList.h"

int main(void) {
  List_ptr list = create_list();
  add_to_list(list, 3);
  add_to_list(list, 1);
  add_to_list(list, 2);
  selection_sort(list);
  bubble_sort(list);
  insertion_sort(list);
  display(list);
  return 0;
};