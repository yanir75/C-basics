#include <math.h>
// checks if a number is a Palindrome
int isPalindrome(int x)
{
        int reverseX=0;
        int copyX=x;
        while(copyX>0)
        {
                reverseX=reverseX+copyX%10;
		copyX=copyX/10;
                if(copyX>0)
                {
                        reverseX=reverseX*10;
                }
        }
        return x==reverseX;
}
/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
Using loops
*/
int isArmstrong(int x)
{
	int copyX=x;
	int answer=0;
	int lenX=0;
	while(copyX>0)
	{
		copyX=copyX/10;
		lenX++;
	}
	copyX=x;
	while(copyX>0)
	{
		answer=answer+pow(copyX%10,lenX);
		copyX=copyX/10;
	}
	return answer==x;
}
