#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
/*
class t_data
{
	friend bool operator < (const t_data &d1, const t_data &d2)
	{
		return (d1.weight < d2.weight);
	}
	
	public:
		int weight, data;
};
*/
typedef int t_data;
class t_heap
{
	public:
		t_heap(const int n)
		{
			 data = new t_data[n];
			 memset(data, 0, sizeof(t_data) * n);
			 heapsize = 0;
		}
		~t_heap()
		{
			 delete [] data;
		}
		void insert(const t_data &newdata)
		{
			data[++heapsize] = newdata;
			turnup(heapsize);
		}
		t_data &gettop() const
		{
			return data[1];
		}
		void deletetop()
		{
			swap(data[1], data[heapsize--]);
			turndown(1);
		}
		void clean()
		{
			heapsize = 0;
		}
		int heapsize;
	private:
		t_data *data;
		void turnup(int p)
		{
			if (p > 1)
			{
				int nextp = (p >> 1);
				if (data[p] > data[nextp])
				{
					swap(data[nextp], data[p]);
					turnup(nextp);
				}
			}
		}
		void turndown(int p)
		{
			int nextp = (p << 1);
			if (nextp <= heapsize)
			{
				if ((nextp < heapsize) && (data[nextp + 1] > data[nextp]))
				{
					++nextp;
				}
				if (data[nextp] > data[p])
				{
					swap(data[nextp], data[p]);
					turndown(nextp);
				}
			}
		}
};

int main()
{
	int i, n, x, y, h1, h2, sum, dam, mxdam;
	cin >> n >> x >> y >> h1 >> h2;
	t_heap att(n + 1);
	att.clean();
	sum = 0;
	dam = 0;
	mxdam = 0;
	for (i = 1; i <= n; ++i)
	{
		dam += x;
		mxdam = max(mxdam, dam);
		if (h2 <= dam)
		{
			break;
		}
		int atk;
		scanf("%d", &atk);
		att.insert(atk);
		sum += atk;
		if (sum >= h1)
		{
			dam -= x;
			int mxatt = att.gettop();
			sum -= max(mxatt, y);
			att.deletetop();
		}
	}
	if (h2 <= dam)
	{
		cout << "Win" << endl;
		cout << i << endl;
	}
	else
	{
		cout << "Lose" << endl;
		cout << mxdam << endl;
	}
	return 0;
}
