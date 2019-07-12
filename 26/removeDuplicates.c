#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize){
  //constant extra space for placement
  int i=0;
  int j=0;
  int len = 1;
  int lastj=0;

  if(numsSize==0)
    return 0;

  for(i=0;i<numsSize;i++)
    {
      for(j=lastj+1;j<numsSize;j++)
        {
          if(nums[j]==nums[i])
            {
              printf("j:%d\n",j);
              continue;
            }
          else
            {
              lastj = j;
              nums[i+1] = nums[j];
              printf("i:%d,j:%d\n",i,j);
              len++;
              break;
            }
        }
      //reach the end of array
      if(j==numsSize)
        return len;
    }
   return len;
}

int main()
{
  //int nums1[] = {1, 1, 2};
  //int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int nums2[] = {-1,0,0,0,0,3,3};

  //int len1 = removeDuplicates(nums1, 3);
  int len2 = removeDuplicates(nums2, 7);

  /*
  for(int i=0; i<len1; i++)
    {
      printf("%d", nums1[i]);
    }
  printf("\n");
  */

  for(int i=0; i<len2; i++)
    {
      printf("%d", nums2[i]);
    }
  printf("\n");
  return 0;
}
