#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	string inp;
	cin >> inp;
	int emp(0);
	int sum(0);
	for (int i = 0; i < inp.size(); ++i)
	{
		if (inp[i] == '0')
		{
			if (inp[(i + 1) % inp.size()] == '0')
			{
				++emp;
			}
			++sum;
		}
	}
	if (emp * inp.size() == sum * sum)
	{
		cout << "EQUAL" << endl;
	}
	else if (emp * inp.size() < sum * sum)
	{
		cout << "ROTATE" << endl;
	}
	else
	{
		cout << "SHOOT" << endl;
	}
	return 0;
}
