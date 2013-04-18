#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* str = "`1234567890-=qwertyuiop[]\asdfghjkl;'zxcvbnm,./";

int main(int argc, char** argv)
{
  int ch;
  int n = strlen(str);
  int i;
  while((ch = getchar()) != EOF)
  {
    /*for (i = 0; i < n; i++)*/
    /*{*/
      /*if (str[i] == ch && i > 0)*/
      /*{*/
        /*putchar(str[i-1]);*/
        /*break;*/
      /*}*/
    /*}*/
    /*if ( i == n)putchar(ch);*/
    for (i = 0; str[i] && str[i] != ch; i++);
    if (str[i])putchar(str[i-1]);
    else putchar(ch);
  }
  return 0;
}
            
    
