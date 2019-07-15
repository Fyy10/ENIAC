#include<stdio.h>
long int change(long int a,long int b);
long int max(long int a1,long int a2);
int main()
{
	long int x,y;
	//freopen("out1.txt","w",stdout);
	scanf("%ld %ld",&x,&y);
	printf("%ld\n",change(x,y));
	/*int i;
	for(i=100;i<150;++i)
	{
		//printf("i=%d\n",i);
		printf("%ld\n",change(i,i));
	}*/
	return 0;
}
long int change(long int a,long int b)
{
	int n1,n2,n5;
	long int n10,tmp;
	/*n1=1;
	if(max(a,b)<5)
		n2=max(a,b)/2;
	else
		n2=2;
	if(max(a,b)>5)
		n5=1;
	else
		n5=0;
	n10=max(a,b)/10;*/ 
	//printf("%d %d %d %d\n",n1,n2,n5,n10);
	//if(max(a,b)<10)
	{
		tmp=max(a/10,b/10);
		a=a%10;
		b=b%10;
		tmp+=max(a/5,b/5);
		a=a%5;
		b=b%5;
		tmp+=max(a/2,b/2);
		a=a%2;
		b=b%2;
		tmp+=max(a,b);
	}
	//else
	//	tmp=max(a,b)/10+4;*/
	//tmp=n1+n2+n5+n10;
	return tmp;
}
long int max(long int a1,long int a2)
{
	return a1>a2?a1:a2;
}
