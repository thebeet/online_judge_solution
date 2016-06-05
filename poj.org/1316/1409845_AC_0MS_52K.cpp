#include <stdio.h>
#include <memory.h>
int main()
{
	int i,t,s;
	bool flag[11000];
	for (i=1;i<10001;i++)
		flag[i]=true;
	for (i=1;i<10001;i++)
	{
		if (flag[i]) printf("%d\n",i);
		t=i;
		s=0;
		while (t>0)
		{
			s=s+t%10;
			t=t/10;
		}
		flag[i+s]=false;
	}
	return 0;
}
	