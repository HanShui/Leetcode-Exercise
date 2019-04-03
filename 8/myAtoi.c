#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

int myAtoi(char* str){
  char *p = str;
  int out = 0;
  int digit = 0;
  int sign = 1;
  int first_flag = 1;

  while(1)
    {
      switch(*p)
        {
        case '\0':
          return out*sign;
        case ' ':
        case '\t':
          if(first_flag == 0)
            return out*sign;
          else
            {
              p++;
              break;
            }
        case '-':
          if(first_flag == 1)
            {
              p++;
              sign = -1;
              first_flag = 0;
              break;
            }
          else
            {
              return out*sign;
            }
        case '+':
          if(first_flag == 1)
            {
              p++;
              sign = 1;
              first_flag = 0;
              break;
            }
          else
            {
              return out*sign;
            }
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          first_flag = 0;
          digit = *p - '0';
          if(sign > 0 && INT_MAX/10.0*sign - digit/10.0 <= out)
            {
              return INT_MAX;
            }
          if(sign <0 && INT_MIN/10.0*sign - digit/10.0 <= out)
            {
              return INT_MIN;
            }
          out = out * 10 + digit;
          p++;
          break;
        default:
          return out*sign;
        }
    }
}

int main(){
  char *a = "42";
  int a_res = myAtoi(a);
  int a_res_lib = atoi(a);
  printf("%s after myatoi: %d, atoi: %d\n", a, a_res, a_res_lib);

  char *b = "   -42";
  int b_res = myAtoi(b);
  int b_res_lib = atoi(b);
  printf("%s after myatoi: %d, atoi: %d\n", b, b_res, b_res_lib);

  char *c  = "4193 with words";
  int c_res = myAtoi(c);
  int c_res_lib = atoi(c);
  printf("%s after myatoi: %d, atoi: %d\n", c, c_res, c_res_lib);

  char *d = "words and 987";
  int d_res = myAtoi(d);
  int d_res_lib = atoi(d);
  printf("%s after myatoi: %d, atoi: %d\n", d, d_res, d_res_lib);

  char *e = "-91283472332";
  int e_res = myAtoi(e);
  int e_res_lib = atoi(e);
  /* -2147483648 */
  printf("%s after myatoi: %d, atoi: %d\n", e, e_res, e_res_lib);

  char *f = "-2147483648";
  int f_res = myAtoi(f);
  int f_res_lib = atoi(f);
  printf("%s after myatoi: %d, atoi: %d\n", f, f_res, f_res_lib);

  char *g = "   +0 123";
  int g_res = myAtoi(g);
  int g_res_lib = atoi(g);
  printf("%s after myatoi: %d, atoi: %d\n", g, g_res, g_res_lib);

  return 0;
}
