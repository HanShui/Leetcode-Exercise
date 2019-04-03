#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPalindrome(int x){
  int digit_no = 0;
  int digits[10];
  if(x < 0) return false;
  while(x/10 != 0)
    {
      digit_no++;
      if(digit_no > 10) return false;
      digits[digit_no-1] = x%10;
      x = x/10;
    }
  digit_no++;
  if(digit_no > 10) return false;
  digits[digit_no-1] = x%10;
  for(int i = 0;i < digit_no/2; i++)
    {
      /* printf("digits[%d]:%d,digits[%d]:%d\n", i, digits[i], digit_no - i - 1, digits[digit_no - i - 1]); */
      if(digits[i] != digits[digit_no - i - 1])
        return false;
    }
  return true;
}

int main()
{
  int a = 121;
  bool a_res = isPalindrome(a);

  int b = -121;
  bool b_res = isPalindrome(b);

  int c = 10;
  bool c_res = isPalindrome(c);

  printf("a_res:%d, b_res:%d, c_res:%d\n", a_res, b_res, c_res);
}
