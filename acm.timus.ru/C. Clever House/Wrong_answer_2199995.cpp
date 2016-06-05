/*
 * Clever_House.cpp
 *
 *  Created on: Aug 17, 2008
 *      Author: yonghu
 */

#ifndef LOOONG_H_
#define LOOONG_H_

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define UNSIGNED_

typedef int INT;

const int L = 10000;
const int defaultbase = 10;
const int defaultw = 3;

class looong
{
	friend istream &operator >> (istream &, looong &);
	friend ostream &operator << (ostream &, const looong &);
	friend int compare(const looong &, const looong &);
	friend looong partmul(const looong &, const looong &, int, int);
	friend looong operator / (const looong &, const looong &);
	friend int operator % (const looong & d1, const int m);
	friend looong sqrt(const looong &);

	public:
		looong(const int);
		looong(const long long);
		looong(const string &);
		looong(const char *);
		~looong(void);
		int &operator [](int pos)
		{
			return data[pos];
		}
		const int &operator [](int pos) const
		{
			return data[pos];
		}
		looong &operator ++ ();
		looong &operator -- ();
		looong operator ++ (int);
		looong operator -- (int);
		looong &operator += (const looong &);
		looong &operator -= (const looong &);
		looong &operator *= (const looong &);
		looong &operator /= (const looong &);
		looong &operator %= (const looong &);
		looong &operator <<= (const int &);
		looong &operator >>= (const int &);

	//private:
		int length;
#ifndef UNSIGNED_
		bool op;
#endif /* UNSIGNED_ */
		INT data[L];
		int width;
		int step;
		int base;
		void init();
		void inclength(void);
		void declength(void);
		void convert(const string &);
		void checknegativezero(void);
};

looong operator + (const looong &,const looong &);
looong operator - (const looong &,const looong &);
looong operator * (const looong &, const looong &);
looong operator % (const looong &,const looong &);
looong operator << (const looong &, const int &);
looong operator >> (const looong &, const int &);
bool operator == (const looong &, const looong &);
bool operator >= (const looong &,const looong &);
bool operator <= (const looong &,const looong &);
bool operator > (const looong &,const looong &);
bool operator < (const looong &,const looong &);

#endif /*LOOONG_H_*/

void looong::init(void)
{
	int i;
	memset(data, 0, sizeof(data));
	length = 1;
#ifndef UNSIGNED_
	op = false;
#endif /* UNSIGNED_ */
	width = defaultw;
	base = defaultbase;
	step = 1;
	for (i = 1; i <= width; ++i)
	{
		step *= base;
	}
}

looong::looong(const int n = 0)
{
	init();
#ifndef UNSIGNED_
	if (n < 0)
	{
		op = true;
		data[1] = -n;
	}
	else
	{
		data[1] = n;
	}
#else
	data[1] = n;
#endif /* UNSIGNED_ */
	inclength();
}

looong::looong(const long long n)
{
	long long t(n);
	init();
#ifndef UNSIGNED_
	if (t < 0)
	{
		op = true;
		t = -t;
	}
#endif /* UNSIGNED_ */
	if (t > 0)
	{
		data[1] = t % (long long)step;
		t /= (long long)step;
		while (n > 0)
		{
			++length;
			data[length] = t % (long long)step;
			t /= (long long)step;
		}
	}
}

looong::looong(const string &inp)
{
	convert(inp);
}

looong::looong(const char inp[])
{
	string newinp(inp);
	convert(newinp);
}

void looong::convert(const string &inp)
{
	init();

	string::size_type rendpos = 0;

#ifndef UNSIGNED_
	if (inp[0] == '-')
	{
		op = true;
		rendpos = 1;
	}
	else if (inp[0] == '+')
	{
		rendpos = 1;
	}
#endif /* UNSIGNED_ */
	for (string::size_type i_str = inp.size() - 1; i_str >= rendpos;)
	{
		int i, b_base;
		for (i = 1, b_base = 1; (i <= width); ++i, --i_str, b_base *= base)
		{
			data[length] = data[length] + (inp[i_str] - '0') * b_base;
			if (i_str == rendpos)
			{
				break;
			}
		}
		if (i > width)
		{
			++length;
		}
		else
		{
			break;
		}
	}
#ifndef UNSIGNED_
	checknegativezero();
#endif /* UNSIGNED_ */
}

#ifndef UNSIGNED_
void looong::checknegativezero(void)
{
	if ((length == 1) && (data[1] == 0))
	{
		op = false;
	}
}
#endif /* UNSIGNED_ */

looong::~looong(void)
{
}

void looong::inclength(void)
{
	int i;
	for (i = 1; i < length; ++i)
	{
		data[i + 1] += (data[i] / step);
		data[i] %= step;
	}
	while (data[i] >= step)
	{
		data[i + 1] += (data[i] / step);
		data[i] %= step;
		++i;
	}
	length = i;
#ifndef UNSIGNED_
	checknegativezero();
#endif /* UNSIGNED_ */
}

void looong::declength(void)
{
	int i;
	for (i = 1; i < length; ++i)
	{
		data[i + 1] += ((data[i] - step + 1) / step);
		data[i] = ((data[i] % step) + step) % step;
	}
	while ((data[i] == 0) && (i > 1))
	{
		--i;
	}
	length = i;
#ifndef UNSIGNED_
	checknegativezero();
#endif /* UNSIGNED_ */
}

istream & operator >> (istream &in, looong &d1)
{
	string inp;
	in >> inp;
	if (in)
	{
		d1.convert(inp);
	}
	return in;
}

ostream & operator << (ostream &out, const looong &d1)
{
#ifndef UNSIGNED_
	if (d1.op == true)
	{
		out << '-';
	}
#endif /* UNSIGNED_ */
	out << d1[d1.length];
	for (int i = d1.length - 1; i >= 1; --i)
	{
		for (int b_step = d1.step / d1.base; (d1[i] < b_step) && (b_step > 1); b_step /= d1.base)
		{
			out << '0';
		}
		out << d1[i];
	}
	return out;
}

looong &looong::operator ++ ()
{
	++data[1];
	inclength();
	return (*this);
}

looong &looong::operator -- ()
{
	--data[1];
	declength();
	return (*this);
}

looong looong::operator ++ (int)
{
	looong old_value(*this);
	++(*this);
	return old_value;
}

looong looong::operator -- (int)
{
	looong old_value(*this);
	--(*this);
	return old_value;
}

looong &looong::operator += (const looong &d1)
{
#ifndef UNSIGNED_
	if (this->op == d1.op)
	{
#endif /* UNSIGNED_ */
		for (int i = 1; i <= d1.length; ++i)
		{
			data[i] += d1[i];
		}
		length = max(d1.length, length);
		inclength();
#ifndef UNSIGNED_
	}
	else
	{
		this->op = d1.op;
		(*this) -= d1;
		this->op = !(this->op);
	}
	checknegativezero();
#endif /* UNSIGNED_ */
	return *this;
}

looong &looong::operator -= (const looong &d1)
{
#ifndef UNSIGNED_
	if (this->op == d1.op)
	{
		if ((*this) >= d1)
		{
#endif /* UNSIGNED_ */
			for (int i = 1; i <= d1.length; ++i)
			{
				data[i] -= d1[i];
			}
			declength();
#ifndef UNSIGNED_
		}
		else
		{
			(*this) = d1 - (*this);
			this->op = !(this->op);
		}
	}
	else
	{
		this->op = d1.op;
		(*this) += d1;
		this->op = !(this->op);
	}
	checknegativezero();
#endif /* UNSIGNED_ */
	return *this;
}

looong operator + (const looong & d1, const looong &d2)
{
	looong d3(d1);
	d3 += d2;
	return d3;
}

looong operator - (const looong & d1, const looong &d2)
{
	looong d3(d1);
	d3 -= d2;
	return d3;
}

looong &looong::operator <<= (const int &offset)
{
	memmove(&data[offset + 1], &data[1], sizeof(int) * length);
	length += offset;
	memset(&data[1], 0, sizeof(int) * offset);
	return *this;
}

looong operator << (const looong &d1, const int &offset)
{
	looong d2(d1);
	d2 <<= offset;
	return d2;
}

looong &looong::operator >>= (const int &offset)
{
	if (length > offset)
	{
		memmove(&data[1], &data[offset + 1], sizeof(int) * (length - offset));
		length -= offset;
	}
	else
	{
		memset(&data[1], 0, sizeof(int) * length);
		length = 1;
	}
	return *this;
}

looong operator >> (const looong &d1, const int &offset)
{
	looong d2(d1);
	d2 >>= offset;
	return d2;
}

looong partmul(const looong &d1, const looong &d2, int p1, int p2)
{
	looong d3(0);
	d3.length = d1.length + d2.length - 1;
	for (int i = p1; i <= d1.length; ++i)
	{
		for (int j = p2; j <= d2.length; ++j)
		{
			d3[i + j - 1] += d1[i] * d2[j];
		}
	}
#ifndef UNSIGNED_
	d3.op = d1.op ^ d2.op;
#endif /* UNSIGNED_ */
	d3.inclength();
	d3.declength();
	return d3;
}

looong operator * (const looong &d1, const looong &d2)
{
	return partmul(d1, d2, 1, 1);
}

looong &looong::operator *= (const looong &d1)
{
	(*this) = (*this) * d1;
	return *this;
}

//low speed
looong operator / (const looong &d1, const looong &d2)
{
#ifndef UNSIGNED_
	bool op1, op2;
	op1 = d1.op;
	op2 = d2.op;
	*const_cast <bool *>(&(d1.op)) = false;
	*const_cast <bool *>(&(d2.op)) = false;
#endif /* UNSIGNED_ */
	looong d3(0);
	looong mul(0);
	if (d1 < d2)
	{
		return d3;
	}
	d3.length = d1.length - d2.length + 1;

	for (int i = d3.length; i >= 1; --i)
	{
		int lo = 0;
		int hi = d3.step;
		while (lo + 1 < hi)
		{
			int mid = (lo + hi) >> 1;
			d3[i] = mid;
			int compret = compare(mul + ((d2 * mid) << (i - 1)), d1);
			switch (compret)
			{
			case 0:
				d3.declength();
				return d3;
			case 1:
				hi = mid;
				break;
			case -1:
				lo = mid;
				break;
			}
		}
		d3.data[i] = lo;
		mul += ((d2 * lo) << (i - 1));
	}
#ifndef UNSIGNED_
	d3.op = op1 ^ op2;
	*const_cast <bool *>(&(d1.op)) = op1;
	*const_cast <bool *>(&(d2.op)) = op2;
#endif /* UNSIGNED_ */
	d3.declength();
	return d3;
}

looong &looong::operator /= (const looong &d1)
{
	(*this) = (*this) / d1;
	return *this;
}

//high speed and unsigned
int operator % (const looong & d1, const int m)
{
	int rest = 0;
	for (int i = d1.length; i >= 1; --i)
	{
		rest = (rest * d1.step + d1[i]) % m;
	}
	return rest;
}

//low speed
looong operator % (const looong & d1, const looong &d2)
{
	looong d3 = d1 / d2;
	return d1 - d2 * d3;
}

looong &looong::operator %= (const looong &d1)
{
	(*this) = (*this) % d1;
	return *this;
}

looong sqrt(const looong &d1)
{
	looong ans(0);
	int i;
	ans.length = (d1.length + 1) >> 1;
	for (i = ans.length; i >= 1; --i)
	{
		int lo = 0;
		int hi = ans.step;
		while (lo + 1 < hi)
		{
			int mid = (lo + hi) >> 1;
			ans[i] = mid;
			int compret = compare(partmul(ans, ans, i, i), d1);
			switch (compret)
			{
			case 0:
				ans.declength();
				return ans;
			case 1:
				hi = mid;
				break;
			case -1:
				lo = mid;
				break;
			}
		}
		ans[i] = lo;
	}
	ans.declength();
	return ans;
}

int compare(const looong & d1, const looong &d2)
{
#ifndef UNSIGNED_
	if ((d1.op == true) && (d2.op == false))
	{
		return 1;
	}
	if ((d1.op == false) && (d2.op == true))
	{
		return -1;
	}
#endif /* UNSIGNED_ */
	if (d1.length > d2.length)
	{
		return 1;
	}
	if (d1.length < d2.length)
	{
		return -1;
	}
	for (int i = d1.length; i >= 1; --i)
	{
		if (d1[i] > d2[i])
		{
			return 1;
		}
		if (d1[i] < d2[i])
		{
			return -1;
		}
	}
	return 0;
}

bool operator > (const looong & d1, const looong &d2)
{
	return (compare(d1, d2) == 1);
}

bool operator >= (const looong & d1, const looong &d2)
{
	return (compare(d1, d2) >= 0);
}

bool operator < (const looong & d1, const looong &d2)
{
	return (compare(d1, d2) == -1);
}

bool operator <= (const looong & d1, const looong &d2)
{
	return (compare(d1, d2) <= 0);
}

bool operator == (const looong & d1, const looong &d2)
{
	return (compare(d1, d2) == 0);
}

bool operator != (const looong & d1, const looong &d2)
{
	return (compare(d1, d2) != 0);
}

const int wide = 20;

class dooouble
{
public:
	dooouble(int i)
	{
		data = i;
		data <<= wide;
	}
	looong data;

	dooouble &operator += (const dooouble &d1)
	{
		data += d1.data;
		return *this;
	}
	dooouble &operator -= (const dooouble &d1)
	{
		data -= d1.data;
		return *this;
	}
	dooouble &operator *= (const dooouble &d1)
	{
		data *= d1.data;
		data >>= wide;
		return *this;
	}
	dooouble &operator /= (const dooouble &d1)
	{
		data <<= wide;
		data /= d1.data;
		return *this;
	}
	friend dooouble operator + (const dooouble &d1, const dooouble &d2)
	{
		dooouble d3(d1);
		d3 += d2;
		return d3;
	}
	friend dooouble operator - (const dooouble &d1, const dooouble &d2)
	{
		dooouble d3(d1);
		d3 -= d2;
		return d3;
	}
	friend dooouble operator * (const dooouble &d1, const dooouble &d2)
	{
		dooouble d3(d1);
		d3 *= d2;
		return d3;
	}
	friend dooouble operator / (const dooouble &d1, const dooouble &d2)
	{
		dooouble d3(d1);
		d3 /= d2;
		return d3;
	}

};

int compare(const dooouble & d1, const dooouble &d2)
{
	return compare(d1.data, d2.data);
}

bool operator > (const dooouble & d1, const dooouble &d2)
{
	return (compare(d1, d2) == 1);
}

bool operator >= (const dooouble & d1, const dooouble &d2)
{
	return (compare(d1, d2) >= 0);
}

bool operator < (const dooouble & d1, const dooouble &d2)
{
	return (compare(d1, d2) == -1);
}

bool operator <= (const dooouble & d1, const dooouble &d2)
{
	return (compare(d1, d2) <= 0);
}

bool operator == (const dooouble & d1, const dooouble &d2)
{
	return (compare(d1, d2) == 0);
}

bool operator != (const dooouble & d1, const dooouble &d2)
{
	return (compare(d1, d2) != 0);
}

/*
int main()
{
	looong Q, C, A, B, N;
	cin >> Q >> C >> N;
	if ((Q < N) && (C < N) || (Q == 0) || (C == 0))
	{
		cout << 0 << endl;
		return 0;
	}
	A = Q % N;
	B = C % N;
	if ((A + B <= N) || (Q < N) || (C < N))
	{
		cout << (Q * C - A * B) / N << endl;
	}
	else
	{
		cout << (Q * C - (N - A) * (N - B)) / N << endl;
	}
	return 0;
}
*/

int main()
{
	int i, k, y;
	int n;
	looong m, p, q(1);
	cin >> n >> p >> k;
	y = 0;
	for (i = 0;