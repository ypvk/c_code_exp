#include <cstdio>

//test multi point to multi array
int main(int argc, char** argv)
{
  int **p;
  p = new int* [2];
  int i;
  for(i = 0; i < 2; i++)
  {
    *(p + i) = new int[2];
  }
  p[1][0] = 3;
  p[1][1] = 2;
  printf("%d %d\n", p[1][0], p[1][1]);
  for(i = 0; i < 2; i++) delete[] *(p+i);
  delete[] p;
  return 0;

}
