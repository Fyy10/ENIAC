#include<stdio.h>
int main()
{
	char a=0xb6;
	short b=0xb600;
	int c=0xb6000000;
	printf("%x\n",(int)a);
	printf("%x\n",(int)b);
	if(a==0xb6)
		printf("a\n");
	if(b==0xb600)
		printf("b\n");
	if(c==0xb6000000)
		printf("c\n"); 
	return 0; 
}
