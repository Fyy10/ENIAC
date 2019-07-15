#include<stdio.h>
int main()
{
	char c;
	int star=1,team=1;
	while((c=getchar())!='\n')
		star*=(c-'A'+1);
	while((c=getchar())!='\n')
		team*=(c-'A'+1);
	if(team%47==star%47)
		printf("GO\n");
	else
		printf("STAY\n");
	return 0;
}
