#include<stdio.h>
#include<string.h>
void convert(char *p);
int main()
{
	char a[201],b[10]="START";
	while(strcmp("ENDOFINPUT",b)!=0)
	{
		gets(b);
		if(strcmp("ENDOFINPUT",b)==0)
			break;
		gets(a);
		gets(b);
		convert(a);
		puts(a);
	}
	return 0;
}
void convert(char *p)
{
	int i;
	for(i=0;i<strlen(p);++i)
	{
		if(p[i]>='A'&&p[i]<='Z')
			if(p[i]-5<'A')
				p[i]=p[i]-5+26;
			else
				p[i]-=5;
	}
}
