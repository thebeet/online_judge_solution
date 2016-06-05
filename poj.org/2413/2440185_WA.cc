#ifndef LOOONG_H_
#define LOOONG_H_

#include <iostream>
#include <string>

using namespace std;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

#define L 1000
#define defaultbase 10
#define defaultw 3

class looong
{
	friend istream &operator >> (istream &, looong &);
	friend ostream &operator << (ostream &, const looong &);
	friend bool operator > (const looong &,const looong &);
	friend bool operator < (const looong &,const looong &);
	friend bool operator == (const looong &,const looong &);
	
	public:
		int length;
		looong(void);
		looong(const int);
		looong(const string &);
		looong(const looong &);
		~looong(void);
		looong &operator += (const looong &);
		looong &operator -= (const looong &);
		looong &operator = (const looong &);
	
	protected:
	
	private:
		int data[L];
		int width;
		int step;
		int base;
		void init();
		void inclength(void);
		void declength(void);
		void convert(const string &);
};

looong operator + (const looong &,const looong &);
looong operator - (const looong &,const looong &);
bool operator >= (const looong &,const looong &);
bool operator <= (const looong &,const looong &);

#endif /*LOOONG_H_*/

void looong::init(void)
{
	int i;
	memset(data, 0, sizeof(data));
	length = 1;
	width = defaultw;
	base = defaultbase;
	step = 1;
	for (i = 1; i <= width; ++i)
	{
		step *= base;
	}
}

looong::looong(void)
{
	init();
}

looong::looong(const int n)
{
	init();
	data[1] = n;
	inclength();
}

looong::looong(const looong &d1)
{
	(*this) = d1;
}

looong::looong(const string &inp)
{
	convert(inp);
}

void looong::convert(const string &inp)
{
	init();
	
	for (string::size_type i_str = inp.size() - 1; i_str >= 0;)
	{
		int i, b_base;
		for (i = 1, b_base = 1; (i <= width); ++i, --i_str, b_base *= base)
		{
			/*
			if (str[i_str] > '9')
			{
				str[i_str] += ('9' + 1 - 'A');
			}
			*/
			data[length] = data[length] + (inp[i_str] - '0') * b_base;
			if (i_str == 0)
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
}

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
}

looong &looong::operator = (const looong &d1)
{
	length = d1.length;
	memcpy(this->data, d1.data, sizeof(data));
	width = d1.width;
	base = d1.base;
	step = d1.step;
	return *this;
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
	out << d1.data[d1.length];
	for (int i = d1.length - 1; i >= 1; --i)
	{
		for (int b_step = (d1.step - 1) / d1.base; d1.data[i] < b_step; b_step /= d1.base)
		{
			out << '0';
		}
		out << d1.data[i];
	}
	return out;
}

looong &looong::operator += (const looong &d1)
{
	for (int i = 1; i <= d1.length; ++i)
	{
		data[i] += d1.data[i];
	}
	length = MAX(d1.length, length);
	inclength();
	return *this;
}

looong &looong::operator -= (const looong &d1)
{
	for (int i = 1; i <= d1.length; ++i)
	{
		data[i] -= d1.data[i];
	}
	declength();
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

bool operator > (const looong & d1, const looong &d2)
{
	if (d1.length > d2.length)
	{
		return true;
	}
	if (d1.length < d2.length)
	{
		return false;
	}
	for (int i = d1.length; i >= 1; --i)
	{
		if (d1.data[i] > d2.data[i])
		{
			return true;
		}
		if (d1.data[i] < d2.data[i])
		{
			return false;
		}
	}
	return false;
}

bool operator >= (const looong & d1, const looong &d2)
{
	return (!(d1 < d2));
}

bool operator < (const looong & d1, const looong &d2)
{
	if (d1.length < d2.length)
	{
		return true;
	}
	if (d1.length > d2.length)
	{
		return false;
	}
	for (int i = d1.length; i >= 1; --i)
	{
		if (d1.data[i] < d2.data[i])
		{
			return true;
		}
		if (d1.data[i] > d2.data[i])
		{
			return false;
		}
	}
	return false;
}

bool operator <= (const looong & d1, const looong &d2)
{
	return (!(d1 > d2));
}

looong l[1010];
looong n, m;

int find(looong tar)
{
	int lo, hi, mid;
	lo = 0; hi = 1000;
	while (lo + 1 < hi)
	{
		mid = (lo + hi) >> 1;
		if (l[mid] > tar)
		{
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	}
	return lo;
}

int main()
{
	l[1] = 1;
	l[2] = 1;
	for (int i = 3; i <= 1000; ++i)
	{
		l[i] = l[i - 1] + l[i - 2];
	}
	while (cin >> n >> m, m > 0)
	{
		cout << find(m) - find(n - 1) << endl;
	}
	return 0;
}	
