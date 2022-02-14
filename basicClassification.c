#include <math.h>

/*Strong number is a special number whose sum of the factorial of digits is equal to the original
number. For Example: 145 is strong number
1! + 4! + 5! = 145
*/
int isStrong(int x) 
{
	int copyX=x;
	int answer=0;
	while(copyX>0)
	{
		int factorial=1;
		int unitP=copyX%10;
		int loop;
		for(loop=1;loop<=unitP;loop++)
		{
                   factorial=factorial*loop;
		}
		answer=answer+factorial;
		copyX=copyX/10;
	}
	return answer==x;
}
/* checks if a number is a prime number
int isPrime(int x)
{
        int rootX=sqrt(x);
        int loop;
        if(x%2==0 && x!=2)
        {
            return 0;
        }
        for(loop=3;loop<=rootX;loop=loop+2)
        {
            if(x%loop==0)
            {
                return 0;
            }
        }
        return 1;
}
