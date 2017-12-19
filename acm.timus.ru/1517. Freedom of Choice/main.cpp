/*
 * sa.cpp
 *
 *  Created on: 2011-11-13
 *      Author: acer
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

template <typename T = int>
class RMQ
{
public:
	RMQ(const std::vector<T> &array) :
		orig_array(array)
	{
		m_extend_size = 1;
		for (; m_extend_size < orig_array.size(); m_extend_size <<= 1)
		{
		}
		rmq_extend_array.resize(m_extend_size * 2, -1);
		for (unsigned int i = m_extend_size; i < m_extend_size + array.size(); ++i)
		{
			rmq_extend_array[i] = i - m_extend_size;
		}
		for (unsigned int i = m_extend_size - 1; i > 0; --i)
		{
			rmq_extend_array[i] = minPos((i << 1), (i << 1) + 1);
		}
	}

	int findminPos(const int start, const int end) const
	{
		int posstart(start + m_extend_size);
		int posend(end + m_extend_size);
		if (posstart > posend) std::swap(posstart, posend);
		int ans(start);
		while (posstart <= posend)
		{
			ans = minPos(ans + m_extend_size, minPos(posstart, posend) + m_extend_size);
			if (posstart == posend) break;
			(posstart += 1) >>= 1;
			(posend -= 1) >>= 1;
		}
		return ans;
	}

private:
	int minPos(const int p1, const int p2) const
	{
		if (rmq_extend_array[p1] == -1) return rmq_extend_array[p2];
		if (rmq_extend_array[p2] == -1) return rmq_extend_array[p1];

		if (orig_array[rmq_extend_array[p1]] < orig_array[rmq_extend_array[p2]]) return rmq_extend_array[p1];
		else return rmq_extend_array[p2];
	}

	unsigned int m_extend_size;
	const std::vector<T> &orig_array;
	std::vector<int> rmq_extend_array;
};

class SuffixArray
{
public:
	SuffixArray(const std::string &str) :
		m_orig_string(str), m_height_rmq(NULL)
	{
	}

	virtual ~SuffixArray()
	{
		if (m_height_rmq != NULL)
		{
			delete m_height_rmq;
		}
	}

	void Doubling()
	{
		const int n = m_orig_string.size();
		m_suffixarray.resize(n, 0);
		m_rank.resize(n, 0);
		{
			std::vector<int> sum(256, 0);
			std::vector<int> use(256, 0);
			for (int i = 0; i < n; ++i)
			{
				++sum[(int)m_orig_string[i]];
			}
			for (int i = 1; i < 256; ++i)
			{
				sum[i] += sum[i - 1];
			}


			for (int i = 0; i < n; ++i)
			{
				m_suffixarray[i] = sum[(int)m_orig_string[i] - 1] + use[(int)m_orig_string[i] - 1];
				++use[(unsigned int)m_orig_string[i] - 1];
			}


			for (int i = 0; i < n; ++i)
			{
				m_rank[i] = sum[(int)m_orig_string[i] - 1];
			}
		}

		int k = 1;
		while (k < n)
		{
			Comp comp(m_rank, k);
			std::sort(m_suffixarray.begin(), m_suffixarray.end(), comp);

			std::vector<int> newrank(n);
			newrank[m_suffixarray[0]] = 0;
			for (int i = 1; i < n; ++i)
			{
				if (comp.operator()(m_suffixarray[i - 1], m_suffixarray[i]) == false)
				{
					newrank[m_suffixarray[i]] = newrank[m_suffixarray[i - 1]];
				}
				else
				{
					newrank[m_suffixarray[i]] = i;
				}

			}
			m_rank = newrank;
			k *= 2;
		}
	}

	void LCPinit()
	{
		const int n = m_orig_string.size();
		m_height.resize(n);
		std::vector<int> h(n);
		for (int i = 0; i < n; ++i)
		{
			if (m_rank[i] == 0)
			{
				h[i] = 0;
				m_height[m_rank[i]] = h[i];
				continue;
			}
			int startpos = 0;
			if ((i == 0) || (h[i - 1] <= 1))
			{
				startpos = 0;
			}
			else
			{
				startpos = h[i - 1] - 1;
			}
			int j = startpos;
			for ( ; ; ++j)
			{
				if ((m_suffixarray[m_rank[i] - 1] + j >= n) || (m_suffixarray[m_rank[i] - 1] + j >= n) ||
						(m_orig_string[m_suffixarray[m_rank[i] - 1] + j] != m_orig_string[m_suffixarray[m_rank[i]] + j]))
				{
					break;
				}
			}
			h[i] = j;
			m_height[m_rank[i]] = h[i];
		}

		//m_height_rmq = new RMQ<int>(m_height);
	}

	string findmax(const int n1, const int n2) const
	{
		int n = m_orig_string.size();
		int ans(0);
        int p(0);
		for (int i = 1; i < n; ++i)
		{
			if (((m_suffixarray[i] < n1) && (m_suffixarray[i - 1] > n1)) ||
					((m_suffixarray[i] > n1) && (m_suffixarray[i - 1] < n1)))
			{
				if (ans < m_height[i])
				{
					ans = m_height[i];
                    p = i;
				}
			}
		}
		return m_orig_string.substr(m_suffixarray[p], ans);
	}

	int LCP(const int i, const int j)
	{
		if (i > j) return LCP(j, i);
		const int n = m_orig_string.size();
		if (i == j) return n - m_suffixarray[i] + 1;
		return m_height_rmq->findminPos(i, j);
	}

protected:

	class Comp : public std::less<int>
	{
	public:
		Comp(const vector<int> &rank, const int k) :
			m_rank(rank), m_k(k)
		{
		}

		bool operator()(const int &x, const int &y) const
		{
			if (m_rank[x] == m_rank[y])
			{
				if (x + m_k >= m_rank.size())
				{
					return true;
				}
				if (y + m_k >= m_rank.size())
				{
					return false;
				}
				return m_rank[x + m_k] < m_rank[y + m_k];
			}
			return m_rank[x] < m_rank[y];
		}

	private:
		const vector<int> &m_rank;
		const int m_k;
	};

	std::vector<int> m_suffixarray;
	std::vector<int> m_rank;

	std::vector<int> m_height;
	const RMQ<int> *m_height_rmq;

	const std::string &m_orig_string;
};

int main()
{
    int n;
    cin >> n;
	std::string str1, str2;
	cin >> str1;
	cin >> str2;
	std::string strconnect = str1 + "$" + str2;
	SuffixArray sa(strconnect);
	sa.Doubling();
	sa.LCPinit();
	cout << sa.findmax(str1.size(), str2.size()) << endl;
	return 0;
}

