#include <stdio.h>
#include <string.h>

typedef int State[9];

int main()
{
  State st[10];
  /*int a;*/
  /*a = 10;*/
  /*int &b = a;*/

  State &a = st[2];
  int i;
  for(i = 0; i<9; i++)
  {
    st[0][i] = i;
  }
  State &b = st[0];
  memcpy(&a, &b, sizeof(a));
  for(i = 0; i<9; i++)
    printf("%d ", a[i]);
  printf("\n");
  
  /*printf("%d\n", b);*/
  /*printf("%s", st[2] == &a ? "yes" : "No");*/
  printf("%d\n", 012);
  return 0;
}
