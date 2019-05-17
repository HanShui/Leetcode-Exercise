#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize)
{
  int* left = &height[0];
  int* right = &height[heightSize-1];
  int min_flag;
  int tmp_area;
  int curr;

  if(*left <= *right)
    min_flag = 0;
  else
    min_flag = 1;

  int area = ((1-min_flag) * (*left) + min_flag * (*right)) * (right-left);

  //printf("*left:%d,*right:%d,right-left/sizeof(int):%ld",*left,*right,(right-left));
  while(left != right)
    {
      if(min_flag==0)
        {
          curr = *left;
          //printf("*left:%d\n",*left);
          left++;
          while(*left<=curr&&right>left)
            {
              left++;
              printf("*left:%d\n",*left);
            }
          //printf("*left:%d\n",*left);
          if(*left <= *right)
            min_flag = 0;
          else
            min_flag = 1;
          tmp_area = ((1-min_flag) * (*left) + min_flag * (*right)) * (right-left);
          //printf("tmp_area:%d\n",tmp_area);
          area = (area>=tmp_area)? area : tmp_area;
          //printf("area:%d\n",area);
        }
      else
        {
          curr = *right;
          right--;
          while(*right<=curr&&right>left)
            {
              right--;
              printf("*right:%d\n",*right);
            }
          if(*left <= *right)
            min_flag = 0;
          else
            min_flag = 1;
          tmp_area = ((1-min_flag) * (*left) + min_flag * (*right)) * (right-left);
          //printf("tmp_area:%d\n",tmp_area);
          area = (area>=tmp_area)? area : tmp_area;
          //printf("area:%d\n",area);
        }
    }
  return area;
}

int main()
{
  int height[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int area = maxArea(height, 9);
  printf("area:%d\n",area);
}
