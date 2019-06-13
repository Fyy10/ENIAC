#include<stdio.h>
int main()
{
	int s;
	char c;
	while(scanf("%d %c",&s,&c)==2)
	{
		switch(c)
		{
			case 'K':
				{
					if(s>1)
						printf("4\n");
					else
						printf("1\n");
					break;
				}
			case 'N':
				{
					if(s>2)
						printf("2\n");
					else
						printf("1\n");
					break;
				}
			case 'B':
				{
					printf("%d\n",s);
					break;
				}
			case 'R':
				{
					printf("%d\n",s);
					break;
				}
			default:;
		}
	}
	return 0;
}
