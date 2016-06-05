#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

class TreeArray
{
public:
	TreeArray(const int n)
	{
		 data = new int[n];
		 memset(data, 0, sizeof(int) * n);
		 size = n - 1;
	}
	~TreeArray()
	{
		 delete [] data;
	}
	void add(int k, int newdata)
	{
		while (k < size)
		{
			data[k] += newdata;
			k += lowbit(k);
		}
	}
	int getsum(int k) //get sum for 1 to k
	{
		int sum = 0;
		while (k > 0)
		{
			sum += data[k];
			k -= lowbit(k);
		}
		return sum;
	}
	int getsum(int f, int t) //get sum for f to t
	{
		return (getsum(t) - getsum(f - 1));
	}

private:
	int *data;
	int size;
	int lowbit(const int x)
	{
		return (x & (-x));
	}
};

struct Elem
{
	int m_key;
	int m_pos;
};

bool operator < (const Elem &a, const Elem &b)
{
	return a.m_key < b.m_key;
}

struct Query
{
	int m_f, m_t;
	int m_k;
	int m_id;
};

bool cmpstart(const Query &q1, const Query &q2)
{
	return q1.m_f < q2.m_f;
}

bool cmpend(const Query &q1, const Query &q2)
{
	return q1.m_t < q2.m_t;
}

Elem elems[100010];
Query querysstart[5010];
Query querysend[5010];

int startpos[5010];
int endpos[5010];
int ans[5010];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &elems[i].m_key);
		elems[i].m_pos = i;
	}
	sort(elems, elems + n);

	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &querysstart[i].m_f, &querysstart[i].m_t, &querysstart[i].m_k);
		--querysstart[i].m_f;
		--querysstart[i].m_t;
		querysstart[i].m_id = i;
	}
/*	memcpy(querysend, querysstart, sizeof(Query) * m);
	sort(querysstart, querysstart + m, cmpstart);
	sort(querysend, querysend + m, cmpend);
	for (int i = 0; i < m; ++i)
	{
		startpos[querysstart[i].m_id] = i;
		endpos[querysend[i].m_id] = i;
	}
*/
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if ((querysstart[j].m_f <= elems[i].m_pos) && (querysstart[j].m_t >= elems[i].m_pos))
			{
				if (--querysstart[j].m_k == 0)
				{
					ans[j] = elems[i].m_key;
				}
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		cout << ans[i] << endl;
	}

	return 0;
}
;
