#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxNum 1005
//brute-force
//O(mn)
/*
int strStr(char * haystack, char * needle)
{
  int hlen = strlen(haystack);
  int nlen = strlen(needle);

  int i = 0;
  int j = 0;

  while(i<hlen && j<nlen)
    {
      if(haystack[i] == needle[j])
        {
          //Match
          i++;
          j++;
        }
      else
        {
          //Not Match, withdraw
          i = i-j+1;
          j = 0;
        }
    }

  if (j == nlen)
    return i - j;
  else
    return -1;
}
*/

//KMP
//O(m+n)
 /*
int* getNext(char * pattern)
{
  int * next = (int*) malloc (strlen(pattern)*sizeof(int));
  next[0] = -1;
  int i = 0;
  int j = -1;

  while(i < strlen(pattern)-1)
    {
      if(j==-1||pattern[i]==pattern[j])
        {
          i++;
          j++;
          next[i] = j;
        }
      else
        {
          j = next[j];
        }
    }
  return next;
}

int strStr(char * haystack, char * needle)
{
int hlen = strlen(haystack);
int nlen = strlen(needle);
if(nlen == 0)
return 0;

int * next = getNext(needle);

int i = 0;
int j = 0;

while(i<hlen && j<nlen)
{
if(j==-1||haystack[i]==needle[j])
{
i++;
j++;
}
else
{
//除当前字符外的最长相同前缀后缀
j = next[j];
}
}
if(j==nlen)
return i - j;
else
return -1;
}

*/

//sunday
//只不过Sunday算法是从前往后匹配，在匹配失败时关注的是主串中参加匹配的最末位字符的下一位字符
//1. 只不过Sunday算法是从前往后匹配，在匹配失败时关注的是主串中参加匹配的最末位字符的下一位字符
//2. 否则，其移动位数 = 模式串长度 - 该字符最右出现的位置(以0开始) = 模式串中该字符最右出现的位置到尾部的距离 + 1。
int shift[maxNum];
int Sunday(const char* T, const char* P)
{
  int n = strlen(T);
  int m = strlen(P);

  for(int i = 0;i < 26;i++)
    {
      shift[i] = m + 1;
    }

  for(int i = 0;i < m;i++)
    {
      shift[P[i]] = m - i;
    }

  int s = 0;
  int j;
  while(s<=n-m)
    {
      j = 0;
      while(T[s+j] == P[j])
        {
          j++;
          if(j>=m)
            {
              return s;
            }
        }
      s += shift[T[s+m]];
    }
  return -1;
}

int strStr(char* haystack, char* needle)
{
  if(needle[0]=='\0')
    return 0;
  return Sunday(haystack,needle);
}

int main()
{
  char * haystack1 = "hello";
  char * needle1 = "ll";

  char * haystack2 = "aaaaa";
  char * needle2 = "bba";

  char * haystack3 = "aaa";
  char * needle3 = "aaaa";

  char * haystack4 = "mississippi";
  char * needle4 = "issip";

  char * haystack5 = "mississippi";
  char * needle5 = "a";

  int pos1 = strStr(haystack1, needle1);
  int pos2 = strStr(haystack2, needle2);
  int pos3 = strStr(haystack3, needle3);
  int pos4 = strStr(haystack4, needle4);
  int pos5 = strStr(haystack5, needle5);

  printf("pos1:%d, pos2:%d, pos3:%d, pos4:%d, pos5:%d\n", pos1, pos2, pos3, pos4, pos5);
  return 0;
}
