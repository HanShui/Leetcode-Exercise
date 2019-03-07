#include<stdio.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  if(nums1Size > nums2Size)
    return findMedianSortedArrays(nums2,nums2Size,nums1,nums1Size);

  int iMin = 0;
  int iMax = nums1Size;
  int halfLen = (nums1Size + nums2Size + 1)/2;

  while (iMin <= iMax) {
    int i = (iMin + iMax) / 2;
    int j = halfLen - i;
    if (i < iMax && nums2[j-1] > nums1[i]){
      iMin = i + 1; // i is too small
    }
    else if (i > iMin && nums1[i-1] > nums2[j]){
      iMax = i - 1; // i is too big
    }
    else { // i is perfect
      int maxLeft = 0;
      if (i==0) {maxLeft = nums2[j-1];}
      else if (j==0) {maxLeft = nums1[i-1];}
      else {maxLeft = (nums1[i-1]>=nums2[j-1]) ?nums1[i-1]:nums2[j-1];}
      if ((nums1Size+nums2Size)%2 == 1) {return maxLeft;}

      int minRight = 0;
      if(i == nums1Size) {minRight = nums2[j];}
      else if (j == nums2Size) {minRight = nums1[i];}
      else {minRight = (nums2[j]<=nums1[i]) ? nums2[j]:nums1[i];}

      return (maxLeft + minRight) / 2.0;
    }

  }

  return 0.0;
}

int  main()
{
  int a1[1] = {2};
  int a2[3] = {1,3,4};
  double t =  findMedianSortedArrays(a1,1,a2,3);
  printf("%lf\n",t);
  return 0;

}
