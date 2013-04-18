#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node *next;
} Node;

Node* findNode(int value, const Node* home)
{
  Node* p = home->next;
  while(p && p->value != value)p = p->next;
  return p;
}

int isEmpty(const Node* home)
{
  return (home->next == NULL);
}

void freeMemory(Node* home)
{
  Node* p, *q;
  p = home;
  while(p)
  {
    q = p;
    p = p->next;
    free(q);
  }
}

void insertNode(int value, Node* home)
{
  Node* p = home;
  while(p->next) p = p->next;
  Node* q = (Node*) malloc(sizeof(Node));
  q -> value = value;
  q -> next = NULL;
  p->next = q;
}
int deleteNode(int value, Node* home)
{
  Node* p, *q;
  p = home;
  while(p->next && p->next->value != value)p = p->next;
  if(p->next) {
    q = p;
    p = p->next;
    q->next = p->next;
    free(p);
    return 1;
  }
  return 0;
}

void printNode(const Node* home)
{
  Node* p = home->next;
  while(p)
  {
    printf("%d", p->value);
    p = p->next;
    if(p)printf("->");
  }
  printf("\n");
}
int main(int argc, char** argv)
{
  Node* home = (Node*)malloc(sizeof(Node));
  home->value = 0;
  home->next = NULL;
  int n;
  Node* p = NULL;
  Node* q = home;
  while(scanf("%d", &n) == 1)
  { 
    if(p)q = p;
    p = (Node*)malloc(sizeof(Node));
    p->value = n;
    p->next = NULL;
    q->next = p;
  }
  /*//print value*/
  /*q = home->next;*/
  /*while(q != NULL)*/
  /*{*/
    /*printf("%d", q->value);*/
    /*q = q->next;*/
    /*if(q)printf("->");*/
  /*}*/
  /*printf("\n");*/
  printNode(home);
  int v;
  scanf("%d", &v);
  Node* result = findNode(v, home);
  if(result)printf("find it \n");

  scanf("%d", &v);
  int re = deleteNode(v, home);
  if(re) printf("delet it \n");
  printNode(home);
  
  scanf("%d", &v);
  insertNode(v, home);
  printNode(home);
  //free all memory
  p = home;
  q = home;
  while(p != NULL)
  {
    q = p;
    p = p->next;
    free(q);
  }
  return 0;
}
