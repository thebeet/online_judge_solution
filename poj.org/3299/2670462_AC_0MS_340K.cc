#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string st1, st2;
	double d1, d2, humidex, temperature, dewpoint, h, e;
	while ((cin >> st1), st1 != "E")
	{
		cin >> d1 >> st2 >> d2;
		if (st1 == "D")
		{
			dewpoint = d1;
			e = 6.11 * exp(5417.7530 * ((1/273.16) - (1/(dewpoint+273.16))));
			h = (0.5555) * (e - 10.0);
			if (st2 == "T")
			{
				temperature = d2;
				humidex = temperature + h;
			}
			else
			{
				humidex = d2;
				temperature = humidex - h;
			}
		}
		else if (st2 == "D")
		{
			dewpoint = d2;
			e = 6.11 * exp(5417.7530 * ((1/273.16) - (1/(dewpoint+273.16))));
			h = (0.5555) * (e - 10.0);
			if (st1 == "T")
			{
				temperature = d1;
				humidex = temperature + h;
			}
			else
			{
				humidex = d1;
				temperature = humidex - h;
			}
		}
		else
		{
			if (st1 == "T")
			{
				temperature = d1;
				humidex = d2;
			}
			else
			{
				temperature = d2;
				humidex = d1;
			}
			h = humidex - temperature;
			e = (h / 0.5555) + 10.0;
			dewpoint = 1/ (-(log(e / 6.11) / 5417.7530 - (1/273.16))) - 273.16;
		}
		printf("T %.1lf D %.1lf H %.1lf\n", temperature, dewpoint, humidex);
	}
	return 0;
}
