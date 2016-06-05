#include <iostream>
#include <string>

using namespace std;

string inp;

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		unsigned int i, st;
		int point;
		cin >> inp;
		point = 0;
		if ((inp[0] == '-') || (inp[0] == '+'))
		{
			st = 1;
		}
		else
		{
			st = 0;
		}
		for (i = st; i < inp.size(); ++i)
		{
			if ((inp[i] >= '0') && (inp[i] <= '9'))
			{
				continue;
			}
			else if (inp[i] == '.')
			{
				if (point >= 1)
				{
					break;
				}
				point = 1;
				if (i == st)
				{
					break;
				}
				st = i + 1;
			}
			else if ((inp[i] == 'e') || (inp[i] == 'E'))
			{
				if (point == 2)
				{
					break;
				}
				if (point == 1)
				{
					if (i == st)
					{
						break;
					}
				}
				point = 2;
				if (i == inp.size() - 1)
				{
					break;
				}
				if ((inp[i + 1] == '+') || (inp[i + 1] == '-'))
				{
					++i;
				}
				st = i + 1;
			}
			else
			{
				break;
			}
		}
		if ((i == st) || (i < inp.size()))
		{
			cout << "ILLEGAL" << endl;
		}
		else
		{
			cout << "LEGAL" << endl;
		}
	}
	return 0;
}
