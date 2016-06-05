#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
string hun[16] =
{
		"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
};
string ten[16] =
{
		"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"
};
string one[16] =
{
		"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
};

class roman
{
	friend ostream &operator << (ostream &out, const roman &r1)
	{
		if (r1.num == 0)
		{
			return (out << 'O'); 
		}
		for (int i = 1000; i <= r1.num; i += 1000)
		{
			out << 'M';
		}
		return (out << hun[(r1.num % 1000) / 100] << ten[(r1.num % 100) / 10] << one[r1.num % 10]); 
	}
public:
	roman(const int n = 0) :
		num(n)
	{
	}
	roman(const string &inp)
	{
		num = 0;
		for (unsigned int i = 0; i < inp.size(); ++i)
		{
			int n = translate(inp[i]);
			if ((translate(inp[i + 1]) > n))
			{
				num += translate(inp[++i]) - n;
			}
			else
			{
				num += n;
			}
		}
	}
	~roman(){};
	
	int num;
private:
	int translate(const char c) const
	{
		switch (c)
		{
		case 'O':
			return 0;
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return -1;
		}
	}
};

int main()
{
	string inp;
	roman reg[16];
	while ((cin >> inp), (inp != "QUIT"))
	{
		if (inp == "RESET")
		{
			for (int i = 0; i < 10; ++i)
			{
				reg[i] = -1;
			}
			cout << "Ready" << endl;
		}
		else
		{
			bool errorflag = false;
			int sum = 0;
			int st = 2;
			int op = 1;
			while ((st < inp.size()) && (inp[st] > 20))
			{
				unsigned int i;
				for (i = st; i < inp.size(); ++i)
				{
					if (inp[i] < '0')
					{
						break;
					}
				}
				if (inp[st] < 'A')
				{
					if (reg[inp[st] - '0'].num >= 0)
					{
						sum += (op * reg[inp[st] - '0'].num);
					}
					else
					{
						errorflag = true;
						break;
					}
				}
				else
				{
					roman newnum(inp.substr(st, i - st));
					sum += (op * newnum.num);
				}
				op = ((inp[i] == '-') ? -1 : 1);
				st = i + 1;
			}
			if ((sum < 0) || (sum > 10000) || (errorflag))
			{
				cout << "Error" << endl;
			}
			else
			{
				reg[inp[0] - '0'] = sum;
				cout << inp[0] << '=' << reg[inp[0] - '0'] << endl;
			}
		}
	}
	cout << "Bye" << endl;
	return 0;
}
