#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
  char large_num[100];
  int m;
  scanf("%s%d", large_num, &m);
  int i;
  int ans = 0;
  for(i = 0; i < strlen(large_num); i++)
  {
    ans = (int)((long long)ans*10 + large_num[i]) % m;
  }
  printf("%d\n", ans);
  return 0;
}
