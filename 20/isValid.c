#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool isValid(char *s )
{
  int len = strlen(s);
  int index = 0;
  if (len == 0)
    return true;

  char* tmp = (char *) malloc (sizeof(char) * len);
  char* p;

  for (p=s;*p != 0x00;p++)
    {
      switch(*p)
        {
        case '(':
        case '[':
        case '{':
          s[index] = *p;
          index++;
          break;
        case ')':
          if(index >= 1 && s[index-1] == '(')
            {
              index--;
              break;
            }
          else
            return false;
        case ']':
          if(index >= 1 && s[index-1] == '[')
            {
              index--;
              break;
            }
          else
            return false;
        case '}':
          if(index >= 1 && s[index-1] == '{')
            {
              index--;
              break;
            }
          else
            return false;
        default:
          continue;
        }
    }
  if (index == 0)
    return true;
  else
    return false;

}


int main()
{
  char s1[] = "()";
  char s2[] = "()[]{}";
  char s3[] = "(]";
  char s4[] = "([)]";
  char s5[] = "{[]}";

  printf("s1:%d,s2:%d,s3:%d,s4:%d,s5:%d\n", isValid(s1), isValid(s2), isValid(s3), isValid(s4), isValid(s5));
  return 0;
}
