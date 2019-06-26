#include <stdio.h>
#include <stdlib.h>


int inc(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
  //nums[l]+nums[i]+nums[j]+nums[r] = T
  //nums[l] <= T/4
  //nums[r] >= T/4

  //checking input array size
  if(numsSize<4)
    {
      *returnSize = 0;
      *returnColumnSizes = NULL;
      return NULL;
    }

  qsort(nums, numsSize, sizeof(int), inc);

  //find bound for l,r
  //find T/4 in nums
  int pivot = target/4;
  int ind_pivot = numsSize/2;
  int low = 0;
  int high = numsSize-1;
  int move = 0;
  while(1)
    {
      if(nums[ind_pivot] > pivot)
        {
          high = ind_pivot;
          ind_pivot = (ind_pivot + low)/2;
          if(low == high||high-low == 1)
            {
              break;
            }
        }
      else if(nums[ind_pivot] < pivot)
        {
          low = ind_pivot;
          ind_pivot = (ind_pivot + high)/2;
          if(low == high||high-low == 1)
            {
              break;
            }
        }
      else
        {
          high = ind_pivot;
          low = ind_pivot;
          break;
        }
    }
  //printf("low:%d, high:%d\n", low, high);
  //printf("1\n");
  //l<=low r>=high
  //fix l,r, looking for i,j
  int** result=NULL;
  *returnSize = 0;
  int i = 0;
  int j = 0;
  int l = 0;
  int r = 0;
  int lasti = 0;
  int lastj = 0;
  int lastl = 0;
  int lastr = 0;
  int firstflag = 1;

  for(int l=0;l<=low;l++)
    {
      if(nums[l]==nums[lastl] && !firstflag)
        {
          //pruning
          printf("last:%d\n", lastl);
          printf("now:%d\n", l);
          continue;
        }
      for(int r=numsSize-1;r>=high;r--)
        {
          if(r-l<3)
            break;
          else
            {
              if(nums[l]==nums[lastl] && nums[r]==nums[lastr] && !firstflag)
                {
                  //pruning
                  printf("last:%d %d\n", lastl, lastr);
                  printf("now:%d %d\n", l, r);
                  continue;
                }
              else
                {
                  i = l+1;
                  j = r-1;

                  //printf("2\n");
                  //due to l,i,j,r 
                  while(i<j)
                    {
                      if(nums[i]==nums[lasti] && nums[j]==nums[lastj] && nums[l]==nums[lastl] && nums[r]==nums[lastr]  && !firstflag)
                        {
                          //pruning
                          printf("last:%d %d %d %d\n", lastl, lasti, lastj, lastr);
                          printf("now:%d %d %d %d\n", l, i, j, r);
                          if(move >= 0)
                            {
                              lasti = i;
                              i++;
                            }
                          else
                            {
                              lastj = j;
                              j--;
                            }
                          firstflag = 0;
                          continue;
                        }
                      else
                        {
                          if(nums[l]+nums[i]+nums[j]+nums[r] == target)
                            {
                              printf("= %d,%d,%d,%d\n", l, i, j, r);
                              //hit
                              (*returnSize)++;
                              result = (int**) realloc (result, (*returnSize)*sizeof(int*));
                              result[(*returnSize)-1] = (int*) malloc (sizeof(int)*4);
                              result[(*returnSize)-1][0] = nums[l];
                              result[(*returnSize)-1][1] = nums[i];
                              result[(*returnSize)-1][2] = nums[j];
                              result[(*returnSize)-1][3] = nums[r];
                              lastl = l;
                              lasti = i;
                              lastj = j;
                              lastr = r;
                              //printf("last %d %d %d %d\n", l, i, j, r);
                              i++;
                              j--;
                              firstflag = 0;
                            }
                          else if(nums[l]+nums[i]+nums[j]+nums[r] < target)
                            {
                              //small
                              printf("< %d,%d,%d,%d\n", l, i, j, r);
                              lastl = l;
                              lasti = i;
                              lastj = j;
                              lastr = r;
                              //printf("last %d %d %d %d\n", l, i, j, r);
                              i++;
                              move = 1;
                              firstflag = 0;
                            }
                          else if(nums[l]+nums[i]+nums[j]+nums[r] > target)
                            {
                              //large
                              printf("> %d,%d,%d,%d\n", l, i, j, r);
                              lastl = l;
                              lasti = i;
                              lastj = j;
                              lastr = r;
                              //printf("last %d %d %d %d\n", l, i, j, r);
                              j--;
                              move = -1;
                              firstflag = 0;
                            }
                        }
                    }
                }
            }
        }
    }
  //printf("3\n");
  int *tmpColumnSizes = (int*) malloc (sizeof(int) * (*returnSize));
  for(int i = 0;i<*returnSize;i++)
    {
      tmpColumnSizes[i] = 4;
    }
  *returnColumnSizes = tmpColumnSizes;
  //printf("returnSize:%d\n",(*returnSize));
  return result;
}

int main()
{
  //int nums[] = {1, 0, -1, 0, -2, 2};
  //int target = 0;
  //int nums[] = {0, 0, 0, 0};
  //int target = 0;
  //int nums[] = {-1, -5, -5, -3, 2, 5, 0, 4};
  //int target = -7;
  //int nums[] = {-1, 2, 2, -5, 0, -1, 4};
  //int target = 3;
  int nums[] = {5, 5, 3, 5, 1, -5, 1, -2};
  int target = 4;

  int returnSize = 0;
  int* returnColumnSizes=NULL;
  int** result;

  result = fourSum(nums, 8, target, &returnSize, &returnColumnSizes);

  for(int i=0;i<returnSize;i++)
    {
      //printf("returnColumnSizes[%d]:%d\n", i, returnColumnSizes[i]);
      for(int j=0;j<returnColumnSizes[i];j++)
        {
          printf("%d ",result[i][j]);
        }
      //printf("returnSize:%d\n", returnSize);
      printf("\n");
    }
  return 0;
}
