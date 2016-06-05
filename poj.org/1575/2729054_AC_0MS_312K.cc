#include <iostream>
#include <string>

using namespace std;

string inp;

inline bool isvowel(char ch)
{
	return ((ch == 'a') || (ch == 'e') || (ch == 'o') || (ch == 'u') || (ch == 'i'));
}

int main()
{
	while ((cin >> inp), inp != "end")
	{
		cout << '<' << inp << "> is ";
		unsigned int i;
		for (i = 0; i < inp.size(); ++i)
		{
			if (isvowel(inp[i]))
			{
				break;
			}
		}
		if (i == inp.size())
		{
			cout << "not acceptable." << endl;
			continue;
		}
		for (i = 0; i < inp.size(); ++i)
		{
			if ((i + 2 < inp.size()) &&
			    ((isvowel(inp[i]) && isvowel(inp[i + 1]) && isvowel(inp[i + 2])) ||
			     ((isvowel(inp[i]) || isvowel(inp[i + 1]) || isvowel(inp[i + 2])) == false)))
			{
				break;
			}
		}
		if (i < inp.size())
		{
			cout << "not acceptable." << endl;
			continue;
		}
		for (i = 1; i < inp.size(); ++i)
		{
			if ((inp[i] == inp[i - 1]) && (inp[i] != 'e') && (inp[i] != 'o'))
			{
				break;
			}
		}
		if (i < inp.size())
		{
			cout << "not acceptable." << endl;
			continue;
		}
		cout << "acceptable." << endl;
	}
	return 0;
}
