#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int height[32];

set<int> tset;

int main()
{
	int i, n, b;
	cin >> n >> b;
	tset.insert(0);
	for (i = 0; i < n; ++i)
	{
		cin >> height[i];
		for (set<int>::reverse_iterator it = tset.rbegin(); it != tset.rend(); ++it)
		{
			tset.insert(*it + height[i]);
		}
	}
	if (tset.find(b) != tset.end())
	{
		cout << 0 << endl;
	}
	else
	{
		tset.insert(b);
		set<int>::iterator it = tset.find(b);
		++it;
		cout << *it - b << endl;
	}
	
	return 0;
}
