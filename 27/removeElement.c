#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val)
{
  //swap the target element with tail of the array
  int len = 0;
  int i = 0;
  int j = numsSize - 1;
  int tmp = 0;

  if(numsSize==0)
    return 0;

  for(i=0;i<numsSize;i++)
    {
      while(j&&nums[j]==val)
        j--;
      if((i<j)&&nums[i]==val)
        {
          tmp = nums[i];
          nums[i] = nums[j];
          nums[j] = tmp;
          len++;
        }
      else if(nums[i] != val)
        {
          len++;
        }
      else
        return len;
    }
  return len;
}

int main()
{
  int nums1[] = {3, 2, 2, 3};
  int val1 = 3;

  int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2};
  int val2 = 2;

  int len1 = removeElement(nums1, 4, val1);
  int len2 = removeElement(nums2, 8, val2);

  for(int i = 0; i < len1; i++)
    {
      printf("%d ", nums1[i]);
    }
  printf("\n");

  for(int j = 0; j < len2; j++)
    {
      printf("%d ", nums2[j]);
    }
  printf("\n");
}
