#include <iostream>

using namespace std;

int meat[32];

int main()
{
	int n;
	while ((cin >> n), n > 0)
	{
		int i, s, sum;
		sum = 0;
		for (i = 1; i <= n; ++i)
		{
			cin >> meat[i];
			sum += meat[i];
		}
		s = 0;
		for (i = 1; i <= n; ++i)
		{
			s += meat[i];
			if ((s + s) == sum)
			{
				break;
			}
		}
		if (i <= n)
		{
			cout << "Sam stops at position " << i <<" and Ella stops at position " << i + 1 << "." << endl;
		}
		else
		{
			cout << "No equal partitioning." << endl;
		}
	}
	return 0;
}
