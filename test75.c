#include <stdio.h>
#define MAX 100
char buff1[MAX];
char buff2[MAX];

int strcmp(const char* a, const char* b)
{
  while(*a && *b && *a == *b){a++; b++;}
  return *a - *b; 
}

int strlen(const char* a)
{
  int len = 0;
  while(*a++)len++;
  return len; 
}

void strcat(char* a, const char* b)
{
  while(*a)a++;
  while(*b)*a++ = *b++;
  *a = '\0';
}

void strcpy(char* a, const char* b)
{
  while(*b)*a++ = *b++;
  *a = '\0';
}

int main(int argc, char** argv)
{
  while(scanf("%s%s", buff1, buff2) == 2)
  {
    printf("%s\n", !strcmp(buff1, buff2) ? "Equal" : "No equal");
    printf("len: %d\n", strlen(buff1));
    strcat(buff1, buff2);
    printf("strcat: %s\n", buff1);
    strcpy(buff1, buff2);
    printf("strcpy: %s\n", buff1);
  }
  return 0;
}
