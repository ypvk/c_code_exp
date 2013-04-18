#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct TNode {
  int v;
  int has_value;
  struct TNode* left, *right;
} Node;

Node* queue[MAX];
Node* root = NULL;
int falure;
int values[256];

Node* new_node()
{
  Node* n = (Node*)malloc(sizeof(Node));
  n->v = 0;
  n->has_value = 0;
  n->left = NULL;
  n->right = NULL;
}
/**
  *add new node by value and str 
  */
void add_node(int value, const char* str)
{
  int n;
  n = strlen(str);
  int i;
  Node* p = root;
  for(i = 0; i < n; i++)
  {
    if(str[i] == 'L')
    {
      if (p->left == NULL)
      {
        p->left = new_node();
        p = p->left;
      }
      else p = p->left;
    }
    else if(str[i] == 'R')
    {
      if(p->right == NULL)
      {
        p->right = new_node();
        p = p->right;
      }
      else p = p->right;
    }
  }
  if(p->has_value) {falure = 1; return;}
  p->v = value;
  p->has_value = 1; 
  return;
}

void free_tree(Node* node)
{
  if (node == NULL)
  {
    return;
  }
  free_tree(node->left);
  free_tree(node->right);
  free(node);
}

void get_output()
{
  if (falure || !root->has_value)
  {
    printf("%d\n", -1);
    return;
  }
  int front, end;
  front = 0;
  end = 0;
  queue[end++] = root;
  int i = 0;
  while(front < end)
  {
    if (!queue[front]->has_value && queue[front]->left != NULL && queue[front] != NULL)
    {
      printf("%d\n", -1);
      return;
    }
    values[i++] = queue[front]->v;
    if(queue[front]->left != NULL) queue[end++] = queue[front]->left;
    if(queue[front]->right != NULL) queue[end++] = queue[front]->right;
    front++;
  }
  int j;
  for(j = 0; j < i; j++)
  {
   printf("%d ", values[j]);
  }
  printf("\n");
  return;
} 

int main(int argc, char** argv)
{
  char s[100];
  falure = 0;
  root = new_node();
  while(scanf("%s", s) == 1)
  {
    if (strcmp(s, "()") == 0) {
      get_output(); 
      free_tree(root); 
      falure = 0;
      root = new_node();
      continue;
    }
    int value;
    sscanf(&s[1], "%d", &value);
    add_node(value, strchr(s, ',') + 1);
  }
  return 0;
}
