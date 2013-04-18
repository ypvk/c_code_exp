#include <stdio.h>
#include <string.h>
#define MAX 20
int s[1<<MAX];

int main(int argc, char** argv)
{
  int D, I;
  int i, k;
  while(scanf("%d%d", &D, &I) == 2)
  {
    /*memset(s, 0, sizeof(s));*/
    /*i = 0;*/
    /*while(i < I)*/
    /*{*/
      /*for (k = 1; k < 1 << D;)*/
      /*{*/
        /*s[k] = !s[k];*/
        /*if(s[k]) k = 2*k;*/
        /*else k = 2*k+1;*/
      /*}*/
      /*i++;*/
    /*}*/
    /*printf("%d\n", k/2);*/
    k = 1;
    for (i = 0; i < D - 1; i++)
    {
      if (I%2) {k = 2*k; I = I/2 + 1;}
      else {k = 2*k + 1; I = I/2;}
    }
    printf("%d\n", k);
  }
  return 0;
}
