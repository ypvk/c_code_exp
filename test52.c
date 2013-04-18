#include <setjmp.h>
#include <stdio.h>
jmp_buf buf;

void banana()
{
  printf("in banana()\n");
  longjmp(buf, 1);
  printf("never see it\n");
}

int main(int argc, char** argv)
{
  if(setjmp(buf))
  {
    printf("back to main\n");
  }
  else
  {
    printf("in the main \n");
    banana();
  }
  return 0;
}
