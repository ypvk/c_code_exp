#include <stdio.h>
int main(int argc, char* argv[])
{
  int a, b, c;
  int i, j;
  int s[9];
  int flag = 0;
  for(a = 100; a < 333; a++)
  {
    b = 2*a;
    c = 3*a;
    s[0] = a/100;
    s[1] = a%100/10;
    s[2] = a%10;
    s[3] = b/100;
    s[4] = b%100/10;
    s[5] = b%10;
    s[6] = c/100;
    s[7] = c%100/10;
    s[8] = c%10;
    flag = 0;
    for(i = 0; i < 8; i++)
    {
      if (flag) break;
      for(j = i + 1; j < 9; j++)
      {
        if(s[i] == s[j]){ flag = 1; break;}
      }
    }
    if (flag)continue;
    printf("%d %d %d\n", a, b, c);
  }
  return 0;
}
