#include <iostream>
#include <string>

using namespace std;

const string weekday[8] = {"Sunday", "Monday", "Tuesday" , "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

class t_Date
{
	friend bool isleapyear(const int year)
	{
		if (((year & 3) == 0) && (((year % 100) != 0) || ((year % 400) == 0)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	friend int compair(const t_Date &d1, const t_Date &d2)
	{
		if (d1.m_year > d2.m_year)
		{
			return 1;
		}
		if (d1.m_year < d2.m_year)
		{
			return -1;
		}
		if (d1.m_month > d2.m_month)
		{
			return 1;
		}
		if (d1.m_month < d2.m_month)
		{
			return -1;
		}
		if (d1.m_day > d2.m_day)
		{
			return 1;
		}
		if (d1.m_day < d2.m_day)
		{
			return -1;
		}
		return 0;
	}
	
	friend bool operator > (const t_Date &d1, const t_Date &d2)
	{
		return (compair(d1, d2) == 1);
	}
	friend bool operator < (const t_Date &d1, const t_Date &d2)
	{
		return (compair(d1, d2) == -1);
	}
	friend bool operator >= (const t_Date &d1, const t_Date &d2)
	{
		return (compair(d1, d2) >= 0);
	}
	friend bool operator <= (const t_Date &d1, const t_Date &d2)
	{
		return (compair(d1, d2) <= 0);
	}
	friend bool operator == (const t_Date &d1, const t_Date &d2)
	{
		return (compair(d1, d2) == 0);
	}
	friend t_Date operator + (const t_Date &d1, const int d) // d >= 0
	{
		t_Date d2(d1);
		d2 += d;
		return d2;
	}
	
	friend int operator - (const t_Date &d1, const t_Date &d2)
	{
		if (d1 < d2) 
		{
			//swap d1 and d2
			return -(d2 - d1);
		}
		
		if (d1.m_year == d2.m_year)
		{
			if (d1.m_month == d2.m_month)
			{
				return (d1.m_day - d2.m_day);
			}
			else
			{
				int sum;
				t_Date tmp(d2);
				sum = tmp.monthlength() - tmp.m_day;
				for ( ++tmp.m_month ; tmp.m_month < d1.m_month; ++tmp.m_month)
				{
					sum += tmp.monthlength();
				}
				sum += d1.m_day;
				return sum;
			}
		}
		else
		{
			int sum = 1;
			t_Date tmp(d2.m_year, 12, 31);
			sum += tmp - d2;
			for (++tmp.m_year; tmp.m_year < d1.m_year; ++tmp.m_year)
			{
				sum += tmp.yearlength();
			}
			tmp.m_month = 1;
			tmp.m_day = 1;
			sum += d1 - tmp;
			return sum;
		}
	}

	friend istream & operator >> (istream &in, t_Date &d1)
	{
		in >> d1.m_year >> d1.m_month >> d1.m_day;
		return in;
	}
	friend ostream & operator << (ostream &out, t_Date &d1)
	{
		out << d1.m_year << "-" << d1.m_month << "-" << d1.m_day;
		return out;
	}

public:
	t_Date(const int year = 0, const int month = 0, const int day = 0)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}
	
	bool isleap() const
	{
		return (isleapyear(m_year));
	}
	
	int yearlength() const
	{
		return ((isleap()) ? 366 : 365);
	}
	int monthlength() const
	{
		switch (m_month)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			return ((isleap()) ? 29 : 28);
		default: //error
			return -1;
		}
	}
	
	t_Date &operator += (const int d) // d >= 0
	{
		m_day += d;
		if (m_day > monthlength())
		{
			int restday = m_day - monthlength();
			++m_month;
			while ((m_month <= 12) && (restday > monthlength()))
			{
				restday -= monthlength();
				++m_month;
			}
			if (m_month <= 12)
			{
				m_day = restday;
				return (*this);
			}
			else
			{
				++m_year;
				while (restday > yearlength())
				{
					restday -= yearlength();
					++m_year;
				}
				m_month = 1;
				m_day = restday;
				(*this) += 0;
				return (*this);
			}
		}
		return (*this);
	}
private:
	int m_year;
	int m_month;
	int m_day;
};

int main()
{
	int n;
	while ((cin >> n), n >= 0)
	{
		t_Date d0(2000, 1, 1);
		d0 += n;
		cout << d0 << " " << weekday[((n + 5) % 7) + 1] << endl;
	}
	return 0;
}
