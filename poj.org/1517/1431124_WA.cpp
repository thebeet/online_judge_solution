#include <stdio.h>
int main()
{
	long i,n;
	double ans;
	ans=0;
	printf("n e\n");
	printf("- -----------\n");
	n=1;
	i=0;
	ans=ans+1.0/n;
	printf("%d %.9g\n",i,ans);
	for (i=1;i<=9;i++)
	{
		n=n*i;
		ans=ans+1.0/n;
		printf("%d %.9g\n",i,ans);
	}
	return 0;
}



