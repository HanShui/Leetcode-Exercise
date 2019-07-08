#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** generateParenthesis(int n, int* returnSize)
{
  //the n-th ( must be placed before the 2n-th slot
  //recursive according for the last ( placement

  char ** result = NULL;
  char ** lastresult;
  int  lastreturnSize;

  *returnSize = 0;

  //special input
  if (n == 0)
    {
      *returnSize = 1;
      result = (char **) malloc (sizeof(char*)*(*returnSize));
      result[0] = "";
      return result;
    }
  else if (n == 1)
    {
      *returnSize = 1;
      result = (char **) malloc (sizeof(char*)*(*returnSize));
      result[0] = (char*) malloc (sizeof(char)*(2*n+1));
      memcpy(result[0],"()", 2*n+1);
      return result;
    }
  else
    {
      lastresult = generateParenthesis(n-1, &lastreturnSize);/*get the (n-1)-th
                                                               ( placement*/
      //malloc a size map array from n-1 to n
      int * mapSize = (int*) malloc (sizeof(int) * lastreturnSize);
      /* for every placement of the (n-1)-th (, calculate the n-th */
      for(int i=0;i<lastreturnSize;i++)
        {
          char * c = strrchr(lastresult[i],'(');
          int index_l = (int)(c-lastresult[i]);//lower bound index for the n-th '('
          int index_u = 2*n-2;//upper bound index for the n-th ')'
          mapSize[i] = index_u - index_l;
          int base = *returnSize;
          *returnSize += mapSize[i];
          
          result = (char **) realloc (result, sizeof(char*)*(*returnSize));
          for(int j=1;j<=mapSize[i];j++)
            {
              result[base+j-1] = (char*) malloc (sizeof(char)*(2*n+1));
              memset(result[base+j-1],')',sizeof(char)*2*n);
              result[base+j-1][2*n] = 0x00;
              memcpy(result[base+j-1],lastresult[i], 2*(n-1));
              result[base+j-1][index_l+j] = '(';
            }
        }
    }

  return result;
}


int main()
{
  int returnSize=0;
  int n=5;
  char** result;
  result = generateParenthesis(n, &returnSize);
  for(int i=0;i<returnSize;i++)
    {
      printf("%s\n",result[i]);
    }
  return 0;
}
