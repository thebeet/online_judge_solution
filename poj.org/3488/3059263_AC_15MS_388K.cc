#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> inp;

int main()
{
	int i, n;
	int ti(0);
	while (cin >> n)
	{
		++ti;
		if (ti > 1)
		{
			cout << endl;
		}
		inp.clear();
		string str;
		for (i = 0; i < n; ++i)
		{
			cin >> str;
			inp.push_back(str);
		}
		int spc(0);
		for (int j = str.size() - 1; j >= 0; --j)
		{
			for (i = n - 1; i >= 0; --i)
			{
				if (inp[i][j] == '_')
				{
					++spc;
				}
				else if (inp[i][j] == '\\')
				{
					for (int sp = 0; sp < spc; ++sp)
					{
						cout << ' ';
					}
					spc = 0;
					cout << endl; 
				}
				else
				{
					for (int sp = 0; sp < spc; ++sp)
					{
						cout << ' ';
					}
					spc = 0;
					cout << inp[i][j];
				}
			}
		}
		cout << endl;
	}
	
	return 0;
}
