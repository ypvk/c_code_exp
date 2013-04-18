#include <stdio.h>
#include <string.h>
#define MAX 100
char buff[MAX];

int main(int argc, char** argv)
{
  scanf("%s", buff);
  int n = strlen(buff);
  int i, j;
  /*int flag;*/
  for(i = 1; i < n; i++)
  {
    /*flag = 1;*/
    if (n % i == 0)
    {
      /*for (j = 0; j < n; j ++)*/
      /*{*/
        /*if (buff[j] != buff[j % i])*/
        /*{*/
          /*flag = 0;*/
          /*break;*/
        /*}*/
      /*}*/
      for (j = 0; j < n && buff[j] == buff[j % i]; j++);
      if(!buff[j]) {printf("%d", i); return 0;}
    }
  }
  if ( i == n) printf("Null");
  return 0;
}

