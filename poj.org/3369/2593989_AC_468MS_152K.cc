#include <stdio.h>

const int uplimit = 2000;

int main()
{
	int i1, i2, i3, i4;
	int s2, s3, bs3;
	int m2, m3;
	for (i1 = 1; i1 <= 125; ++i1)
	{
		for (i2 = i1; i2 <= 592; ++i2)
		{
			s2 = i1 + i2;
			m2 = i1 * i2;
			
			for (i3 = i2; i3 <= 884; ++i3)
			{
				s3 = s2 + i3;
				if ((s3 + i3) > uplimit)
				{
					break;
				}
				m3 = m2 * i3; 
				if (m3 <= 1000000)
				{
					continue;
				}
				bs3 = s3 * 1000000;
				m3 -= 1000000;
				i4 = bs3 / m3;
				if ((i4 >= i3) && (s3 + i4 <= uplimit) && ((bs3 % m3) == 0))
				{
					printf("%d.%02d %d.%02d %d.%02d %d.%02d\n", i1 / 100, i1 % 100, i2 / 100, i2 % 100, i3 / 100, i3 % 100, i4 / 100, i4 % 100);
				}
			}
		}
	}
	return 0;	
}
