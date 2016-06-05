/*
 * USTC_1::Constellations.cpp
 *
 *  Created on: Sep 29, 2008 2:13:48 PM
 *      Author: TheBeet
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU Affero General Public License as
 *	published by the Free Software Foundation, either version 3 of the
 *	License, or (at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU Affero General Public License for more details.
 *
 *	You should have received a copy of the GNU Affero General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long INT;

const int MAX(1024);

int n, m;
char base_map[1024][1024];
INT dmap[1024][1024];
INT msum[1024][1024];
//INT masum[1024][1024];

int a, b;
char smap[128][64][64];
INT dsmap[128][64];
INT mssum[128];
//INT massum[128];

bool check(const int x, const int y, const int p)
{
	for (int i = 0; i < a; ++i)
	{
		if (dmap[i + x][y] != dsmap[p][i])
		{
			return false;
		}
	}
	return true;
}

const int p = 10019;
const int MAXN = 128;



int hashtable[p];

int endslot = 0;
int slot[MAXN];
int data[MAXN];
int next[MAXN];

void hash_insert(int d, int k)
{
	int m = d % p;
	++endslot;
	slot[endslot] = d;
	data[endslot] = k;
	next[endslot] = hashtable[m];
	hashtable[m] = endslot;
}

bool hash_find(int d, int i, int j)
{
	int m = d % p;
	int *pre = &hashtable[m];
	int pp = hashtable[m];
	while (pp != 0)
	{
		if (slot[pp] == d)
		{
			if (check(i - a + 1, j , data[pp]))
			{
				*pre = next[pp];
				return true;
			}
		}
		pp = next[pp];
	}
	return false;
}
/*
3 6 1 3 2
*00*00
000000
00*000

00
00
00
 */

map< INT, vector< int > > thash;

void debugout(INT mm[MAX][MAX], int n, int m, char * name)
{
	cout << name << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << mm[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int caseid(0);
	while (scanf("%d%d", &n, &m), n > 0)
	{
		printf("Case %d: ", ++caseid);
		int t;
		scanf("%d%d%d", &t, &a, &b);
		long long mask((1LL << b) - 1LL);
		//memset(dmap, 0, sizeof(dmap));
		memset(dsmap, 0, sizeof(dsmap));
		//memset(msum, 0, sizeof(msum));
		memset(mssum, 0, sizeof(mssum));
		//memset(masum, 0, sizeof(masum));
		//memset(massum, 0, sizeof(massum));


		for (int i = 1; i <= n; ++i)
		{
			scanf("%s", base_map[i] + 1);
			for (int j = 1; j <= m; ++j)
			{
				dmap[i][j] = ((dmap[i][j - 1] << 1) + (INT)((base_map[i][j] == '*') ? 1 : 0)) & mask;
				msum[i][j] = msum[i - 1][j] + dmap[i][j];
				//masum[i][j] = masum[i - 1][j] + msum[i][j];
				if (i > a)
				{
					msum[i][j] -= dmap[i - a][j];
					//masum[i][j] -= dmap[i - a][j] * (INT)(a + 1);
				}
			}
		}
		for (int k = 0; k < t; ++k)
		{
			for (int i = 0; i < a; ++i)
			{
				scanf("%s", smap[k][i]);
				for (int j = 0; j < b; ++j)
				{
					(dsmap[k][i] <<= 1) += (INT)((smap[k][i][j] == '*') ? 1 : 0);
				}
				mssum[k] += dsmap[k][i];
				//massum[k] += mssum[k];
			}
			//thash[mssum[k]].push_back(k);
			hash_insert(mssum[k], k);
		}
		int ans(0);
		for (int i = a; i <= n; ++i)
		{
			for (int j = b; j <= m; ++j)
			{
				if (hash_find(msum[i][j], i, j))
				{
					++ans;
				}
				/*
				map<INT, vector<int> >::iterator fit = thash.find(msum[i][j]);
				if (fit != thash.end())
				{
					for (vector<int>::iterator it = fit->second.begin(); it != fit->second.end(); ++it)
					{
						if (check(i - a + 1, j , *it))
						{
							++ans;
							fit->second.erase(it);
						}
					}
					if (fit->second.size() == 0)
					{
						thash.erase(fit);
					}
				}
				*/
				/*
				for (int k = 0; k < t; ++k)
				{
					if (ok[k]) continue;
					if ((masum[i][j] == massum[k]) && (msum[i][j] == mssum[k]) && (check(i - a + 1, j, k)))
					{
						++ans;
						ok[k] = true;
					}
				}*/
			}
		}
		cout << ans << endl;
	}
	return 0;
}
