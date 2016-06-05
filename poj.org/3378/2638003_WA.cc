#ifndef LOOONG_H_
#define LOOONG_H_

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

//#define UNSIGNED_

#define L 1000
#define defaultbase 10
#define defaultw 3

class looong
{
	friend istream &operator >> (istream &, looong &);
	friend ostream &operator << (ostream &, const looong &);
	friend int compare(const looong &, const looong &);
	friend bool operator == (const looong &, const looong &);
	friend looong operator * (const looong &, const looong &);
	friend looong operator / (const looong &, const looong &);
	friend int operator % (const looong & d1, const int m);
	friend looong sqrt(const looong &);

	public:
		looong(const int);
		looong(const string &);
		looong(const char *);
		~looong(void);
		int size(void);
		looong &operator ++ ();
		looong &operator -- ();
		looong operator ++ (int);
		looong operator -- (int);
		looong &operator += (const looong &);
		looong &operator -= (const looong &);
		looong &operator *= (const looong &);
		looong &operator /= (const looong &);
		looong &operator %= (const looong &);
	
	protected:
	
	private:
		int length;
#ifndef UNSIGNED_
		bool op;
#endif /* UNSIGNED_ */
		int data[L];
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
looong operator % (const looong &,const looong &);
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

int looong::size(void)
{
	return length;
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
	out << d1.data[d1.length];
	for (int i = d1.length - 1; i >= 1; --i)
	{
		for (int b_step = d1.step / d1.base; (d1.data[i] < b_step) && (b_step > 1); b_step /= d1.base)
		{
			out << '0';
		}
		out << d1.data[i];
	}
	return out;
}

looong &looong::operator ++ ()
{
	++data[0];
	inclength();
	return (*this);
}

looong &looong::operator -- ()
{
	--data[0];
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
			data[i] += d1.data[i];
		}
		length = MAX(d1.length, length);
		inclength();
#ifndef UNSIGNED_
	}
	else
	{
		this->op = d1.op;
		(*this) -= d1;
		this->op = !(this->op);
	}
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
				data[i] -= d1.data[i];
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

looong operator * (const looong &d1, const looong &d2)
{
	looong d3(0);
	if (((d1.length == 1) && (d1.data[1] == 0)) || ((d2.length == 1) && (d2.data[1] == 0)))
	{
		return d3;
	}
	d3.length = d1.length + d2.length - 1;
	for (int i = 1; i <= d1.length; ++i)
	{
		for (int j = 1; j <= d2.length; ++j)
		{
			d3.data[i + j - 1] += d1.data[i] * d2.data[j];
		}
	}
#ifndef UNSIGNED_
	d3.op = d1.op ^ d2.op;
#endif /* UNSIGNED_ */
	d3.inclength();
	return d3;
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
	if ((d2.data[0] == 1) && (d2.data[1] == 1))
	{
		return d3;
	}
	if (d1 < d2)
	{
		return d3;
	}
	d3.length = d1.length - d2.length + 1;
	
	for (int i = d3.length; i >= 1; --i)
	{
		while (d3 * d2 <= d1)
		{ 
			++d3.data[i];
		}
		--d3.data[i];
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
		rest = (rest * d1.step + d1.data[i]) % m;
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
	int i, j;
	ans.length = (d1.length + 1) >> 1;
	for (i = ans.length; i >= 1; --i)
	{
		for (j = 1; j < ans.step; ++j)
		{
			ans.data[i] = j;
			if (ans * ans > d1)
			{
				break;
			}
		}
		ans.data[i] = j - 1;
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
		if (d1.data[i] > d2.data[i])
		{
			return 1;
		}
		if (d1.data[i] < d2.data[i])
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

struct inp
{
	int d;
	int pos;
}inps[65536];

int newinp[65536];

bool operator < (const inp &i1, const inp &i2)
{
	return (i1.d < i2.d);
}

const int SIZE = 50010;

class t_TreeArray
{
public:
	void init(const int n)
	{
		 memset(data, 0, sizeof(long long) * (n + 1));
		 size = n;
	}
	void add(int k, long long newdata)
	{
		while (k <= size)
		{
			data[k] += newdata;
			k += lowbit(k);
		}
	}
	long long getsum(int k) //get sum for 1 to k
	{
		long long sum = 0;
		while (k > 0)
		{
			sum += data[k];
			k -= lowbit(k);
		}
		return sum;
	}
	
private:
	long long data[SIZE];
	int size;
	int lowbit(const int x)
	{
		return (x & (x ^ (x - 1)));
	}
};

t_TreeArray ta[5];

int main()
{
	int i, n, k;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &inps[i].d);
			inps[i].pos = i;
		}
		sort(inps + 1, inps + 1 + n);
		k = 1;
		newinp[inps[1].pos] = 1;
		for (i = 2; i <= n; ++i)
		{
			if (inps[i].d == inps[i - 1].d)
			{
				newinp[inps[i].pos] = k; 
			}
			else
			{
				newinp[inps[i].pos] = ++k; 
			}
		}
		
		for (i = 0; i <= 4; ++i)
		{
			ta[i].init(k);
		}
		
		looong ans(0);
		for (i = 1; i <= n; ++i)
		{
			int ret = ta[4].getsum(newinp[i] - 1);
			if (ret > 0)
			{
				char buf[64];
				sprintf(buf, "%I64d", ta[4].getsum(newinp[i] - 1));
				ans += (looong)(buf);
			}
			for (k = 3; k >= 0; --k)
			{
				int sum = ta[k].getsum(newinp[i] - 1);
				if (sum > 0)
				{
					ta[k + 1].add(newinp[i], ta[k].getsum(newinp[i] - 1));
				}
			}
			ta[1].add(newinp[i], 1);
		}
		cout << ans << endl;
	}
}
