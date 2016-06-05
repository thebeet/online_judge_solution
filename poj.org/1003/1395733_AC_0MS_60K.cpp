#include <stdio.h>
int main()
{
	int i;
	float s,t;
	scanf("%f",&s);
	while (s>0.00001)
	{
		t=0;
		for	(i=2;t<s;i++)
		{
			t=t+1.0/i;
		}
		printf("%d card(s)\n",i-2);
		scanf("%f",&s);
	}
    return 0;
}