#include <stdio.h>

int main(int argc, char** argv)
{
  double a, c, x, y;
  int i, b, f;
  scanf("%lf%d%lf", &a, &b, &c);
  x = 0;
  y = 100.0;
  f = a;
  double m;
  while(y - x > 1e-5)
  {
    m = x + (y-x)/2;
    f = a;
    for(i = 0; i < b; i++) f = f + f*m/100 - c;
    if (f == 0) break;
    if ( f > 0) y = m;
    else x = m;
  }
  printf("%.3lf", m);
  return 0;
}
