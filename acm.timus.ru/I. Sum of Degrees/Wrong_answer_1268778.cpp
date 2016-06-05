#include "stdio.h"

#define MAX 33

typedef long long INT;

INT c[MAX][MAX];
INT a[MAX+3][2];
INT sum[2],tmp[2];
int k;

INT gcd(INT n,INT m){
	if (m==0)
		return n;
	return gcd(m,n%m);
}

void reg(INT *a){
	if (a[1]<0){
		a[0]=-a[0];
		a[1]=-a[1];
	}
	if (a[0]==0)
		a[1]=1;
}

void mul(INT *a,INT b,INT *c){
	INT g=gcd(a[1],b);
	b/=g;
	c[0]=a[0]*b;
	c[1]=a[1]/g;
}

void add(INT *a,INT *b,INT *c){
	INT g;
	c[0]=a[0]*b[1]+b[0]*a[1];
	c[1]=a[1]*b[1];
	reg(c);
	if (c[1]<0)
		g=gcd(c[0],-c[1]);
	else 
		g=gcd(c[0],c[1]);	
	c[0]/=g;
	c[1]/=g;
	reg(c);
}

void div(INT *a,INT b,INT *c){
	INT g;
	if (c[0]<0)
		g=gcd(-c[0],b);
	else
		g=gcd(c[0],b);
	c[0]=a[0]/g;
	b/=g;
	c[1]=a[1]*b;
}

int main(){
	/*
#ifndef ONLINE_JUDGE
	freopen("test.txt","r",stdin);
#endif
	*/
	int i,j;
	int flag;
	c[0][0]=1;
	for (i=1;i<=31;i++){
		c[i][0]=1;
		c[i][i]=1;
		for (j=1;j<i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	scanf("%d",&k);
	a[k+1][0]=1;
	a[k+1][1]=c[k+1][1];
	a[0][0]=0;
	a[0][1]=1;
	for (i=k;i>0;i--){
		flag=1;
		sum[0]=0;
		sum[1]=1;
		for (j=i+1;j<=k+1;j++,flag=-flag){
			mul(a[j],c[j][j-i+1],tmp);
			tmp[0]*=flag;
			reg(tmp);
			add(sum,tmp,sum);
			reg(sum);
		}
		div(sum,c[i][1],sum);
		a[i][0]=sum[0];
		a[i][1]=sum[1];
	}
	for (i=k+1;i>0;i--)
		printf("%lld/%lld ",a[i][0],a[i][1]);
	printf("0/1\n");
	return 0;
}
