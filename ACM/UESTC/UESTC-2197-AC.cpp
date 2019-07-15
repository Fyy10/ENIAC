#include<stdio.h>
int main()
{
	int n,i,j,row,col,w,h,k;
	scanf("%d",&n);
	for(k=1;k<=n;k++)
	{
		scanf("%d %d %d %d",&row,&col,&w,&h);
		printf("Case #%d:\n",k);
		for(i=1;i<=(h+1)*row+1;i++)
		{
			for(j=1;j<=(w+1)*col+1;j++)
			{
				if(i%(h+1)==1)
				{
					if(j%(w+1)==1)
						printf("+");
					else
						printf("-");
				}
				else
				{
					if(j%(w+1)==1)
						printf("|");
					else
						printf("*");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
