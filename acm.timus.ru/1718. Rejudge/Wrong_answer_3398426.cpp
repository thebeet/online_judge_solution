#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
int main()
{
	int n;
	cin >> n;
	int ans(0);
	set<string> auth;
	for (int i = 0; i < n; ++i)
	{
		string name, result;
		cin >> name >> result;
		if (result == "AC")
		{
			auth.insert(name);
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
				auth.insert(name);
			}
		}
	}
	cout << 0 << " " << auth.size() << endl;
	return 0;
}
