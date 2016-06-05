#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	char st = 'a';
	string inp;
	cin >> inp;
	cout << string('a', '+');
	for (unsigned int i = 0; i < inp.size(); ++i)
	{
		if (inp[i] > st)
		{
			cout << string(inp[i] - st, '+');
		}
		else if (inp[i] < st)
		{
			cout << string(st - inp[i], '-');
		}
		cout << '.';
		st = inp[i];
	}
	cout << endl;
	return 0;
}
