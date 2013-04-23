#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
char buff[MAX];

typedef struct NODE {
  int freq;
  char ch;
  struct NODE* left;
  struct NODE* right;
}Node;

typedef struct HEAP {
  int size;
  int capasity;
  Node **top;
}Heap;

void initHeap(Heap* heap, int cap)
{
  heap->capasity = cap;
  heap->size = 0;
  int i;
  heap->top = (Node**)malloc(cap*sizeof(Node*));
}
void adjustHeap(Heap* heap)
{
  int i;
  for(i = heap->size - 1; i >= 1; i = (i-1)/2)
  {
    if((*(heap->top+i))->freq < (*(heap->top+(i-1)/2))->freq)
    {
      Node* tmp; 
      tmp = *(heap->top+i);
      *(heap->top+i) = *(heap->top+(i-1)/2);
      *(heap->top+(i-1)/2) = tmp;
    }
  }
}
void addItem(Heap* heap, Node* node)
{
  *(heap->top + heap->size) = node;
  heap->size++;
  adjustHeap(heap);
}
Node* getTop(Heap* heap)
{
  if(!heap->size) return NULL;
  Node* re = *(heap->top);
  *(heap->top) = *(heap->top + heap->size - 1);
  heap->size--;
  adjustHeap(heap);
  return re;
}

void freeHeap(Heap* heap)
{
  free(heap->top); 
}

void printCode(const Node* start, char* str, int len)
{
  if(start->left == NULL && start->right == NULL) 
  {
    str[len] = '\0';
    printf("%c->%s\n", start->ch, str); 
    return;
  }
  str[len] = '0';
  printCode(start->left, str, len+1);
  str[len] = '1';
  printCode(start->right, str, len+1);
}

void freeNode(Node* node)
{
  if(!node)return;
  freeNode(node->left);
  freeNode(node->right);
  free(node);
}

Heap* heap;
/*Huffman encoding*/
int main(int argc, char** argv)
{
  int n;
  while(scanf("%d", &n) == 1)
  {
    heap = (Heap*)malloc(sizeof(Heap));
    initHeap(heap, MAX);
    int i;
    for(i = 0; i < n; i++)
    {
      int freq;
      char ch[2];
      scanf("%s%d", &ch, &freq);
      Node* node = (Node*)malloc(sizeof(Node));
      node->left = NULL;
      node->right = NULL;
      node->ch = ch[0];
      node->freq = freq;
      addItem(heap, node);
    }
    while(heap->size >= 2) {
      Node* node1 = getTop(heap);
      Node* node2 = getTop(heap);
      Node* father = (Node*)malloc(sizeof(Node));
      father->left = node1;
      father->right = node2;
      father->freq = node1->freq + node2->freq;
      father->ch = '\0';
      addItem(heap, father);
    }
    Node* root = getTop(heap);
    freeHeap(heap);
    free(heap);
    printCode(root, buff, 0);
    freeNode(root);
  }
} 
