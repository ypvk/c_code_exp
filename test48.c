#include <stdio.h>

#define MAX 100
int a[MAX][MAX];
int d[MAX][MAX];
int pos[MAX][MAX];
const int LEFT = 0;
const int RIGHT = 1;

int bp_triangle(int n)
{
  int i;
  for(i = 0; i < n; i++) d[n-1][i] = a[n-1][i];
  int j;
  for(i = n-2; i >=0; i--)
  {
    for(j = 0; j <= i; j++)
    {
      int tmp = d[i+1][j] > d[i+1][j+1] ? d[i+1][j] : d[i+1][j+1];
      if (d[i+1][j] > d[i+1][j+1])pos[i][j] = LEFT;
      else pos[i][j] = RIGHT;
      d[i][j] = a[i][j] + tmp;
    }
  }
  return 0;
}

void print_path(int x, int y, int n)
{
  while(x < n-1)
  {
    if (pos[x][y] == LEFT)
    {
      printf("LEFT\n");
      x++;
    }
    else {
      printf("RIGHT\n");
      x++;
      y++;
    }
  }
}

int main(int argc, char** argv)
{

  int n;
  scanf("%d", &n);
  int i, j;
  for(i = 0; i < n; i++)
  {
    for(j = 0; j <= i; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }
  bp_triangle(n);
  printf("%d\n", d[0][0]);
  print_path(0, 0, n);
  return 0;
}
