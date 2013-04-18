#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
  return (*(int*)a - *(int*)b);
}

int main(int argc, char** argv)
{
  int a[] = {3,1,5,7,2};
  qsort(a, 5, sizeof(int), cmp);
  int i;
  for(i = 0; i < 5; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
