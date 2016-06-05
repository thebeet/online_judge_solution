#include <stdio.h>
#include <memory.h>

long ans[1010];
long s[11];

int main()
{
	long i,n,sss,t,j;
	char c;
	memset(s,0,sizeof(s));
	scanf("%c",&c);
	sss=0;
	while (c>20)
	{
		s[c-48]++;
		sss=sss+c-48;
		scanf("%c",&c);
	}
	if (sss<3)
	{
		printf("impossible\n");
		return 0;
	}
	if ((s[0]==0) && (s[5]==0))
	{
		printf("impossible\n");
		return 0;
	}
	if ((sss%3)==1)
	{
		if (s[1]>0)
			s[1]--;
		else
		{
			if (s[4]>0)
				s[4]--;
			else
			{
				if (s[7]>0)
					s[7]--;
				else
				{
					if (s[2]>1)
						s[2]-=2;
					else
					{
						if (((s[5]>0) && ((s[5]>1) || (s[0]>0))) && (s[2]>0))
						{
							s[2]--;
							s[5]--;
						}
						else
						{
							if ((s[2]>0) && (s[8]>0))
							{
								s[2]--;
								s[8]--;
							}
							else
							{
								if ((s[5]>1) && ((s[5]>2) || (s[0]>0)))
									s[5]-=2;
								else
								{
									if (((s[5]>0) && ((s[5]>1) || (s[0]>0))) && (s[8]>0))
									{
										s[5]--;
										s[8]--;
									}
									else
									{
										if (s[8]>1)
											s[8]-=2;
										else
										{
											printf("impossible\n");
											return 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if ((sss%3)==2)
	{
		if (s[2]>0)
			s[2]--;
		else
		{
			if ((s[5]>0) && ((s[5]>1) || (s[0]>0)))
				s[5]--;
			else
			{
				if (s[8]>0)
					s[8]--;
				else
				{
					if (s[1]>1)
						s[1]-=2;
					else
					{
						if ((s[4]>0) && (s[1]>0))
						{
							s[1]--;
							s[4]--;
						}
						else
						{
							if ((s[1]>0) && (s[7]>0))
							{
								s[1]--;
								s[7]--;
							}
							else
							{
								if (s[4]>1)
									s[4]-=2;
								else
								{
									if ((s[4]>0) && (s[7]>0))
									{
										s[4]--;
										s[7]--;
									}
									else
									{
										if (s[7]>1)
											s[7]-=2;
										else
										{
											printf("impossible\n");
											return 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}	
	sss=0;
	for (i=1;i<=9;i++)
		sss=sss+s[i]*i;
	if (sss<3) 
	{
		printf("impossible\n");
		return 0;
	}
	if (s[0]>0)
	{
		s[0]--;
		t=0;
	}
	else
	{
		s[5]--;
		t=5;
	}
	for (i=9;i>=0;i--)
	{
		for (j=1;j<=s[i];j++)
			printf("%d",i);
	}
	printf("%d\n",t);
	return 0;
}





