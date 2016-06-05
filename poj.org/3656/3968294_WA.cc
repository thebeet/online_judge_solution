#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Ans
{
	int pos, dis, count, length;
};

bool operator < (const Ans &a1, const Ans &a2)
{
	if (a1.count == a2.count)
	{
		if (a1.length == a2.length)
		{
			if (a1.pos == a2.pos)
			{
				return a1.dis > a2.dis;
			}
			return a1.pos < a2.pos;
		}
		return a1.length < a2.length;
	}
	return a1.count < a2.count;
}

void Go(const string &water, Ans &ans)
{
	ans.count = 0;
	for (int i = ans.pos; i < water.size(); i += ans.dis)
	{
		ans.length = i - ans.pos;
		if (water[i] == '.')
		{
			++ans.count;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	string inp;
	while ((cin >> inp), inp != "END")
	{
		Ans ans;
		ans.count = -1;
		for (int i = 0; i < inp.size(); ++i)
		{
			Ans tans;
			tans.pos = i;
			for (int j = 1; j < inp.size(); ++j)
			{
				tans.dis = j;
				Go(inp, tans);
				ans = max(ans, tans);
			}
		}
		cout << ans.pos << " " << ans.dis << endl;
	}
	return 0;
}
