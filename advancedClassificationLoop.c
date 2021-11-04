#include <math.h>
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
