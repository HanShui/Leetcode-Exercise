#include <stdlib.h>
#include <stdio.h>

void nextPermutation(int* nums, int numsSize)
{
  //find max k, so that nums[k] < nums[k+1], if not exist reverse nums
  //find max l, so that nums[l] > nums[k]
  //swap nums[k] with nums[l]
  //reverse nums[k+1:]

  //1. find max k
  int k = -1;
  for(int i=0;i<numsSize-1;i++)
    {
      if(nums[i] < nums[i+1])
        {
          k = i;
        }
    }

  //2. find max l
  int l = -1;
  if(k!=-1)
    {
      for(int i=0;i<numsSize;i++)
        {
          if(nums[i] > nums[k])
            {
              l = i;
            }
        }
    }

  //3. swap nums[k] with nums[l]
  if (k!=-1 && l!=-1)
    {
      int tmp = nums[k];
      nums[k] = nums[l];
      nums[l] = tmp;
    }

  //4. revers nums[k+1:]
  for(int i=k+1,j=numsSize-1;i<j;i++,j--)
    {
      int tmp = nums[i];
      nums[i] = nums[j];
      nums[j] = tmp;
    }
  return;
}

int main()
{
  int nums1[] = {1,2,3};//expect 1,3,2
  int len1 = 3;
  nextPermutation(nums1, len1);
  printf("nums1: %d,%d,%d\n",nums1[0],nums1[1],nums1[2]);

  int nums2[] = {3,2,1};//expect 1,2,3
  int len2 = 3;
  nextPermutation(nums2, len2);
  printf("nums2: %d,%d,%d\n",nums2[0],nums2[1],nums2[2]);

  int nums3[] = {1,1,5};//expect 1,5,1
  int len3 = 3;
  nextPermutation(nums3, len3);
  printf("nums3: %d,%d,%d\n",nums3[0],nums3[1],nums3[2]);

  return 0;
}
