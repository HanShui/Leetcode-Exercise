#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool isMatch(char* s, char* p){
  int ls = strlen(s);
  int lp = strlen(p);
  bool match[ls+1][lp+1];
  memset(match, false, sizeof(bool)*(ls+1)*(lp+1));
  match[ls][lp]=true;
  for(int i=ls;i>=0;--i)
    {
      for(int j=lp-1;j>=0;--j)
        {
          bool curmatch=(s[i]==p[j])||(p[j]=='.');
          if(p[j+1]=='*')
            {
              if(i==ls)
                match[i][j]=match[i][j+2];
              else
                match[i][j]=match[i][j+2]||(match[i+1][j]&&curmatch);
            }
          else
            {
              if(i==ls)
                match[i][j]=false;
              else
                match[i][j]=curmatch&&match[i+1][j+1];
            }
        }
    }
  return match[0][0];
}

int main()
{
  char* s_1 = "aa";
  char* p_1 = "a";
  bool res_1 = isMatch(s_1, p_1);

  char* s_2 = "aa";
  char* p_2 = "a*";
  bool res_2 = isMatch(s_2, p_2);

  char* s_3 = "ab";
  char* p_3 = ".*";
  bool res_3 = isMatch(s_3, p_3);

  char* s_4 = "aab";
  char* p_4 = "c*a*b";
  bool res_4 = isMatch(s_4, p_4);

  char* s_5 = "mississippi";
  char* p_5 = "mis*is*p*.";
  bool res_5 = isMatch(s_5, p_5);

  printf("result:\n,res_1:%d,res_2:%d,res_3:%d,res_4:%d,res_5:%d\n",res_1,res_2,res_3,res_4,res_5);

}
