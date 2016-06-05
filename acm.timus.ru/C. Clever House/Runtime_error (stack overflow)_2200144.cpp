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

const int L = 20010;
const int defaultbase = 10;
const int defaultw = 2;

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
			data[len