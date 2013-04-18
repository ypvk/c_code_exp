#include <stdio.h>
#include <sys/time.h>
int main()
{
  /*float f;*/
  /*char* string*/
  /*scanf("%f", &f);*/
  /*printf("%f", f);*/

  struct timeval tv;
  struct timezone tz;
  gettimeofday(&tv, &tz);
  printf("%f", tv.tv_sec);
  return 0;
}
