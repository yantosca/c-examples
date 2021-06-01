#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} node_t;


void printlist(node_t *head) {
  // Prints nodes of a linked list 
  node_t *current;
  current = head;
  while (current != NULL) {
    printf("%d - ", current->value);
    current = current->next;
  }
  printf("\n");
}

node_t *create_node(int value) {
  // Creates 1 node of a linked list
  node_t *result = malloc(sizeof(node_t));
  result->value = value;
  result->next = NULL;
  return result; 
}

node_t *insert_at_front(node_t *node, node_t *head){
  // Inserts a node at the head of a linked list, and
  // then the node we just inserted becomes the new head
  node->next = head; 
  return node;
}

void insert_at_value(int value, node_t* node, node_t *head){
  // Inserts a node at the head of a linked list, and
  // then the node we just inserted becomes the new head
  node_t *current = head;
  while(current->value != value) {
    current = current->next;
  }
  node->next = current->next;  // The new node pts to the next node in list
  current->next = node;        // The new node becomes the current node
}

node_t *remove_at_value(int value, node_t *head){
  // Removes a node at the head of a linked list, and
  // then the node we just inserted becomes the new head
  node_t *current;

  // Guard clause in case the node to remove is the head
  if (head->value == value) {
    head = head->next;
    return head;
  }

  // Search for value starting from head
  current = head;
  while(current->next->value != value) {
    current = current->next;
  }
  current->next = current->next->next;
  return head;
}


int main(int argc, char **argv) {

  int i;
  node_t *head, *current;

  current = NULL;
  head = NULL;

  for (i = 0; i < 11; i++) {
    head = insert_at_front(create_node(i), head);
  }
  printlist(head);
  
  insert_at_value(7, create_node(100), head);
  printlist(head);

  head = remove_at_value(100, head);
  printlist(head);

  head = remove_at_value(4, head);
  printlist(head);

  head = remove_at_value(0, head);
  printlist(head);

  insert_at_value(10, create_node(200), head);
  printlist(head); 
  
  head = remove_at_value(10, head);
  printlist(head);
  
  return 0;
}
