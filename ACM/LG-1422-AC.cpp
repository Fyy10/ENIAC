#include<stdio.h>
int main()
{
	int p;
	double m;
	scanf("%d",&p);
	if(p<=150)
		m=0.4463*p;
	else
		if(p<=400)
			m=150*0.4463+(p-150)*0.4663;
		else
			m=150*0.4463+(400-150)*0.4663+(p-400)*0.5663;
	printf("%.1lf\n",m);
	return 0; 
}
