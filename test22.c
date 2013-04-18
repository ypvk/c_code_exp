#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char word[2000][10], sorted[2000][10];

int cmp_string(const void* a, const void* b)
{
  return strcmp((char*)a, (char*)b);
}
int cmp_char(const void* a, const void* b)
{
  return (*(char*)a - *(char*)b);
}
int main(int argc, char** argv)
{
  int n = 0;
  int i;
  int found;
  while(scanf("%s", word[n]) != EOF)
  {
    if (word[n][0] == '*') break;
    n++;
  } 
  qsort(word, n, sizeof(word[0]), cmp_string);
  for(i = 0; i < n; i++)
  {
    strcpy(sorted[i], word[i]);
    qsort(sorted[i], strlen(sorted[i]), sizeof(char), cmp_char);
  }
  char s[10];
  while(scanf("%s", s) != EOF)
  {
    qsort(s, strlen(s), sizeof(char), cmp_char);
    found = 0;
    for (i = 0; i < n; i++)
    {
     if(strcmp(s, sorted[i]) == 0)
     {
      printf("%s ", word[i]);
      found = 1;
     }
    }
    if (!found)printf(":(");
    printf("\n");
  }
 return 0;
} 
