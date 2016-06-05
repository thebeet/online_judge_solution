#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int n;

struct books
{
	char bs[16];
};
bool operator < (const books &b1, const books &b2)
{
	return (memcmp(b1.bs, b2.bs, 16) < 0);
}
bool operator == (const books &b1, const books &b2)
{
	return (memcmp(b1.bs, b2.bs, 16) == 0);
}

void transport(books &dest, books &sour, int i, int j, int r, int m)
{
	++j;
	if (m == 0)
	{
		memcpy(dest.bs, sour.bs, 16);
		memcpy(&dest.bs[0], &sour.bs[0], i);
		memcpy(&dest.bs[r - j + i], &sour.bs[i], j - i);
		memcpy(&dest.bs[i], &sour.bs[j], r - j);
	}
	else
	{
		memcpy(dest.bs, sour.bs, 16);
		memcpy(&dest.bs[j - i], &sour.bs[0], i);
		memcpy(&dest.bs[0], &sour.bs[i], j - i);
		memcpy(&dest.bs[j], &sour.bs[j], r - j);
	}
}

books inp, normal;

books ft[4096];
books ft2[4096];

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, j, k, k2, m, r, ki;
		int ans = 0;
		cin >> n;
		map<books, bool> hash;
		map<books, bool> hash2;
		hash.clear();
		hash2.clear();
		memset(&inp, 0, sizeof(books));
		memset(&normal, 0, sizeof(books));
		memset(ft, 0, sizeof(ft));
		memset(ft2, 0, sizeof(ft2));
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &inp.bs[i]);
			normal.bs[i] = i + 1;
		}
		if (inp == normal)
		{
			goto output;
		}
		else
		{
			k = 0;
			ans = 1;
			for (i = 0; i < n; ++i)
			{
				for (j = i; j < n; ++j)
				{
					for (r = j + 1; r <= n; ++r)
					{
						for (m = 0; m < 2; ++m)
						{
							transport(ft[++k], inp, i, j, r, m);
							/*
							for (int u = 0; u < n; ++u)
							{
								cout << (int)ft[k].bs[u] << " ";
							}
							cout << endl;
							//*/
							if (ft[k] == normal)
							{
								goto output;
							}
							hash[ft[k]] = true;
						}
					}
				}
			}
			ans = 2;
			k2 = 0;
			for (i = 0; i < n; ++i)
			{
				for (j = i; j < n; ++j)
				{
					for (r = j + 1; r <= n; ++r)
					{
						for (m = 0; m < 2; ++m)
						{
							transport(ft2[++k2], normal, i, j, r, m);
							if (hash[ft2[k2]])
							{
								goto output;
							}
						}
					}
				}
			}
			ans = 3;
			for (ki = 1; ki <= k2; ++ki)
			{
				for (i = 0; i < n; ++i)
				{
					for (j = i; j < n; ++j)
					{
						for (r = j + 1; r <= n; ++r)
						{
							for (m = 0; m < 2; ++m)
							{
								books newbook;
								transport(newbook, ft2[ki], i, j, r, m);
								if (hash[newbook])
								{
									goto output;
								}
								hash2[newbook] = true;
							}
						}
					}
				}
			}
			ans = 4;
			for (ki = 1; ki <= k; ++ki)
			{
				for (i = 0; i < n; ++i)
				{
					for (j = i; j < n; ++j)
					{
						for (r = j + 1; r <= n; ++r)
						{
							for (m = 0; m < 2; ++m)
							{
								books newbook;
								transport(newbook, ft[ki], i, j, r, m);
								if (hash2[newbook])
								{
									goto output;
								}
							}
						}
					}
				}
			}
		}
		cout << "5 or more" << endl;
		continue;
	output:	cout << ans << endl;
	}
	return 0;
}
