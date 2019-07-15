#include<stdio.h>
#include<string.h>
char stringform[]="`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
	int i;
	char c;
	while((c=getchar())!=EOF)
	{
		for(i=0;stringform[i]!=0&&c!=stringform[i];++i);
		if(stringform[i]==0)
			putchar(c);
		else
			putchar(stringform[i-1]);
	}
	return 0;
}
