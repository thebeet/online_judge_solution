#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int main()
{
	int n;
	cin >> n;
	int ans(0);
	for (int i = 0; i < n; ++i)
	{
		string name, result;
		cin >> name >> result;
		if (result == "AC")
		{
			++ans;
		}
		else if (result == "CE")
		{
		}
		else
		{
			int casenum;
			cin >> casenum;
			if (casenum >= 6)
			{
				++ans;
			}
		}
	}
	cout << 0 << " " << ans << endl;
	return 0;
}
