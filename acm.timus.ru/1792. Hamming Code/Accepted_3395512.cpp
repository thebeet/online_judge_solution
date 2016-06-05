#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class HammingCode
{
public:
	HammingCode()
	{
		memset(code, 0, sizeof(code));
	}
	void input()
	{
		for (int i = 0; i < 7; ++i)
		{
			cin >> code[i];
		}
	}
	bool vali() const
	{
		if (code[4] != (code[3] ^ code[2] ^ code[1])) return false;
		if (code[5] != (code[3] ^ code[0] ^ code[2])) return false;
		if (code[6] != (code[3] ^ code[1] ^ code[0])) return false;
		return true;
	}
	void output() const
	{
		for (int i = 0; i < 7; ++i)
		{
			cout << code[i] << " ";
		}
		cout << endl;
	}

	int code[7];
};

int main()
{
	HammingCode hc;
	hc.input();
	if (hc.vali())
	{
		hc.output();
	}
	else
	{
		for (int i = 0; i < 7; ++i)
		{
			hc.code[i] ^= 1;
			if (hc.vali())
			{
				hc.output();
				break;
			}
			hc.code[i] ^= 1;
		}
	}
	return 0;
}
