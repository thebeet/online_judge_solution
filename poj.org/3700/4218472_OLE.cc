/*
 * Missile_Defence_System.cpp
 *
 *  Created on: 2008-10-14
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Hei
{
	int h;
	int pos;
	bool operator < (const Hei &hei) const
	{
		return (h < hei.h);
	}
};

int thei[64];
Hei hei[64];

struct Stat
{
	long long lo, hi;
	int mis;
	bool operator < (const Stat &st) const
	{
		return ((lo == st.lo) ? (hi < st.hi) : (lo < st.lo));
	}
};

const long long p = 1019;
const int MAXN = 100010;

int endslot;
int hashtable[p];
long long slot1[MAXN];
long long slot2[MAXN];
int next[MAXN];

void hash_init(void)
{
	memset(hashtable, 0, sizeof(hashtable));
	memset(next, 0, sizeof(int) * (endslot + 1));
	endslot = 0;
}

bool hash_find(long long d1, long long d2)
{
	int m = (int)(((d1 << 4)+ d2) % p);
	int pp = hashtable[m];
	while (pp != 0)
	{
		if ((slot1[pp] == d1) && (slot2[pp] == d2))
		{
			return false;
		}
		pp = next[pp];
	}
	slot1[++endslot] = d1;
	slot2[endslot] = d2;
	next[endslot] = hashtable[m];
	hashtable[m] = endslot;
	return true;
}

queue<Stat> q[2];

int main()
{
	int n;
	while ((cin >> n), n > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &hei[i].h);
			cin >> hei[i].h;
			//hei[i].h = (int)(sin(double(i * i + n)) * 10000);
			hei[i].pos = i;
		}
		sort(hei, hei + n);
		for (int i = 0; i < n; ++i)
		{
			thei[hei[i].pos] = i;
		}
		int ans;
		for (ans = 1; ; ++ans)
		{
			int p0(0), p1(1);
			while (q[0].empty() == false) q[0].pop();
			while (q[1].empty() == false) q[1].pop();
			Stat initstat;
			initstat.lo = 0;
			initstat.hi = 0;
			initstat.mis = 0;
			q[0].push(initstat);
			int i;
			for (i = 0; i < n; ++i)
			{
				if (q[p0].empty()) break;
				//hash.clear();
				hash_init();
				for ( ;q[p0].empty() == false; q[p0].pop())
				{
					Stat now = q[p0].front();
					long long d = now.lo >> thei[i];
					if (d > 0)
					{
						d = d & (d ^ (d - 1LL));
						now.lo ^= ((d + 1LL) << thei[i]);
						if (hash_find(now.lo, now.hi))
						{
							q[p1].push(now);
						}
					}
					else
					{
						if (++now.mis <= ans)
						{
							now.lo ^= (1LL << thei[i]);
							if (hash_find(now.lo, now.hi))
							{
								q[p1].push(now);
							}
						}
					}

					now = q[p0].front();
					d = now.hi & ((1LL << thei[i]) - 1);
					if (d)
					{
						int lo(0), hi(thei[i]);
						while (lo + 1 < hi)
						{
							int mid((lo + hi) >> 1);
							(((d >> mid) > 0) ? lo : hi) = mid;
						}
						now.hi ^= (1LL << lo);
						now.hi ^= (1LL << thei[i]);
						if (hash_find(now.lo, now.hi))
						{
							q[p1].push(now);
						}
					}
					else
					{
						if (++now.mis <= ans)
						{
							now.hi ^= (1LL << thei[i]);
							if (hash_find(now.lo, now.hi))
							{
								q[p1].push(now);
							}
						}
					}
				}
				swap(p0, p1);
			}
			if (q[p0].empty() == false)
			{
				break;
			}
			if (i == n - 1)
			{
				++ans;
				break;
			}
		}
		cout << ans << endl;
	}

}
