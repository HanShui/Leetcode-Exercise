#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

  给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

  示例:

  输入："23"
  输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

  说明:
  尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/

const char *map[10]  =
  {
    "",//0
    "",//1
    "abc",//2
    "def",//3
    "ghi",//4
    "jkl",//5
    "mno",//6
    "pqrs",//7
    "tuv",//8
    "wxyz"//9
  };


char ** letterCombinations(char * digits, int* returnSize)
{
  /* special end condition*/
  if(strlen(digits) == 0)
    {
      *returnSize = 0;
      return NULL;
    }
  /* end condition*/
  if(strlen(digits) == 1)
    {
      switch(*digits)
        {
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '8':
          *returnSize = 3;
          break;
        case '7':
        case '9':
          *returnSize = 4;
          break;
        }

      char **letterCombinations = (char**) malloc (sizeof(char*)*(*returnSize));
      for(int i=0;i<*returnSize;i++)
       {
         letterCombinations[i] = (char*)  malloc (sizeof(char)*2);
         letterCombinations[i][0] = map[*digits-'0'][i];
         letterCombinations[i][1] = 0x00;
        }
      return letterCombinations;
    }

  /*recursion*/
  else
    {
      int lastSize;
      int split;
      char **lastCombinations = letterCombinations(digits+1, &lastSize);

      switch(*digits)
        {
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '8':
          split = 3;
          *returnSize = split*lastSize;
          break;
        case '7':
        case '9':
          split = 4;
          *returnSize = split*lastSize;
          break;
        }

      char **letterCombinations = (char**) malloc (sizeof(char*)*(*returnSize));
      for(int i=0;i<split;i++)
        {
          for(int j=0;j<lastSize;j++)
            {
              letterCombinations[i*lastSize+j] = (char*) malloc (sizeof(char)*(strlen(digits)+1));
              letterCombinations[i*lastSize+j][0] = map[*digits-'0'][i];
              strcpy(&letterCombinations[i*lastSize+j][1], lastCombinations[j]);
            }
        }

      /* some clean job*/
      for(int i=0;i<lastSize;i++)
        {
          free(lastCombinations[i]);
        }
      free(lastCombinations);
      return letterCombinations;
    }
}

int main()
{
  char digits[3] = "23";
  int returnSize = 0;
  char** result;

  result = letterCombinations(digits, &returnSize);
  printf("%d\n", returnSize);

  for(int i = 0;i < returnSize;i++)
    {
      printf("%s\n", result[i]);
    }
}
