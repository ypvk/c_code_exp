#include <stdio.h>
#include <string.h>

#define MAX  1010
int buff[MAX];

void sort(int* num)
{
  int i, j;
  int temp;
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4 - i - 1; j++)
    {
     if (num[j] > num[j+1]){
      temp = num[j+1];
      num[j+1] = num[j];
      num[j] = temp;
     }
    }
  }
}

int main(int argc, char** argv)
{
  int num[4];
  int n;
  int i, j;
  int a, b, tmp;
  j = 0;
  memset(buff, 0, sizeof(buff));
  scanf("%d", &n);
  for(i = 0; i < 4; i++)
  {
    num[i] = n % 10;
    n = n / 10;
  }
  while(1) {
    sort(num);
    a = num[0] + num[1]*10 + num[2]*100 + num[3]*1000;
    b = num[3] + num[2]*10 + num[1]*100 + num[0]*1000;
    tmp = a - b;
    for(i = 0; i < j && buff[i] != tmp; i++);
    if (buff[i]){ printf("%d\n", tmp); break;}
    buff[j++] = tmp;
    printf("%d->", tmp);
    for(i = 0; i < 4; i++)
    {
      num[i] = tmp % 10;
      tmp = tmp / 10;
    }
  }
  return 0;
}
  
