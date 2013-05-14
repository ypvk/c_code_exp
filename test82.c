#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
char buff[MAX];
char* index_array[MAX];

int cmp(const void* a, const void* b)
{
  char* str1 = *((char**)a);
  char* str2 = *((char**)b);
  while(*str1 && *str2 && *str1 == *str2) {str1++; str2++;}
  return (*str1 - *str2);
}
int main(int argc, char** argv)
{
  char ch;
  int n = 0;
  memset(buff, 0, sizeof(buff));
  memset(index_array, 0, sizeof(index_array));
  while((ch=getchar()) != '\n')
  {
    index_array[n] = &buff[n];
    buff[n++] = ch; 
  }
  buff[n] = '\0';
  int i;
  printf("before sort\n");
  for(i = 0; i < n; i++)
  {
    printf("%s\n", index_array[i]);
  }
  qsort(index_array, n, sizeof(char*), cmp);
  printf("after sort\n");
  for(i = 0; i < n; i++)
  {
    printf("%s\n", index_array[i]);
  }
  return 0;
}
