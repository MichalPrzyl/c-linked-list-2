#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
  int value;
  struct Node *next;
};

struct LinkedList {
  struct Node *first;
};

// Funkcje deklaracje
void print_all_nodes_from_linked_list(struct LinkedList *list);
struct Node* get_last_element_from_list(struct LinkedList *list);
int add_element_to_end_of_the_list(int value, struct LinkedList *list);
void free_list(struct LinkedList *list);

#endif // LINKED_LIST_H

