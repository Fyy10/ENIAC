#include<stdio.h>
#include<string.h>
char reverse[]="123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ5YXWVUT2   O MJ LIH  3   A 8  Z ES1";
int main()
{
	char strin[100];
	int i,j,judgep=1,judger=1;
	scanf("%s",strin);
	for(i=0;i<strlen(strin);++i)
	{
		for(j=0;strin[i]!=reverse[j];++j);
		if(strin[strlen(strin)-i-1]!=reverse[strlen(reverse)-j-1])
			judger=0;
	}
	for(i=0;i<(strlen(strin)+1)/2;++i)
		if(strin[i]!=strin[strlen(strin)-i-1])
			judgep=0;
	if(judgep&&judger)
		printf("%s--is a mirrored palindrome.\n",strin);
	if(!judgep&&judger)
		printf("%s--is a mirrored string.\n",strin);
	if(judgep&&!judger)
		printf("%s--is a regular palindrome.\n",strin);
	if(!judgep&&!judger)
		printf("%s--is not a palindrome.\n",strin);
	return 0;
}
