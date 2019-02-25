#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lengthOfLongestSubstring(char* s)
{
  if(*s=='\0')
    return 0;
  else if(*(s+1)=='\0')
    return 1;

  char* p=s+1;
  char* target=s;
  for(target=s;*target!='\0';target++)
    {
      for(p=target+1;*p!='\0';p++)
        {
          if((*p) == (*target))
            {
              int l2 = lengthOfLongestSubstring(target+1);
              (*p) = '\0';
              int l1 = lengthOfLongestSubstring(s);
              return l1>l2 ? l1:l2; 
            }
        }
    }

  return strlen(s);
}


int main()
{
  char s[] = "cdd";
  int len = lengthOfLongestSubstring(s);
  /*int len = 0;*/
  printf("%d\n",len);
  return 0;
}
