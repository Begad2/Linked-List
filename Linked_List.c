#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_types.h"

typedef struct Node_type Node;
typedef struct Linked_list list;
//? Struct initialization
struct Node_type
{
  u16 value;
  Node *next;
};
struct Linked_list
{
  Node *head;
  Node *tail;
};
//?initialize the list
list *init()
{
  list *l = (list *)malloc(sizeof(list));
  l->head = NULL;
  l->tail = NULL;
  return l;
}
//? check if the list is empty
u8 isEmpty(list *l)
{
  u8 i;
  if (l->head == NULL && l->tail == NULL)
  {
    i = 1;
  }
  else
  {
    i = 0;
  }
  return i;
}
//? create a new node
Node *newNode(u16 val)
{
  Node *temp = (Node *)malloc(sizeof(Node));
  if (temp != NULL)
  {
    temp->value = val;
    temp->next = NULL;
  }
  return temp;
}
//? insert a new node at the end of the list
void insertEnd(list *li, u16 val)
{
  Node *n = newNode(val);
  if (isEmpty(li))
  {
    li->tail = li->head = n;
  }
  else
  {
    Node *temp = li->tail;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = n;
    li->head = n;
  }
}
//? print the nodes in the list
void printNodes(list *li)
{
  Node *temp = li->tail;
  while (temp != NULL)
  {
    printf("Node value %d\n", temp->value);
    temp = temp->next;
  }
}
//? count the nodes in the list
u32 countNodes(list *li)
{
  u32 count = 0;
  Node *temp = li->tail;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  return count;
}
//? insert a node after a given node
void insertAfter(list *li, u16 val, u16 pos)
{
  Node *n = newNode(val);
  Node *temp = li->tail;
  while (temp != NULL)
  {
    if (temp->value == pos)
    {
      n->next = temp->next;
      temp->next = n;
      break;
    }
    else
    {
      temp = temp->next;
    }
  }
}
//? insert a node before a given node
void insertBefore(list *li, u16 val, u32 pos)
{
  Node *n = newNode(val);
  Node *temp = li->tail;
  while (temp != NULL)
  {
    if (temp->next->value == pos)
    {
      n->next = temp->next;
      temp->next = n;
      break;
    }
    else
    {
      temp = temp->next;
    }
  }
}
//? search for a node
Node *search(list *li, u16 val)
{
  Node *ret = NULL;
  Node *temp = li->tail;
  while (temp != NULL)
  {
    if (temp->value == val)
    {
      ret = temp;
      break;
    }
    else
    {
      temp = temp->next;
    }
  }
  return ret;
}
//? delete a node
void delete (list *li, u16 val)
{
  Node *n;
  Node *temp = li->tail;
  while (temp != NULL)
  {
    if (temp->next->value == val)
    {
      n = temp->next;
      temp->next = n->next;
      free(n);
      break;
    }
    else
    {
      temp = temp->next;
    }
  }
}
//? Deallocate a node
void destroy(Node *n)
{
  free(n);
}
