#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bigrand();
int randint(int a, int b);
void getknuth(int, int);

int main(int argc, char** argv)
{
  srand(time(NULL));
  printf("time %d\n", time(NULL));
  printf("RAND_MAX = %d\n", RAND_MAX);
  printf("rand() = %d\n", rand());
  printf("bigrand() = %d\n", bigrand());
  printf("randint() = %d\n", randint(7, 10));
  getknuth(20, 200);
  return 0;
}

int bigrand()
{
  srand(time(NULL));
  return (rand() * RAND_MAX + rand());
}

int randint(int a, int b)
{
  if( a >= b) return -1;
  srand(time(NULL));
  int temp = rand() * RAND_MAX + rand();
  temp = temp % (b - a + 1) + a;
  return temp;
}
/* knuth method to get m ints in n */
void getknuth(int m, int n)
{
  int i;
  for(i = 0; i < n; i++)
  {
    if(bigrand() % (n - i) < m)
    {
      printf("%d ", i);
      m--;
    }
  }
  printf("\n");
  return;
}
