#include <stdio.h>
#include <string.h>

#define MAX 100
char buff[MAX];
/* try usefull function in string.h and stdio.h */
int main(int argc, char** argv)
{
  //strcpy
  strcpy(buff, "abcdefggg");
  printf("strcpy :%s\n", buff);
  //strncpy
  strncpy(buff, "abcdef", 3);
  printf("strncpy: %s\n", buff);
  //strcat
  strcpy(buff, "abc ");
  strcat(buff, "efg");
  printf("%s\n", buff);
 //strncat
  strcpy(buff, "abc ");
  strncat(buff, "efg", 2);
  printf("%s\n", buff);
  //strchr
  char* str_tmp = strchr(buff, 'e');
  if(str_tmp) printf("%s\n", str_tmp); 
  //strncmp
  strcpy(buff, "abcef");
  int result = strncmp(buff, "abcd", 3);
  printf("%s\n", !result ? "Yes" : "No");
 // sprintf
  sprintf(buff, "test : %d\n", 10);
  printf(buff);
  //sscanf
  int year, month, day;
  strcpy(buff, "time 2013-4-28");
  sscanf(buff, "%d-%d-%d", &year, &month, &day);
  printf("%d:%d:%d", year, month, day);
  return 0;
}
