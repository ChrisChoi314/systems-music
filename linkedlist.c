#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"


void print_list(struct node * n) {
  struct node *point = n;
  printf("[");
  while (point != NULL) {
    printf("%d", point->num);
    if (point->next != NULL) {
      printf(" ");
    }
    point = point->next;
  }
  printf("]\n");
}

struct node * insert_front(struct node * n, int i) {
  struct node *n1 = malloc(sizeof(2)+ sizeof(n1));
  n1->num = i;
  n1->next = n;
  return n1;
}

struct node * free_list(struct node * n) {
  struct node *output = n;
  struct node *point = n;
  while (point != NULL) {
    output = point->next;
    free(point);
    point = output;
  }
  return point;
}

struct node * remove_num(struct node *front, int data) {
  if (front->num == data) {
    struct node *pointer = front->next;
    free(front);
    return pointer;
  }
  if (front->next == NULL) {
    return front;
  }
  struct node *point = front;
  while (point->next != NULL) {
    if (point->next->num == data) {
      struct node *pointer = point->next;
      point->next = point->next->next;
      free(pointer);
      return front;
    }
    point = point->next;
  }
  return front;
}