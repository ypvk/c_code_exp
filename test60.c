#include <stdio.h>

int count = 0;
int* orig;
int num;

void swap(int* a, int* b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void all_list(int* array, int n)
{
  int i;
  int tmp;
  int* s = array;
  if(n == 0)
  {
    count++;
    for(i = 0; i < num; i++)
    {
      printf("%d ", orig[i]);
    }
    printf("\n");
    return;
  }
    
  for(i = 0; i < n; i++)
  {
    tmp = s[i];
    s[i] = s[0];
    s[0] = tmp;
    all_list(s + 1, n-1);
    tmp = s[i];
    s[i] = s[0];
    s[0] = tmp;
  }
}

void get_list_for_index(int* array, int n, int index)
{
  int i;
  if (index == 5){
    count++;
    for(i = 0; i<index; i++)
    {
      printf("%d ", orig[i]);
    }
    printf("\n");
    return;
  }
  for(i = 0; i < n; i++)
  {
    int tmp = array[i];
    array[i] = array[0];
    array[0] = tmp;
    get_list_for_index(array+1, n - 1, index+1);
    tmp = array[i];
    array[i] = array[0];
    array[0] = tmp;
  }
  return;
}

int main(int argc, char** argv)
{
  int array[5] = {1, 2, 3, 4, 5};
  orig = array;
  num = 5;
  all_list(array, 5);
  printf("num: %d\n", count);
  count = 0;
  int array1[10] = {0,1,2,3,4,5,6,7,8,9};
  orig = array1;
  get_list_for_index(array1, 10, 0);
  printf("num: %d\n",count);
  return 0;
}
