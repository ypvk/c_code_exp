#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 29989
#define MULT 31

typedef struct node
{
  int count;
  char *str;
  struct node *next;
}node;

node* bin[NUM];

int hash(char* str);
int incword(char* str);
void free_nodes();

int main(int argc, char** argv)
{
  memset(bin, 0, sizeof(bin));
  char buff[100];
  while(scanf("%s", buff) == 1)
  {
    incword(buff);
  }
  //print ans
  int i;
  for(i = 0; i < NUM; i++)
  {
    if(bin[i])
    {
      node* p = bin[i];
      while(p)
      {
        printf("%s:%d\n", p->str, p->count);
        p = p->next;
      }
    }
  }
  free_nodes();
  return 0;
}

int hash(char* str)
{
  int len = strlen(str);
  int i;
  int hashcode = 0;
  for(i = 0; i < len; i++)
  {
    hashcode = hashcode * MULT + str[i];
  }
  return hashcode % NUM;
}

int incword(char* str)
{
  int hashcode = hash(str);
  node* p = bin[hashcode];
  while(p)
  {
    if(!strcmp(p->str, str))
    {
      p->count++;
      return;
    }
    p = p->next;
  }
  p = (node*)malloc(sizeof(node));
  p->count = 1;
  p->str = (char*)malloc(strlen(str) + 1);
  strcpy(p->str, str);
  p->next = NULL;
  bin[hashcode] = p;
  return;
}

void free_nodes()
{
  int i;
  for(i = 0; i < NUM; i++)
  {
    if(bin[i])
    {
      node* p = bin[i];
      node* q;
      while(p)
      {
        q = p;
        p = p->next;
        free(q->str);
        free(q);
      }
    }
  }
}
