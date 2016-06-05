/*
 * Wireless_Network.cpp
 *
 *  Created on: 2009-9-5
 *      Author: Administrator
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int xx[1024];
int yy[1024];

bool connect[1024][1024];
bool repaired[1024];

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

int main()
{
	int n, d;
	scanf("%d%d", &n, &d);
	memset(connect, false, sizeof(connect));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &xx[i], &yy[i]);
		for (int j = 0; j < i; ++j)
		{
			connect[i][j] = connect[j][i] = (((xx[i] - xx[j]) * (xx[i] - xx[j])) + ((yy[i] - yy[j]) * (yy[i] - yy[j])) <= d * d);
		}
	}
	memset(repaired, false, sizeof(repaired));
	char op[4];
	UnionSet us(n);
	while (scanf("%s", op) != EOF)
	{
		if (op[0] == 'O')
		{
			int a;
			scanf("%d", &a);
			--a;
			if (repaired[a] == true) continue;
			repaired[a] = true;
			for (int i = 0; i < n; ++i)
			{
				if ((connect[a][i]) && (repaired[i]))
				{
					us.Merge(i, a);
				}
			}
		}
		else
		{
			int a, b;
			scanf("%d%d", &a, &b);
			--a; --b;
			printf("%s\n", ((us.FindRoot(a) != us.FindRoot(b)) ? "FAIL" : "SUCCESS"));
		}
	}
	return 0;
}
