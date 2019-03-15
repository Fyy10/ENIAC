#include<stdio.h>
int main()
{
	int T,rightn,digit;
	long int n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%ld",&n);
		rightn=n%10;
		if(rightn==0||rightn==1||rightn==5||rightn==6||rightn==9)
			digit=rightn;
		else
			switch(rightn)
			{
				case 2:
				{
					if(n%4==0)
						digit=6;
					else
						digit=4;
					break;
				}
				case 3:
				{
					if(n%4==1)
						digit=3;
					else
						digit=7;
					break;
				}
				case 4:
				{
					digit=6;
					break;
				}
				case 7:
				{
					if(n%4==1)
						digit=7;
					else
						digit=3;
					break;
				}
				case 8:
				{
					if(n%4==0)
						digit=6;
					else
						digit=4;
					break;
				}
			}
		printf("%d\n",digit);
	}
	return 0;
}
