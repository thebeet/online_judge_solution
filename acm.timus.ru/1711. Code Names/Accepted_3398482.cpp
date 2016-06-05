#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

vector<string> inpq[1024];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		inpq[i].resize(3);
		for (int j = 0; j < 3; ++j)
		{
			cin >> inpq[i][j];
		}
		sort(inpq[i].begin(), inpq[i].end());
	}
	vector<string> ans;
	string c = "";
	for (int i = 0; i < n; ++i)
	{
		int d;
		cin >> d;
		--d;
		bool flag = false;
		for (int j = 0; j < 3; ++j)
		{
			if (c < inpq[d][j])
			{
				c = inpq[d][j];
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		ans.push_back(c);
	}
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}
	return 0;
}
