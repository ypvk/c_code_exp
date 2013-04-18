#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 5000+10
char buff[MAX], s[MAX]; 
int p[MAX];
int main(int argc, char* argv[])
{
  int i, j, k, n, m;
  int max = 0;
  int x, y;
  m = 0;
  fgets(buff, MAX, stdin);
  n = strlen(buff);
  for(i = 0; i < n; i ++)
  {
   if(isalpha(buff[i])) {
    p[m] = i;
    s[m++] = toupper(buff[i]);
   }
  }
 for(i=0; i<m; i++)
 {
  for(j=0; j <= i && i + j < m; j++) {
    if (s[i - j] != s[i + j]) break;
  }
  --j;
  if (2 * j + 1 > max) {
    max = 2*j + 1;
    x = p[i-j];
    y = p[i+j];
  }
  for (j=0; j<=i && i+j+1 < m; j++) {
    if(s[i-j] != s[i+j+1])break;
  }
  --j;
  if(2*j+2 > max) {
    max = 2*j+2;
    x = p[i-j];
    y = p[i+j+1];
  }
 }
 for(i=x; i<=y; i++) {
   printf("%c", buff[i]);
 }
 printf("\n");
 return 0;
}
