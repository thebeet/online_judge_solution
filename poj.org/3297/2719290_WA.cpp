#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> vote;
struct book
{
	string name;
	int s;
}books[256];

bool operator < (const book &b1, const book &b2)
{
	if (b1.s == b2.s)
	{
		return (b1.name < b2.name);
	}
	return (b1.s > b2.s);
}

string people;
char buf[256];

int main()
{
	int i, n;
	gets(buf);
	while (buf[0] != '0')
	{
		n = 0;
		while (buf[0] != '1')
		{
			books[++n].name = buf;
			books[n].s = 0;
			for (;;)
			{
				gets(buf);
				if (buf[0] < 'a')
				{
					break;
				}
				people = buf;
				int ret = vote[people];
				if (ret == 0)
				{
					vote[people] = n;
					++books[n].s;
				}
				else if ((ret > 0) && (ret != n))
				{
					vote[people] = -1;
					--books[ret].s;
				}
			}
		}
		sort(books + 1, books + 1 + n);
		for (i = 1; i <= n; ++i)
		{
			cout << books[i].name << " " << books[i].s << endl;
		}
		gets(buf);
	}
	return 0;
}
