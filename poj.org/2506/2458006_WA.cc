#include <iostream>
#include <string>

using namespace std;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

#define NOP

#define L 2000
#define defaultbase 10
#define defaultw 3

class looong
{
	friend istream &operator >> (istream &, looong &);
	friend ostream &operator << (ostream &, const looong &);
	friend bool operator > (const looong &,const looong &);
	friend bool operator < (const looong &,const looong &);
	friend bool operator == (const looong &,const looong &);
	friend looong operator * (const looong &,const looong &);
	
	public:
		looong(void);
		looong(const int);
		looong(const string &);
		looong(const char *);
		looong(const looong &);
		~looong(void);
		int size(void);
		looong &operator ++ ();
		looong &operator -- ();
		looong operator ++ (int);
		looong operator -- (int);
		looong &operator += (const looong &);
		looong &operator -= (const looong &);
		looong &operator *= (const looong &);
		looong &operator = (const looong &);
	
	protected:
	
	private:
		int length;
#ifndef NOP
		bool op;
#endif /* NOP */
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
bool operator >= (const looong &,const looong &);
bool operator <= (const looong &,const looong &);

void looong::init(void)
{
	int i;
	memset(data, 0, sizeof(data));
	length = 1;
#ifndef NOP
	op = false;
#endif /* NOP */
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
#ifndef NOP
	int new_n;
	if (n < 0)
	{
		op = true;
		new_n = -n;
	}
	else
	{
		new_n = n;
	}
	data[1] = new_n;
#else
	data[1] = n;
#endif /* NOP */
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

looong::looong(const char inp[])
{
	string newinp(inp);
	convert(newinp);
}

void looong::convert(const string &inp)
{
	init();
	
	string::size_type rendpos = 0;
	
#ifndef NOP
	if (inp[0] == '-')
	{
		op = true;
		rendpos = 1;
	}
	else if (inp[0] == '+')
	{
		rendpos = 1;
	}
#endif /* NOP */
	for (string::size_type i_str = inp.size() - 1; i_str >= rendpos;)
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
#ifndef NOP
	checknegativezero();
#endif /* NOP */	
}

#ifndef NOP
void looong::checknegativezero(void)
{
	if ((length == 1) && (data[1] == 0))
	{
		op = false;
	}
}
#endif /* NOP */

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
#ifndef NOP
	checknegativezero();
#endif /* NOP */	
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
#ifndef NOP
	checknegativezero();
#endif /* NOP */	
}

int looong::size(void)
{
	return length;
}

looong &looong::operator = (const looong &d1)
{
	length = d1.length;
#ifndef NOP
	op = d1.op;
#endif /* NOP */
	memmove(this->data, d1.data, sizeof(data));
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


/* ?????????????????? */
ostream & operator << (ostream &out, const looong &d1)
{
#ifndef NOP	
	if (d1.op == true)
	{
		out << '-';
	}
#endif /* NOP */	
	out << d1.data[d1.length];
	for (int i = d1.length - 1; i >= 1; --i)
	{
		for (int b_step = (d1.step - 1) / d1.base; d1.data[i] < b_step; b_step /= d1.base)
		{
			out << "0";
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
#ifndef NOP
	if (this->op == d1.op)
	{
#endif /* NOP */
		for (int i = 1; i <= d1.length; ++i)
		{
			data[i] += d1.data[i];
		}
		length = MAX(d1.length, length);
		inclength();
#ifndef NOP
	}
	else
	{
		this->op = d1.op;
		(*this) -= d1;
		this->op = !(this->op);
	}
#endif /* NOP */
	return (*this);
}

looong &looong::operator -= (const looong &d1)
{
#ifndef NOP
	if (this->op == d1.op)
	{
		if ((*this) >= d1)
		{
#endif /* NOP */
			for (int i = 1; i <= d1.length; ++i)
			{
				data[i] -= d1.data[i];
			}
			declength();
#ifndef NOP
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
#endif /* NOP */
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

looong operator * (const looong & d1, const looong &d2)
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
#ifndef NOP
	d3.op = d1.op ^ d2.op;
#endif /* NOP */
	d3.inclength();
	return d3;
}

looong &looong::operator *= (const looong &d1)
{
	(*this) = (*this) * d1;
	return *this;
}
	
bool operator > (const looong & d1, const looong &d2)
{
#ifndef NOP
	if ((d1.op == true) && (d2.op == false))
	{
		return true;
	}
	if ((d1.op == false) && (d2.op == true))
	{
		return false;
	}
#endif /* NOP */
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
#ifndef NOP
	if ((d1.op == true) && (d2.op == false))
	{
		return false;
	}
	if ((d1.op == false) && (d2.op == true))
	{
		return true;
	}
#endif /* NOP */
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

bool operator <= (const looong & d1, const looong &d2)
{
	return (!(d1 > d2));
}

bool operator == (const looong & d1, const looong &d2)
{
#ifndef NOP
	if ((d1.length != d2.length) || (d1.op != d2.op))
	{
		return false;
	}
#endif /* NOP */
	for (int i = d1.length; i >= 1; --i)
	{
		if (d1.data[i] != d2.data[i])
		{
			return false;
		}
	}
	return true;
}

looong ans[256];

int main()
{
	ans[0] = 1;
	ans[1] = 1;
	ans[2] = 3;
	for (int i = 3; i <= 250; ++i)
	{
		ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 2];
	}

	int n;
	while (scanf("%d", &n) != EOF)
	{
		  cout << ans[n] << endl;
	}
	return 0;	
}
