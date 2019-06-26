#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int inc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target)
{
  int closest = nums[0]+nums[1]+nums[2];
  int diff = abs(closest - target);
  qsort(nums, numsSize, sizeof(int),inc);
  for(int i = 0; i < numsSize - 2; i++)
    {
      int left = i + 1;
      int right = numsSize - 1;
      while(left < right)
        {
          int sum = nums[i]+nums[left]+nums[right];
          printf("i: %d,j: %d, k: %d, sum: %d, target: %d\n", i ,left, right, sum, target);
          int newDiff = abs(sum-target);
          if(diff > newDiff)
            {
              diff = newDiff;
              closest = sum;
            }
          if(sum < target) ++left;
          else --right;
        }
    }
  return closest;
}


int main()
{
  //int nums[4] = {-1, 2, 1, -4};
  //int nums[3] = {0, 1, 2};
  //int nums[10] = {0, 5, -1, -2, 4, -1, 0, -3, 4, -5};
  int nums[6] = {-1,0,1,1,5,5};
  int target = 1;
  //expect result (-1 + 2 + 1 = 2)
  int result = threeSumClosest(nums, 6, target);
  printf("result: %d\n", result);
}
