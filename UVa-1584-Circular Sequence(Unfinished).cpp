#include<stdio.h>
#include<string.h>
int main()
{
	char dicstr[100];
	int p,i,dicsum,minsum=0,mini=0;
	scanf("%s",dicstr);
	for(i=0;i<strlen(dicstr);++i)
	{
		dicsum=0;
		p=i;
		while(p+1!=i)
		{
			dicsum+=dicstr[p];
			if(p+1==strlen(dicstr))
				p=0;
			else
				++p;
		}
	}
	return 0;
}
