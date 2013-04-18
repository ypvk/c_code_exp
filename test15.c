#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int array[MAX][MAX] = {0};

void func(int n)
{
  int i, j, k;
  k = 1;
  i = 0;
  j = n - 1;
  array[i][j] = 1;
  while(k < n*n) {
    while(i+1<n && !array[i+1][j]){array[i+1][j]=++k; ++i;}
    while(j >= 1 && !array[i][j-1]){array[i][j-1]=++k; --j;}
    while(i >= 1 && !array[i-1][j]){array[i-1][j]=++k; --i;}
    while(j+1 <n && !array[i][j+1]){array[i][j+1] = ++k; ++j;}
  }
  for (i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      printf("%d\t", array[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char** argv)
{
  int n;
  /*int i, j, k;*/
  /*int array[10][10] = {0};*/
  scanf("%d", &n);
  func(n);
  /*k = 1;*/
  /*i = 0;*/
  /*j = n - 1;*/
  /*array[i][j] = 1;*/
  /*while(k < n*n) {*/
    /*while(i+1<n && !array[i+1][j]){array[i+1][j]=++k; ++i;}*/
    /*while(j >= 1 && !array[i][j-1]){array[i][j-1]=++k; --j;}*/
    /*while(i >= 1 && !array[i-1][j]){array[i-1][j]=++k; --i;}*/
    /*while(j+1 <n && !array[i][j+1]){array[i][j+1] = ++k; ++j;}*/
  /*}*/
  /*for (i = 0; i < n; i++)*/
  /*{*/
    /*for(j = 0; j < n; j++)*/
    /*{*/
      /*printf("%d\t", array[i][j]);*/
    /*}*/
    /*printf("\n");*/
  /*}*/
  return 0;
}
