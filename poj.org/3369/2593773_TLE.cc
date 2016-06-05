#include <stdio.h>

const unsigned int uplimit = 2000;
const unsigned int mmm = 1 << 30;

int main()
{
	unsigned int i1, i2, i3, i4;
	unsigned int s2, s3;
	unsigned int m2, m3;
	double sd2, sd3;
	double d1, d2, d3;
	double md2, md3;
	double upd = 20.0;
	unsigned int limit2;
	//setbuf(stdout, NULL);
	for (i1 = 1; i1 <= 125; ++i1)
	{
		d1 = (double)i1 / 100.0;
		switch (i1)
		{
		case 1:
			limit2 = 1600;
			break;
		case 2:
			limit2 = 1200;
			break;
		default:
			limit2 = 896;
		}
		for (i2 = i1; i2 <= limit2; ++i2)
		{
			d2 = (double)i2 / 100.0;
			sd2 = d1 + d2;
			md2 = d1 * d2;
			
			if ((md2 * d2 * d2) > sd2 + upd + upd + 0.001)
			{
				break;
			}
			if ((md2 * upd * upd) < sd2 + d2 + d2 - 0.001)
			{
				break;
			}
			
			s2 = i1 + i2;
			m2 = i1 * i2;
			
			for (i3 = i2; i3 <= 1875; ++i3)
			{
				s3 = s2 + i3;
				m3 = m2 * i3; 
				if (m3 <= 1000000)
				{
					continue;
				}
				s3 *= (unsigned int)1000000;
				m3 -= (unsigned int)1000000;
				i4 = s3 / m3;
				if ((i4 >= i3) && (i4 <= uplimit) && ((s3 % m3) == 0))
				{
					printf("%d.%02d %d.%02d %d.%02d %d.%02d\n", i1 / 100, i1 % 100, i2 / 100, i2 % 100, i3 / 100, i3 % 100, i4 / 100, i4 % 100);
				}
			}
		}
	}
	return 0;	
}
