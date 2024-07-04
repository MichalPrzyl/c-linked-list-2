#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void print_all_nodes_from_linked_list(struct LinkedList *list) {
  struct Node *current = list->first;

  puts("printing...");
  while (current != NULL) {
    printf("%d\n", current->value);
    current = current->next;
  }
}

struct Node* get_last_element_from_list(struct LinkedList *list) {
  struct Node *current = list->first;

  if (current == NULL) {
    return NULL;
  }

  while (current->next != NULL) {
    current = current->next;
  }

  return current;
}

int add_element_to_end_of_the_list(int value, struct LinkedList *list) {
  struct Node *last_element = get_last_element_from_list(list);

  struct Node *p_new_node = (struct Node *)malloc(sizeof(struct Node));
  if (p_new_node == NULL) {
    printf("Memory allocation failed\n");
    return -1;
  }

  p_new_node->value = value;
  p_new_node->next = NULL;

  if (last_element != NULL) {
    last_element->next = p_new_node;
  } else {
    list->first = p_new_node;
  }

  return 0;
}

void free_list(struct LinkedList *list) {
  struct Node *current = list->first;
  struct Node *next_node;

  while (current != NULL) {
    next_node = current->next;
    free(current);
    current = next_node;
  }
  list->first = NULL;
}

