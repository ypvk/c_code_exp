#include <stdio.h>
#include <string.h>

#define MAX 100
char str1[MAX];
char str2[MAX];

int dp[MAX][MAX];
char dir[MAX][MAX];//0 up, 1, left, 2, left and up

#define max(a, b) (a>b ? a:b)

int lcsl(int len1, int len2)
{
  memset(dp, 0, sizeof(dp));
  memset(dir, 0, sizeof(dp));
  int i, j;
  for(i = 1; i <= len1; i++)
  {
    for(j = 1; j <= len2; j++)
    {
      if(str1[i-1] == str2[j-1])
      {
        dp[i][j] = dp[i-1][j-1] + 1;
        dir[i][j] = 2;
      }
      else
      {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        if(dp[i-1][j] > dp[i][j-1])
        {
          dir[i][j] = 0;
        }
        else {
          dir[i][j] = 1;
        }
      }
    }
  }
  return dp[len1][len2];
}

void printcs(int len1, int len2)
{ 
  if(len1 == 0 || len2 == 0)return;
  if(dir[len1][len2] == 2)
  {
      printcs(len1-1, len2-1);
      printf("%c", str1[len1-1]);
  } 
  else {
    if(dir[len1][len2] == 0)
    {
      printcs(len1-1, len2);
    }
    else {
      printcs(len1, len2-1);
    }
  }
}
int main(int argc, char** argv)
{
  while(scanf("%s%s", str1, str2)==2)
  {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int ans = lcsl(len1,len2);
    printf("%d\n", ans);
    printcs(len1, len2);
    printf("\n");
  }
  return 0;
}
