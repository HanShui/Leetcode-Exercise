#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Manacher Algorithm*/

char* longestPalindrome(char* s) {
  int s_len = strlen(s);
  int tmp_len = 2*s_len+2;
  char* tmp = (char *) malloc (sizeof(char)*(tmp_len+1));
  /*deal with add or even*/
  tmp[0] = '$';
  tmp[1] = '#';
  for (int i = 0; i < s_len; i++)
    {
      tmp[2*i+2] = s[i];
      tmp[2*i+3] = '#';
    }
  tmp[2*s_len+2] = '\0';
  printf("strlen(tmp):%ld\n",strlen(tmp));

  int mx = 0;
  int id = 0;
  int resLen = 0;
  int resCenter = 0;
  int* p = (int *) malloc (sizeof(int)*tmp_len);
  for(int i = 0; i < tmp_len; i++)
    {
      p[i] = mx > i ? ((p[2*id-i]<= mx -i)? p[2*id-i]:mx-i) : 1;
      if( i + p[i] <= tmp_len && i - p[i] >=0 )
      {
          while (tmp[i + p[i]] == tmp[i - p[i]]) ++p[i];
      }
      if (mx < i + p[i])
        {
          mx = i + p[i];
          id = i;
        }

      if(resLen < p[i])
        {
          resLen = p[i];
          resCenter = i;
        }
    }
  printf("resLen:%d,resCenter:%d\n",resLen,resCenter);
  char* result = (char*) malloc (sizeof(char)*resLen);
  result[resLen-1] = '\0';
  strncpy(result,&s[(resCenter-resLen)/2],resLen-1);
  free(tmp);
  free(p);
  return result;
}

int main()
{
  char s[] = "babad";
  char* res = longestPalindrome(s);
  printf("%s\n", res);
  return 0;
}
