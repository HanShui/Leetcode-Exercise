#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize)
{
  int lens = 0;
  int j = 0;
  char * result;
  if(strsSize==0)
    return NULL;
  while(1)
    {
      for(int i=0; i<strsSize; i++)
        {
          if(strs[i][lens]-strs[0][lens] != 0||strs[i][lens] == 0||strs[0][lens] == 0)
            {
              result = (char*) malloc (sizeof(char)*(lens+1));
              memset(result, 0x00, sizeof(char)*(lens+1));
              memcpy(result, strs[0], sizeof(char)*lens);
              return result;
            }
        }
      lens++;
      //printf("lens:%d\n",lens);
    }
}

int main()
{
  char *strs1[7] = {"flower", "flow", "flight"};
  char *strs2[8] = {"dog", "racecar", "car"};
  printf("strs1 prefix:%s\n",longestCommonPrefix(strs1,3));
  printf("strs2 prefix:%s\n",longestCommonPrefix(strs2,3));
}
