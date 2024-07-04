#include <stdio.h>
#include "linked_list.h"

int main() {
  struct Node first_node;
  struct Node *p_first_node = &first_node;
  p_first_node->value = 69;

  struct Node second_node;
  second_node.value = 2;

  struct Node third_node;
  third_node.value = 102;

  first_node.next = &second_node;
  second_node.next = &third_node;
  third_node.next = NULL;

  struct LinkedList linked_list;
  linked_list.first = &first_node;

  // Print list
  print_all_nodes_from_linked_list(&linked_list);

  // Get last element
  struct Node *last_element = get_last_element_from_list(&linked_list);

  // Add new element
  add_element_to_end_of_the_list(666, &linked_list);

  // Print list again to verify the new element is added
  print_all_nodes_from_linked_list(&linked_list);


  return 0;
}

