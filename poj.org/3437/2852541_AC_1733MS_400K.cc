#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int st[65536];

int main()
{
	string inp;
	int ti(0);
	while ((cin >> inp), inp != "#")
	{
		int now(0), mh(0), mh2(0);
		st[0] = 0;
		for (unsigned int i = 0; i < inp.size(); ++i)
		{
			if (inp[i] == 'd')
			{
				++now;
				st[now] = st[now - 1];
			}
			else
			{
				--now;
			}
			++st[now];
			mh = max(mh, now);
			mh2 = max(mh2, st[now]);
		}
		cout << "Tree " << ++ti << ": " << mh << " => " << mh2 << endl;
	}
	return 0;
}
