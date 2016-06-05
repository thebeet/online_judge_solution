#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	string dd;
	cin >> n >> dd;
	double df;
	dd = "0." + dd;
	char fmt[32];
	snprintf(fmt, 32,  "%%.%dlf", n);
	for (int i = 0; ; ++i)
	{
		double ans = sqrt((double)i);
		char buf[32];
		snprintf(buf, 32, fmt, ans - (int)ans);
		string s(buf);
		if (s == dd)
		{
			cout << i << endl;
			return 0;;
		}
	}
	return 0;
}




