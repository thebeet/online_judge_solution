/*
 * PKU3419::Difference_Is_Beautiful.cpp
 *
 *  Created on: Oct 30, 2008 8:49:07 PM
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

using namespace std;

class RMQ
{
public:
	RMQ(const int n = 262144 * 2) :
		m_n(n)
	{
		m_data = new int[m_n * 2];
		Clear();
	}
	~RMQ(void)
	{
		delete [] m_data;
	}

	void Clear(void)
	{
		memset(m_data, -1, sizeof(int) * m_n * 2);
	}

	int &operator [] (const int pos)
	{
		return m_data[m_n + pos];
	}
	const int &operator [] (const int pos) const
	{
		return m_data[m_n + pos];
	}

	void Init(void)
	{
		for (int i = m_n - 1; i >= 1; --i)
		{
			m_data[i] = max(m_data[i << 1], m_data[(i << 1) + 1]);
		}
	}

	int findmax(const int st, const int ed) const
	{
		int s(st + m_n);
		int e(ed + m_n);
		int ans(-1);
		while (s < e)
		{
			if ((s & 1) == 1)
			{
				ans = max(ans, m_data[s]);
				++s;
			}
			s >>= 1;
			if ((e & 1) == 0)
			{
				ans = max(ans, m_data[e]);
				--e;
			}
			e >>= 1;
		}
		if (s == e)
		{
			ans = max(ans, m_data[s]);
		}
		return ans;
	}

	int *m_data;
	int m_n;
};

RMQ rmq;
bool hash[1024 * 1024];
int arr[200010];
int ed[200010];

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(hash, false, sizeof(hash));
		rmq.Clear();
		int pre(-1);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &arr[i]);
			while (hash[arr[i]])
			{
				hash[arr[++pre]] = false;
				ed[pre] = i;
				rmq[pre] = ed[pre] - pre;
			}
			hash[arr[i]] = true;
		}
		while (++pre < n)
		{
			ed[pre] = n;
			rmq[pre] = ed[pre] - pre;
		}
		ed[n] = n + n;
		rmq.Init();
		for (int i = 0; i < m; ++i)
		{
			int ss, ee;
			scanf("%d%d", &ss, &ee);
			if (ed[ss] > ee)
			{
				printf("%d\n", ee - ss + 1);
			}
			else
			{
				int lo(ss), hi(n);
				while (lo + 1 < hi)
				{
					int mid((lo + hi) / 2);
					((ed[mid] > ee) ? hi : lo) = mid;
				}
				if (hi == n)
				{
					cout << rmq.findmax(ss, lo) << endl;
				}
				else
				{
					cout << max(rmq.findmax(ss, lo), ee - hi + 1) << endl;
				}
			}
		}
	}
	return 0;
}
