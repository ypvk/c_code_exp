#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
  int freq;
  char ch;
  struct NODE* left;
  struct NODE* right;
}Node;

#define MAX 100
Node *nodes[MAX];
Node *root;
Node *tmp[MAX];

int main(int argc, char** argv)
{
  int n;
  while(scanf("%d", %n) == 1)
  {
    for(i = 0; i < n; i++)
    {
      int freq;
      char ch;
      scanf("%c%d", &ch, &freq);
      Node* node = (Node*)malloc(sizeof(Node));
      node->left = NULL;
      node->right = NULL;
      node->ch = ch;
      node->freq = freq;
      nodes[i] = node;
    }
    Node *min = nodes[0];
    Node *second = Nodes[1];
    for(i = 0; i < n; i++)
    { 
      if(nodes[i]->freq < min->freq)
      {
        second = min;
        min = node[i];
      }
      else if(nodes[i]->freq < second->freq)
      {
        second = nodes[i];
      }
    }
    Node *father = (Node*)malloc(sizeof(Node));
    father->freq = min->freq + second->freq;
    father->left = min;
    father->right = second; 
    for(i = 0; i <
  }
} 
