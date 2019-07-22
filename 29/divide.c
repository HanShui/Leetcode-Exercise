#include <stdlib.h>
#include <stdio.h>

#define INT_MIN -2147483648
#define INT_MAX  2147483647


int divide(int dividend, int divisor)
{
  //32bit signed dividend && divisor

  //sign
  int sign = 0;
  long long quotient = 0;
  long long factor = 1;

  long long ll_dividend = dividend;
  long long ll_divisor = divisor;


  if(ll_dividend>=0 && ll_divisor>=0)
    {
      sign = 1;
    }
  else if(ll_dividend<0 && ll_divisor>=0)
    {
      sign = -1;
      ll_dividend = -ll_dividend;
    }
  else if(ll_dividend>=0 && ll_divisor<0)
    {
      sign = -1;
      ll_divisor = -ll_divisor;
    }
  else
    {
      sign = 1;
      ll_dividend = -ll_dividend;
      ll_divisor = -ll_divisor;
    }
  while(ll_dividend>=ll_divisor)
    {
      ll_divisor <<= 1;
      factor <<=1;
    }
  ll_divisor>>=1;
  factor>>=1;
  while(factor >= 1)
    {
      if(ll_dividend>=ll_divisor)
        {
          ll_dividend -= ll_divisor;
          quotient += factor;
        }
      factor>>=1;
      ll_divisor>>=1;
    }

  if(sign==1)
    {
      if(quotient>INT_MAX)
        return INT_MAX;
      else
        return (int)quotient;
    }
  else
    {
      if(quotient<INT_MIN)
        return INT_MAX;
      else
        return (int)(-quotient);
    }
}

int main()
{
  int dividend1 = 10;
  int divisor1 = 3;
  int quotient1 = divide(dividend1, divisor1);//expect 3

  int dividend2 = 7;
  int divisor2 = -3;
  int quotient2 = divide(dividend2, divisor2);//expect -2

  printf("quotient1: %d, quotient2: %d\n", quotient1, quotient2);
}
