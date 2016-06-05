#include <stdio.h>
int main()
{
	int i;
	float s,t;
	while (scanf("%f",&s))
	{
		t=0;
		for	(i=2;t<s;i++)
		{
			t=t+1.0/i;
		}
		printf("%d card(s)\n",i-2);
	}
    return 0;
}