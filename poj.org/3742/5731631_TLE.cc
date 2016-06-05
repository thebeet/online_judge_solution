/*
 * PKU3742::Equivalent_Polynomial.cpp
 *
 *  Created on: Aug 23, 2009 1:29:09 PM
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
#include <string>

using namespace std;

//#define UNSIGNED_
//#ifndef LOOONG_H_
#define LOOONG_H_

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>


template <typename T_INT = int, int BASE = 10, int W = 3, typename _Alloc = std::allocator<T_INT> >
class Looong
{
	friend std::istream &operator >> (std::istream &in, Looong &d)
	{
		std::string inp;
		if (in >> inp)
		{
			d.Convert(inp);
		}
		return in;
	}
	friend std::ostream &operator << (std::ostream &out, const Looong &d)
	{
		return d.Output(out);
	}
	friend bool operator < (const Looong &d1, const Looong &d2)
	{
		return (Compare(d1, d2) == -1);
	}
	friend bool operator <= (const Looong &d1, const Looong &d2)
	{
		return (Compare(d1, d2) <= 0);
	}
	friend bool operator > (const Looong &d1, const Looong &d2)
	{
		return (Compare(d1, d2) == 1);
	}
	friend bool operator >= (const Looong &d1, const Looong &d2)
	{
		return (Compare(d1, d2) >= 0);
	}
	friend bool operator == (const Looong &d1, const Looong &d2)
	{
		return (Compare(d1, d2) == 0);
	}
	friend bool operator != (const Looong &d1, const Looong &d2)
	{
		return (Compare(d1, d2) != 0);
	}
	friend Looong operator + (const Looong &d1, const Looong &d2)
	{
		Looong d3(d1);
		d3 += d2;
		return d3;
	}
	friend Looong operator - (const Looong &d1, const Looong &d2)
	{
		Looong d3(d1);
		d3 -= d2;
		return d3;
	}
	friend Looong operator * (const Looong &d1, const Looong &d2)
	{
		Looong d3;
		d3.ab_multiply_part(d1, d2);
		d3.m_op = d1.m_op ^ d2.m_op;
		d3.Check_NegativeZero();
		return d3;
	}
	friend Looong operator / (const Looong &d1, const Looong &d2)
	{
		Looong d3;
		d3.ab_divid(d1, d2);
		d3.m_op = d1.m_op ^ d2.m_op;
		d3.Check_NegativeZero();
		return d3;
	}
	friend Looong operator / (const Looong &d1, const T_INT d2)
	{
		Looong ret(d1);
		ret /= d2;
		return ret;
	}
	friend Looong operator % (const Looong &d1, const Looong &d2)
	{
		return d1 - (d1 / d2) * d2;
	}
	friend T_INT operator % (const Looong &d1, const T_INT d2)
	{
		T_INT ret(0);
		for (int i = d1.Size() - 1; i >=0; --i)
		{
			ret = ((ret * d1.m_step) + d1.m_data[i]) % d2;
		}
		return ret * (d1.m_op ? -1 : 1);
	}

public:
	Looong(const T_INT n = T_INT())
	{
		Init();
		T_INT t_n;
		if (n < 0)
		{
			m_op = true;
			t_n = -n;
		}
		else
		{
			t_n = n;
		}
		while (t_n > 0)
		{
			m_data.push_back(t_n % m_step);
			t_n /= m_step;
		}
	}
	Looong(const std::string &str)
	{
		this->Convert(str);
	}
	~Looong(void)
	{
	}
	unsigned int Size(void) const
	{
		return m_data.size();
	}
	T_INT &operator [](const unsigned int pos)
	{
		/*if (pos >= m_data.size())
		{
			m_data.resize(pos + 1);
		}*/
		return m_data[pos];
	}
	const T_INT &operator [](const unsigned int pos) const
	{
		assert(pos < m_data.size());
		return m_data[pos];
	}

	Looong &operator <<= (const unsigned int offset)
	{
		m_data.insert(m_data.begin(), offset, 0);
		return *this;
	}
	Looong &operator >>= (const unsigned int offset)
	{
		if (offset >= Size())
		{
			Init();
		}
		else
		{
			m_data.erase(m_data.begin(), m_data.begin() + offset);
		}
		return *this;
	}
	Looong operator << (const unsigned int offset) const
	{
		Looong ret(*this);
		ret <<= offset;
		return ret;
	}
	Looong operator >> (const unsigned int offset) const
	{
		Looong ret(*this);
		ret >>= offset;
		return ret;
	}
	Looong &Negative(void)
	{
		m_op = !m_op;
		Check_NegativeZero();
		return *this;
	}
	Looong operator - (void) const
	{
		Looong d(*this);
		return d.Negative();
	}
	Looong &operator += (const Looong &d)
	{
		return (m_op == d.m_op) ? ab_add(d) : ab_minus(d);
	}
	Looong &operator -= (const Looong &d)
	{
		*this += (-d);
		return *this;
	}
	Looong &operator *= (const Looong &d)
	{
		*this = *this * d;
		return *this;
	}
	Looong &operator /= (const Looong &d)
	{
		*this = *this / d;
		return *this;
	}
	Looong &operator /= (const T_INT d)
	{
		if (d == 0)
		{
			//Debug("Divid by Zero.", "Error");
			return *this;
		}
		if (d <= m_step)
		{
			T_INT d2((d > 0) ? d : -d);
			T_INT bonus(0);
			for (int i = Size() - 1; i >= 0; --i)
			{
				m_data[i] += (bonus * m_step);
				bonus = m_data[i] % d2;
				m_data[i] /= d2;
			}
			Dec_Length();
			if (d < 0)
			{
				Negative();
			}
		}
		else
		{
			*this /= (Looong)d;
		}
		return *this;
	}
	Looong &operator %= (const Looong &d)
	{
		*this = *this % d;
		return *this;
	}
	Looong &operator %= (const T_INT &d)
	{
		*this = Looong<>((*this) % d);
		return *this;
	}
	Looong &operator ++ (void)
	{
		*this += 1;
		return (*this);
	}

	Looong &operator -- (void)
	{
		*this -= 1;
		return (*this);
	}

	Looong operator ++ (int)
	{
		Looong old_value(*this);
		++(*this);
		return old_value;
	}

	Looong operator -- (int)
	{
		Looong old_value(*this);
		--(*this);
		return old_value;
	}

	Looong &Random(const unsigned int &l)
	{
		m_data.resize(l);
		for (unsigned int i = 0; i < Size(); ++i)
		{
			m_data[i] = rand() % m_step;
		}
		Dec_Length();
		return *this;
	}

private:
	static int Compare(const Looong &d1, const Looong &d2)
	{
		if (d1.m_op ^ d2.m_op)
		{
			return d1.m_op ? -1 : 1;
		}
		return (d1.m_op ? -1 : 1) * ab_Compare(d1, d2);
	}
	static int ab_Compare(const Looong &d1, const Looong &d2)
	{
		if (d1.Size() == d2.Size())
		{
			for (int i = d1.Size() - 1; i >= 0; --i)
			{
				if (d1.m_data[i] != d2.m_data[i])
				{
					return (d1.m_data[i] < d2.m_data[i]) ? -1 : 1;
				}
			}
			return 0;
		}
		else
		{
			return (d1.Size() < d2.Size()) ? -1 : 1;
		}
	}
	Looong &ab_add(const Looong &d)
	{
		if (d.Size() > Size())
		{
			m_data.resize(d.Size());
		}
		T_INT bonus(0);
		for (unsigned int i = 0; i < d.Size(); ++i)
		{
			(m_data[i] += d.m_data[i]) += bonus;
			if (m_data[i] >= m_step)
			{
				m_data[i] -= m_step;
				bonus = 1;
			}
			else
			{
				bonus = 0;
			}
		}
		if ((bonus > 0) && (d.Size() >= Size()))
		{
			m_data.push_back(bonus);
		}
		return *this;
	}
	Looong &ab_minus(const Looong &d)
	{
		int cmpret = ab_Compare(*this, d);
		switch (cmpret)
		{
			case 0:
			{
				Init();
				break;
			}
			case 1:
			{
				ab_minus_mx(d);
				break;
			}
			case -1:
			{
				Looong d2(d);
				*this = d2.ab_minus_mx(*this);
				break;
			}
		}
		Check_NegativeZero();
		return *this;
	}
	Looong &ab_minus_mx(const Looong &d)
	{
		T_INT bonus(0);
		for (unsigned int i = 0; i < d.Size(); ++i)
		{
			(m_data[i] -= d.m_data[i]) -= bonus;
			if (m_data[i] < 0)
			{
				m_data[i] += m_step;
				bonus = 1;
			}
			else
			{
				bonus = 0;
			}
		}
		if (bonus > 0)
		{
			m_data[d.Size()] -= bonus;
		}
		Dec_Length();
		return *this;
	}
	Looong &ab_multiply_part(const Looong &d1, const Looong &d2, const unsigned int start1 = 0, const unsigned int start2 = 0)
	{
		Init();
		m_data.resize(d1.Size() + d2.Size());
		for (unsigned int i = start1; i < d1.Size(); ++i)
		{
			for (unsigned int j = start2; j < d2.Size(); ++j)
			{
				m_data[i + j] += d1.m_data[i] * d2.m_data[j];
				m_data[i + j + 1] += (m_data[i + j] / m_step);
				m_data[i + j] %= m_step;
			}
		}
		Dec_Length();
		return *this;
	}
	Looong &ab_divid(const Looong &d1, const Looong &d2)
	{
		if (d2 == 0)
		{
			//Debug("Divid by 0", "Error");
			return *this;
		}
		Init();
		if (d1.Size() < d2.Size())
		{
			return *this;
		}
		m_data.resize(d1.Size() - d2.Size() + 1);
		Looong tmp;
		tmp.Init();
		for (int i = Size() - 1; i >= 0; --i)
		{
			T_INT lo(0);
			T_INT hi(m_step);
			while (lo + 1 < hi)
			{
				T_INT mid((lo + hi) >> 1);
				m_data[i] = mid;
				tmp.ab_multiply_part(*this, d2, i, 0);
				int compret = ab_Compare(d1, tmp);
				switch (compret)
				{
					case 0:
					{
						Dec_Length();
						return *this;
					}
					case 1:
					{
						lo = mid;
						break;
					}
					case -1:
					{
						hi = mid;
						break;
					}
				}
			}
			m_data[i] = lo;
		}
		Dec_Length();
		return *this;
	}
	void Init(void)
	{
		m_data.clear();
		m_op = false;
		m_step = 1;
		for (int i = 1; i <= W; ++i)
		{
			m_step *= BASE;
		}
	}
	void Check_NegativeZero(void)
	{
		if ((m_op == true) && (m_data.size() == 0))
		{
			m_op = false;
		}
	}
	void Dec_Length(void)
	{
		if (m_data.empty() == false)
		{
			typename std::vector<T_INT>::iterator i(m_data.end() - 1);
			while ((m_data.empty() == false) && (*i == 0))
			{
				m_data.erase(i--);
			}
		}
	}
	void Convert(const std::string &inp)
	{
		Init();
		std::string::size_type startpos(0);
		if (inp[0] == '-')
		{
			m_op = true;
			startpos = 1;
		}
		else if (inp[0] == '+')
		{
			startpos = 1;
		}
		unsigned int mxsize((inp.size() - startpos + W - 1) / W);
		m_data.resize(mxsize);
		std::string::size_type firstend(inp.size() - W * (mxsize - 1));
		for ( ; startpos < firstend; ++startpos)
		{
			(m_data[mxsize - 1] *= BASE) += (inp[startpos] - '0');
		}
		for (int ti = mxsize - 2; ti >= 0; --ti)
		{
			for (int i(0); i < W; ++startpos, ++i)
			{
				(m_data[ti] *= BASE) += (inp[startpos] - '0');
			}
		}
		Dec_Length();
		Check_NegativeZero();
	}
	std::ostream &Output(std::ostream &out) const
	{
		if (m_op == true)
		{
			out << '-';
		}
		if (m_data.empty())
		{
			out << "0";
		}
		else
		{
			out << m_data[m_data.size() - 1];
			out << std::setfill('0');
			for (int i = m_data.size() - 2; i >= 0; --i)
			{
				out << std::setw(W) << std::setfill('0') << m_data[i];
			}
			out << std::setfill(' ');
		}
		return out;
	}

	bool m_op;
	std::vector<T_INT, _Alloc> m_data;
	T_INT m_step;
};

Looong<int>  tp[202];
Looong<int>  coef[202];
Looong<int>  CC[201][201];
/*
Looong<int>  C(int n, int m)
{
	Looong<int>  s(1);
	if (m + m > n)
	{
		m = n - m;
	}
	for (int j = 0; j < m; ++j)
	{
		(s *= (n - j)) /= (j + 1);
	}
	return s;
}
*/
int main()
{
	for (int i = 0; i <= 200; ++i)
	{
		CC[i][0] = 1;
		for (int j = 1; j < i; ++j)
		{
			CC[i][j] = CC[i - 1][j] + CC[i - 1][j - 1];
		}
		CC[i][i] = 1;
	}
	int n, t;
	while (cin >> n >> t)
	{
		tp[0] = 1;
		tp[1] = t;
		for (int i = 2; i <= n; ++i)
		{
			tp[i] = tp[i - 1] * tp[1];
		}

		for (int i = 0; i <= n; ++i)
		{
			cin >> coef[i];
		}
		for (int i = 0; i <= n; ++i)
		{
			Looong<int> c(0);
			for (int j = i; j <= n; ++j)
			{
				c += coef[j] * CC[j][i] * tp[j - i];
			}
			cout << c;
			if (i == n)
			{
				cout << endl;
			}
			else
			{
				cout << " ";
			}
		}
	}
	return 0;
}
