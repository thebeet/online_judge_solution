#include <iostream>
#include <string>

using namespace std;

int number[1048576];
char inp[1048576];

int main()
{
	int ti(0);
	string inp;
	while ((cin >> inp), inp != "0")
	{
		cout << ++ti << ". ";
		int t = inp.size();
		int i;
		number[t] = 0;
		for (i = t - 1; i >= 0; --i)
		{
			number[i] = inp[i] - '0';
			number[i] -= number[i + 1];
			if (number[i] < 0)
			{
				number[i] += 10;
				if (i > 0)
				{
					--inp[i - 1];
				}
			}
		}
		if (number[0] > 0)
		{
			for (i = 0; i < t; ++i)
			{
				printf("%d", number[i]);
			}
			cout << endl;
		}
		else
		{
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}
