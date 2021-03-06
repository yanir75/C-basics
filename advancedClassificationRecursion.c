#include <math.h>
int isArm(int x,int len)
{
        if(x>0)
        {
                return pow(x%10,len)+isArm(x/10,len);
        }
        else
        {
            return 0;
        }
}
int lenNum(int x)
{
        if(x>0)
        {
                return lenNum(x/10)+1;
        }
        else
        {
                return 0;
        }
}
int isPali(int x ,int rev)
{
    if(x==0)
    {
            return rev;
    }
    else
    {
            rev=rev*10+x%10;
            return isPali(x/10,rev);
    }
}
// checks if the number is a palindrome using recursion
int isPalindrome(int x)
{      int reverse=isPali(x,0);
       return reverse==x;
}
/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
using recursion
*/
int isArmstrong(int x)
{
    int length = lenNum(x);
	return x==isArm(x,length);
}
