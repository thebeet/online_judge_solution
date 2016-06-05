#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int p = 1000007;

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
	return (memcmp(&b1, &b2, sizeof(books)) == 0);
}

int hashtable[p];

int endslot;
books slot[16406];
int next[16406];

void hash_insert(const books &b)
{
	int m(0);
	for (int i = 0; i < n; ++i)
	{
		(m += b.bs[i] * b.bs[i] * b.bs[i] * (i + 1) * (i + 1)) %= p;
	}
	slot[++endslot] = b;
	next[endslot] = hashtable[m];
	hashtable[m] = endslot;
}

bool hash_find(const books &b)
{
	int m(0);
	for (int i = 0; i < n; ++i)
	{
		(m += b.bs[i] * b.bs[i] * b.bs[i] * (i + 1) * (i + 1)) %= p;
	}
	int pp = hashtable[m];
	while (pp != 0)
	{
		if (slot[pp] == b)
		{	
			return true;
		}
		pp = next[pp];
	}
	return false;
}		


int hashtable2[p];

int endslot2;
books slot2[416406];
int next2[416406];

void hash_insert2( const books &b)
{
	int m(0);
	for (int i = 0; i < n; ++i)
	{
		(m += b.bs[i] * b.bs[i] * b.bs[i] * (i + 1)) %= p;
	}
	slot2[++endslot2] = b;
	next2[endslot2] = hashtable2[m];
	hashtable2[m] = endslot2;
}

bool hash_find2(const books &b)
{
	int m(0);
	for (int i = 0; i < n; ++i)
	{
		(m += b.bs[i] * b.bs[i] * b.bs[i] * (i + 1)) %= p;
	}
	int pp = hashtable2[m];
	while (pp != 0)
	{
		if (slot2[pp] == b)
		{	
			return true;
		}
		pp = next2[pp];
	}
	return false;
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

books ft[40960];
books ft2[40960];

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, j, k, k2, m, r, ki, st, ed;
		int ans = 0;
		cin >> n;
		
		memset(hashtable, 0, sizeof(hashtable));
		memset(hashtable2, 0, sizeof(hashtable2));
		memset(next, 0, sizeof(next));
		memset(next2, 0, sizeof(next2));
		endslot = 0;
		endslot2 = 0;
		
		memset(&inp, 0, sizeof(books));
		memset(&normal, 0, sizeof(books));
		memset(ft, 0, sizeof(ft));
		memset(ft2, 0, sizeof(ft2));
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &inp.bs[i]);
			normal.bs[i] = i + 1;
		}
		st = 0;
		ed = n;
/*		while ((normal.bs[st] == inp.bs[st]) && (st < ed))
		{
			++st;
		}
		while ((normal.bs[ed - 1] == inp.bs[ed - 1]) && (st < ed))
		{
			--ed;
		}*/
		if (inp == normal)
		{
			goto output;
		}
		else
		{
			k = 0;
			ans = 1;
			for (i = st; i < ed; ++i)
			{
				for (j = i; j < ed; ++j)
				{
					for (r = j + 1; r <= ed; ++r)
					{
						for (m = 0; m < 2; ++m)
						{
							transport(ft[++k], inp, i, j, r, m);
							if (ft[k] == normal)
							{
								goto output;
							}
							hash_insert(ft[k]);
						}
					}
				}
			}
			ans = 2;
			k2 = 0;
			for (i = st; i < ed; ++i)
			{
				for (j = i; j < ed; ++j)
				{
					for (r = j + 1; r <= ed; ++r)
					{
						for (m = 0; m < 2; ++m)
						{
							transport(ft2[++k2], normal, i, j, r, m);
							if (hash_find(ft2[k2]))
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
				for (i = st; i < ed; ++i)
				{
					for (j = i; j < ed; ++j)
					{
						for (r = j + 1; r <= ed; ++r)
						{
							for (m = 0; m < 2; ++m)
							{
								books newbook;
								transport(newbook, ft2[ki], i, j, r, m);
								if (hash_find(newbook))
								{
									goto output;
								}
								hash_insert2(newbook);
							}
						}
					}
				}
			}
			ans = 4;
			for (ki = 1; ki <= k; ++ki)
			{
				for (i = st; i < ed; ++i)
				{
					for (j = i; j < ed; ++j)
					{
						for (r = j + 1; r <= ed; ++r)
						{
							for (m = 0; m < 2; ++m)
							{
								books newbook;
								transport(newbook, ft[ki], i, j, r, m);
								//cout << i << " " << j << " " << r << " " << m << endl;
								if (hash_find2(newbook))
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
