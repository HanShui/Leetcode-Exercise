#include <stdlib.h>
#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int inc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
  qsort(nums, numsSize, sizeof(int), inc);
  //printf("0\n");
  int tmpSize = 0;
  if(numsSize<3)
    {
      *returnSize = 0;
      *returnColumnSizes = 0;
      return NULL;
    }
  int i = 0;
  int j = 0;
  int k = 0;
  int lasti = 1;
  int lastj = -1;
  int lastk = -1;
  int flagj = 1;
  int tmpResultLen = sizeof(int*)*numsSize;
  int addResultLen = sizeof(int*)*numsSize;
  int** tmpResult = (int**) malloc (tmpResultLen);
  for(i = 0; i<numsSize-2; i++)
    {
      if(i != 0 && nums[i] == lasti)
        continue;
      flagj = 1;
      j = i+1;
      k = numsSize-1;
      /*if(flagi != 0)
        {
          if(nums[i] == lasti)
            {
              //printf("numsi[%d]: %d, lasti %d\n", i, nums[i], lasti);
              continue;
            }
        }
      */
      while(j < k)
        {
          if(nums[i]+nums[j]+nums[k] == 0)
            {
              printf("i:%d, j:%d, k:%d, sum:%d\n", i ,j, k, nums[i]+nums[j]+nums[k]);
              if(nums[i] == lasti && nums[j] == lastj && !flagj)
                {
                  j++;
                  continue;
                }
              if((tmpSize+1) * sizeof(int*) > tmpResultLen)
                {
                  tmpResult = (int**) realloc (tmpResult, tmpResultLen + addResultLen);
                  tmpResultLen += addResultLen;
                }
              tmpResult[tmpSize] = (int*) malloc (sizeof(int)*3);
              printf("i: %d, j:%d, k:%d\n",i, j, k);
              printf("nums[i]: %d, nums[j]: %d, nums[k]: %d\n", nums[i], nums[j], nums[k]);
              tmpResult[tmpSize][0] = nums[i];
              tmpResult[tmpSize][1] = nums[j];
              tmpResult[tmpSize][2] = nums[k];
              tmpSize++;
              lasti = nums[i];
              lastj = nums[j];
              lastk = nums[k];
              flagj = 0;
              j++;
            }
          else if(nums[i]+nums[j]+nums[k] < 0)
            {
              printf("i:%d, j:%d, k:%d, sum:%d\n", i ,j, k, nums[i]+nums[j]+nums[k]);
              j++;
              printf("i:%d, j:%d, k:%d, sum:%d\n", i ,j, k, nums[i]+nums[j]+nums[k]);
            }
          else if(nums[i]+nums[j]+nums[k] > 0)
            {
              printf("i:%d, j:%d, k:%d, sum:%d\n", i ,j, k, nums[i]+nums[j]+nums[k]);
              k--;
              printf("i:%d, j:%d, k:%d, sum:%d\n", i ,j, k, nums[i]+nums[j]+nums[k]);
            }
        }
    }
  printf("1\n");
  //returnSize = (int*) malloc (sizeof(int));
  int* tmpColumnSizes = (int*) malloc (sizeof(int*) * tmpSize);
  for(int i = 0;i<tmpSize;i++)
    {
      tmpColumnSizes[i] = 3; 
    }
  *returnSize = tmpSize;
  *returnColumnSizes = tmpColumnSizes;
  printf("2\n");
  printf("returnSize:%d\n",(*returnSize));
  return tmpResult;
}

int main()
{
  int nums[6] = {-1, 0 ,1, 2, -1 ,-4};
  //int nums[6] = {3, 0, -2, -1, 1, 2};
  //int nums[4] = {1,-1,-1,0};
  //int nums[17] = {-1, -2, -3, 4, 1, 3, 0, 3, -2, 1, -2, 2, -1, 1, -5, 4, -3};
  //int nums[5] = {-2, 0, 1, 1, 2};
  //int nums[15] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};

  int returnSize;
  printf("returnSize:%d\n",(returnSize));
  int* returnColumnSizes = NULL;
  int** result;
  result = threeSum(nums, 6, &returnSize, &returnColumnSizes);
  printf("returnSize:%d\n",returnSize);
  printf("3\n");

  //result output

  for(int i = 0; i < returnSize; i++)
    {
      for(int j = 0; j < returnColumnSizes[i]; j++)
        printf("%d, ", result[i][j]);
      printf("\n");
    }
}
