#include<stdio.h>
int main()
{
	int hh1,hh2,mm1,mm2;
	scanf("%d:%d",&hh1,&mm1);
	scanf("%d:%d",&hh2,&mm2);
	mm1+=hh1*60;
	mm2+=hh2*60;
	mm2=(mm1+mm2)/2;
	hh2=mm2/60;
	mm2%=60;
	printf("%02d:%02d\n",hh2,mm2);
	return 0;
}
