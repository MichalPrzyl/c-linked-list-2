// #include <cstdio>
#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
  struct Node *first;
};

struct Node {
  int value;
  struct Node *next;
};

void print_all_nodes_from_linked_list(struct LinkedList *list) {
  struct Node *current = list->first;

  while (current != NULL) {
    printf("%d\n", current->value);
    current = current->next;
  }
}

struct Node *get_last_element_from_list(struct LinkedList *list) {
  struct Node *current = list->first;
  struct Node *last = list->first;

  while (current != NULL) {
    if (current->next == NULL) {
      last = current;
    }
    current = current->next;
  }

  return last;
}

struct Node* add_element_to_end_of_the_list(int value, struct LinkedList *list) {
  struct Node *last_element = get_last_element_from_list(list);

  struct Node *p_new_node = (struct Node*)malloc(sizeof(struct Node));

  p_new_node->value = value;
  p_new_node->next = NULL;
  last_element->next = p_new_node;

  return p_new_node;
}

int main() {

  struct Node first_node;
  // first_node.value = 69;
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

  // printing list
  // print_all_nodes_from_linked_list(&linked_list);

  // getting last element
  struct Node *last_element = get_last_element_from_list(&linked_list);
  printf("last element value: %d\n", last_element->value);


  // Add new element
  struct Node *p_new_element_1 = add_element_to_end_of_the_list(666, &linked_list);
  struct Node *p_new_element_2 = add_element_to_end_of_the_list(667, &linked_list);
  struct Node *p_new_element_3 = add_element_to_end_of_the_list(668, &linked_list);


  struct Node *last_element_2 = get_last_element_from_list(&linked_list);
  // puts("check this out");
  printf("last element value: %d\n", last_element_2->value);

  free(p_new_element_1);
  free(p_new_element_2);
  free(p_new_element_3);

  return 0;
}
