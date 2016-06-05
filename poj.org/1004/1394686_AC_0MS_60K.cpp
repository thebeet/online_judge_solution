#include <stdio.h>
int main()
{
    float s[13];
	int i;
	float m=0;
	for	(i=1;i<13;i++)
	{
		scanf("%f",&s[i]);
		m+=s[i];
	}
    printf("$%.2f\n",m/12);
    return 0;
}