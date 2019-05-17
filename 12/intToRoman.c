#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * intToRoman(int num)
 {
   static char roman[16];
   memset(roman,0x00,sizeof(roman));
    switch(num/1000)
      {
      case 0:
        break;
      case 1:
        strcat(roman,"M");
        break;
      case 2:
        strcat(roman,"MM");
        break;
      case 3:
        strcat(roman,"MMM");
        break;
      default:
        return NULL;;
      }
    num = num%1000;
    switch(num/100)
      {
      case 0:
        break;
      case 1:
        strcat(roman,"C");
        break;
      case 2:
        strcat(roman,"CC");
        break;
      case 3:
        strcat(roman,"CCC");
        break;
      case 4:
        strcat(roman,"CD");
        break;
      case 5:
        strcat(roman,"D");
        break;
      case 6:
        strcat(roman,"DC");
        break;
      case 7:
        strcat(roman,"DCC");
        break;
      case 8:
        strcat(roman, "DCCC");
        break;
      case 9:
        strcat(roman, "CM");
        break;
      default:
        return NULL;
      }
    num = num%100;
    switch(num/10)
      {
      case 0:
        break;
      case 1:
        strcat(roman,"X");
        break;
      case 2:
        strcat(roman,"XX");
        break;
      case 3:
        strcat(roman,"XXX");
        break;
      case 4:
        strcat(roman,"XL");
        break;
      case 5:
        strcat(roman,"L");
        break;
      case 6:
        strcat(roman,"LX");
        break;
      case 7:
        strcat(roman,"LXX");
        break;
      case 8:
        strcat(roman,"LXXX");
        break;
      case 9:
        strcat(roman,"XC");
        break;
      default:
        return NULL;
      }
    num = num%10;
    switch(num)
      {
      case 0:
        break;
      case 1:
        strcat(roman,"I");
        break;
      case 2:
        strcat(roman, "II");
        break;
      case 3:
        strcat(roman, "III");
        break;
      case 4:
        strcat(roman, "IV");
        break;
      case 5:
        strcat(roman, "V");
        break;
      case 6:
        strcat(roman, "VI");
        break;
      case 7:
        strcat(roman, "VII");
        break;
      case 8:
        strcat(roman, "VIII");
        break;
      case 9:
        strcat(roman, "IX");
        break;
      default:
        return NULL;
      }
    return roman;
}

int main()
{
    printf("%d:%s\n",3,intToRoman(3));
    printf("%d:%s\n",4,intToRoman(4));
    printf("%d:%s\n",9,intToRoman(9));
    printf("%d:%s\n",58,intToRoman(58));
    printf("%d:%s\n",1994,intToRoman(1994));
    return 0;
}
