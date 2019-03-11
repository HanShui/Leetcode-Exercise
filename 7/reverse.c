#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

int reverse(int x){
  int rev = 0;
  while (x/10 != 0)
    {
      if(rev > INT_MAX/10.0 - x%10/10.0 || rev < INT_MIN/10.0 - x%10/10.0)
        return 0;
      rev = rev*10 + x%10;
      x = x/10;
    }
  if(rev > INT_MAX/10.0 - x%10/10.0 || rev < INT_MIN/10.0 - x%10/10.0)
    return 0;
  rev = rev*10 + x%10;
  return rev;
}

int main(){
  int a = 123;
  int a_rev = reverse(a);
  printf("a:%d, reverse:%d\n", a, a_rev);

  int b = -123;
  int b_rev = reverse(b);
  printf("b:%d, reverse:%d\n", b, b_rev);

  int c = 120;
  int c_rev = reverse(c);
  printf("c:%d, reverse:%d\n", c, c_rev);


  printf("INT_MIN:%d,INT_MAX:%d\n",INT_MIN,INT_MAX);
  int d = 1534236469;
  int d_rev = reverse(d);
  printf("d:%d, reverse:%d\n", d, d_rev);

  return 0;
}
