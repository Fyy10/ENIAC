#include<stdio.h>
int main()
{
	char c;
	bool state=1;
	while((c=getchar())!=EOF)
	{
		if(c=='"')
		{
			if(state)
				printf("``");
			else
				printf("''");
			state=!state;
		}
		else
			putchar(c);
	}
	return 0;
}
