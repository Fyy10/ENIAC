#include<stdio.h>
#include<math.h>
void unitlize(float a[300][10]);
void setzero(float a[300][10]);
void setzero2(float b[10]);
void setone(float b[10]);
void findbest(float a[300][10],float b[10],int n,int m);
void findworst(float a[300][10],float b[10],int n,int m);
float angle(int h,float a[300][10],float b[10],int m);
float value(float a,float b);
void addweight(float a[300][10],float b[10]);
void outa(float a[300][10],int n,int m);
void outv(float a[300][10],float b1[10],float b2[10],int n,int m);
void main()
{
	float a[300][10],best[10],worst[10],weight[10];
	int n,m,j,k;
	FILE *fin=fopen("data.txt","r");
	FILE *win=fopen("weight.txt","r");
	setzero(a);
	setzero2(best);
	setone(worst);
	setone(weight);
	fscanf(fin,"%d %d",&n,&m);
	for(k=1;k<=m;k++)
		for(j=1;j<=n;j++) fscanf(fin,"%f",&a[j-1][k-1]);
	for(k=1;k<=m;k++) fscanf(win,"%f",&weight[k-1]);
	unitlize(a);
	addweight(a,weight);
	findbest(a,best,n,m);
	findworst(a,worst,n,m);
	outa(a,n,m);
	outv(a,best,worst,n,m);
	fclose(fin);
	fclose(win);
}
void unitlize(float a[300][10])
{
	int i,x;
	float unit;
	for(x=1;x<=10;x++)
	{
		unit=0;
		for(i=1;i<=300;i++) unit+=a[i-1][x-1]*a[i-1][x-1];
		unit=sqrt(unit);
		for(i=1;i<=300;i++) a[i-1][x-1]/=unit;
	}
}
void setzero(float a[300][10])
{
	int i,j;
	for(j=1;j<=10;j++)
		for(i=1;i<=300;i++) a[i-1][j-1]=0;
}
void setzero2(float b[10])
{
	int i;
	for(i=1;i<=10;i++) b[i-1]=0;
}
void setone(float b[10])
{
	int i;
	for(i=1;i<=10;i++) b[i-1]=1;
}
void findbest(float a[300][10],float b[10],int n,int m)
{
	int i,j;
	for(j=1;j<=m;j++)
		for(i=1;i<=n;i++)
			if(a[i-1][j-1]>b[j-1]) b[j-1]=a[i-1][j-1];
}
void findworst(float a[300][10],float b[10],int n,int m)
{
	int i,j;
	for(j=1;j<=m;j++)
		for(i=1;i<=n;i++)
			if(a[i-1][j-1]<b[j-1]) b[j-1]=a[i-1][j-1];
}
float angle(int h,float a[300][10],float b[10],int m)
{
	int j;
	float upn=0,downa=0,downb=0;
	for(j=1;j<=m;j++)
	{
		upn+=a[h-1][j-1]*b[j-1];
		downa+=a[h-1][j-1]*a[h-1][j-1];
		downb+=b[j-1]*b[j-1];
	}
	downa=sqrt(downa);
	downb=sqrt(downb);
	return acos(fabs(upn/(downa*downb)));
}
float value(float a,float b)
{
	return b/(a+b);
}
void addweight(float a[300][10],float b[10])
{
	int i,j;
	for(j=1;j<=10;j++)
		for(i=1;i<=300;i++) a[i-1][j-1]*=b[j-1];
}
void outa(float a[300][10],int n,int m)
{
	int i,j;
	FILE *fout=fopen("out.txt","w");
	for(j=1;j<=m;j++)
		for(i=1;i<=n;i++)
			if(i<n) fprintf(fout,"%.2f\n",a[i-1][j-1]);
				else fprintf(fout,"%.2f\n********\n",a[i-1][j-1]);
	fclose(fout);
}
void outv(float a[300][10],float b1[10],float b2[10],int n,int m)
{
	int i;
	FILE *vout=fopen("outv.txt","w");
	for(i=1;i<=n;i++) fprintf(vout,"%f\n",value(angle(i,a,b1,m),angle(i,a,b2,m)));
	fclose(vout);
}

