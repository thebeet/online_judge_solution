/*
 * Feel_Good.cpp
 *
 *  Created on: 2009-9-19
 *      Author: Administrator
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

class UnionSet
{
public:
	UnionSet(const int n) :
		m_size(n)
	{
		m_father = new int[n];
		Clear();
	}
	~UnionSet()
	{
		delete [] m_father;
	}

	int FindRoot(const int p)
	{
		if (m_father[p] != p)
		{
			m_father[p] = FindRoot(m_father[p]);
		}
		return m_father[p];
	}

	void Clear()
	{
		for (int i = 0; i < m_size; ++i)
		{
			m_father[i] = i;
		}
	}

	void Merge(const int p1, const int p2)
	{
		int f1 = FindRoot(p1);
		int f2 = FindRoot(p2);
		m_father[f1] = f2;
	}

private:
	int m_size;
	int *m_father;
};

int arr[100010];
struct Inp
{
	int val;
	int pos;
};

int tleft[100010];
int tright[100010];

bool operator < (const Inp &inp1, const Inp &inp2)
{
	return (inp1.val > inp2.val);
}

Inp inp[100010];
long long sum[100010];

int main()
{
	int n;
	scanf("%d", &n);
	sum[0] = 0LL;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &arr[i]);
		sum[i] = sum[i - 1] + (long long)arr[i];
		inp[i].pos = i;
		inp[i].val = arr[i];
		tleft[i] = i - 1;
		tright[i] = i + 1;
	}
	sort(inp + 1, inp + n + 1);
	UnionSet us(n + 1);
	long long best(-1);
	int lo, hi;
	for (int i = 1; i <= n; ++i)
	{
		int p = inp[i].pos;
		int val = inp[i].val;
		int j = tleft[us.FindRoot(p)];
		while (j >= 1)
		{
			if (arr[j] >= val)
			{
				int oldleft = min(tleft[us.FindRoot(j)], tleft[us.FindRoot(p)]);
				int oldright = max(tright[us.FindRoot(j)], tright[us.FindRoot(p)]);
				us.Merge(p, j);
				j = tleft[us.FindRoot(p)] = oldleft;
				tright[us.FindRoot(p)] = oldright;
			}
			else
			{
				break;
			}
		}
		j = tright[us.FindRoot(p)];
		while (j <= n)
		{
			if (arr[j] >= val)
			{
				int oldleft = min(tleft[us.FindRoot(j)], tleft[us.FindRoot(p)]);
				int oldright = max(tright[us.FindRoot(j)], tright[us.FindRoot(p)]);
				us.Merge(p, j);
				tleft[us.FindRoot(p)] = oldleft;
				j = tright[us.FindRoot(p)] = oldright;
			}
			else
			{
				break;
			}
		}
		long long tbest = (sum[tright[us.FindRoot(p)] - 1] - sum[tleft[us.FindRoot(p)]]) * (long long)val;
		if (tbest > best)
		{
			best = tbest;
			lo = tleft[us.FindRoot(p)] + 1;
			hi = tright[us.FindRoot(p)] - 1;
		}
	}
	cout << best << endl << lo << " " << hi << endl;
	return 0;
}
