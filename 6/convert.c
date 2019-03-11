
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/* nowRows0 nowRows0+numRows ... nowRows0+t*numRows */
/* nowRows1 2*numRows-nowRows1 2*numRows+nowRows1 ... 2*numRows+(-1)^t*nowRows1 */
/* nowRows2 2*numRows-nowRows2 ... ....*/
/* nowRows_n-1 nowRows_n-1+numRows*/


char* convert(char* s, int numRows) {
  int T = 2*numRows - 2;
  int slen = strlen(s);
  int t = 0;

  char* result = (char*) malloc (sizeof(char) * (slen+1));

  if(T == 0) return s;

  for(int i = 0; i < numRows; i++)
    {
      for(int j = 0; j < slen; j++)
        {
          if((i+j)%T == 0||(j-i)%T == 0)
            {
              result[t] = s[j];
              t++;
            }
        }
    }
  result[slen] = '\0';
  return result;
}

int main() {
  char s[] = "LEETCODEISHIRING";
  /* LCIRETOESIIGEDHN */
  char* s_3;
  s_3 = convert(s,3);
  printf("s_3:%s\n",s_3);
  /* LDREOEIIECIHNTSG */
  char* s_4;
  s_4 = convert(s,4);
  printf("s_4:%s\n",s_4);
}
