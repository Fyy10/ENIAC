#include<stdio.h>
int main()
{
	double h,l,v;
	while(scanf("%lf%lf%lf",&h,&l,&v)==3)
	{
		if(h==0&&l==0&&v==0)
			break;
		printf("%.2lf\n",-9.8/2/v/v*l*l+v*v/2/9.8+h);
	}
	return 0;
}
