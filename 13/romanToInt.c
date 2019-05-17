#include <stdlib.h>
#include <stdio.h>

int romanToInt(char * s)
{
  char* p=s;
  int thousands = 0;
  int hundreds = 0;
  int tens = 0;
  int ones = 0;
  for(;*p!=0;)
    {
      //printf("%d\n",*p);
      switch(*p)
        {
        case 'M':
          do
            {
              thousands++;
              p++;
            }
          while(*p == 'M');
          break;
        case 'D':
          hundreds = hundreds + 5;
          p++;
          break;
        case 'C':
          if(*(p+1) == 'M')
            {
              hundreds = hundreds + 9;
              p = p + 2;
            }
          else if(*(p+1) == 'D')
            {
              hundreds = hundreds + 4;
              p = p + 2;
            }
          else
            do
              {
                hundreds++;
                p++;
              }
            while(*p == 'C');
          break;
        case 'L':
          tens = tens + 5;
          p++;
          break;
        case 'X':
          if(*(p+1) == 'C')
            {
              tens = tens + 9;
              p = p + 2;
            }
          else if(*(p+1) == 'L')
            {
              tens = tens + 4;
              p = p + 2;
            }
          else
            do
              {
                tens++;
                p++;
              }
            while(*p == 'X');
          break;
        case 'V':
          ones = ones + 5;
          p++;
          break;
        case 'I':
          if(*(p+1) == 'X')
            {
              ones = ones + 9;
              p = p + 2;
            }
          else if(*(p+1) == 'V')
            {
              ones = ones + 4;
              p = p + 2;
            }
          else
            do
              {
                ones++;
                p++;
              }
            while(*p == 'I');
          break;
        default:
          p++;
          break;
        }
    }
  return thousands*1000+hundreds*100+tens*10+ones;
}

int main()
{
  printf("%s:%d\n", "III", romanToInt("III"));
  printf("%s:%d\n", "IV", romanToInt("IV"));
  printf("%s:%d\n", "IX", romanToInt("IX"));
  printf("%s:%d\n", "LVIII", romanToInt("LVIII"));
  printf("%s:%d\n", "MCMXCIV", romanToInt("MCMXCIV"));
}
