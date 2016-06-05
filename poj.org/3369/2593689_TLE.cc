#include <stdio.h>

const unsigned int uplimit = 2000;

int main()
{
	unsigned int i1, i2, i3, i4;
	unsigned int s2, s3;
	unsigned int m2, m3;
	double sd2, sd3;
	double d1, d2, d3;
	double md2, md3;
	double upd = 20.0;
	//setbuf(stdout, NULL);
	for (i1 = 1; i1 <= 125; ++i1)
	{
		//d1 = (double)i1 / 100.0;
		for (i2 = i1; i2 <= uplimit; ++i2)
		{
			//d2 = (double)i2 / 100.0;
			
			s2 = i1 + i2;
			//sd2 = d1 + d2;
			m2 = i1 * i2;
			//md2 = d1 * d2;
			/*
			if ((md2 * d2 * d2) > sd2 + upd + upd + 0.001)
			{
				break;
			}
			if ((md2 * upd * upd) < sd2 + d2 + d2 - 0.001)
			{
				break;
			}*/
			
			for (i3 = i2; i3 <= uplimit; ++i3)
			{
				s3 = s2 + i3;
				m3 = m2 * i3;
				if ((m3 % 100) != 0)
				{
					continue;
				}
				m3 /= 100;
				if (m3 <= 10000)
				{
					continue;
				}
				
				i4 = (s3 * 10000) / (m3  - 10000);
				if ((i4 >= i3) && (i4 <= uplimit) && ((s3 * 10000) % (m3  - 10000) == 0))
				{
					printf("%d.%02d %d.%02d %d.%02d %d.%02d\n", i1 / 100, i1 % 100, i2 / 100, i2 % 100, i3 / 100, i3 % 100, i4 / 100, i4 % 100);
				}
			}
		}
	}
	return 0;	
}
