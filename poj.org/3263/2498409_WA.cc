#include <iostream>

using namespace std;

#define SIZE 30010

void swap(int &d1, int &d2)
{
	int tmp = d1;
	d1 = d2;
	d2 = tmp;
}

class t_TreeList
{
public:
	t_TreeList(const int n)
	{
		 memset(data, 0, sizeof(data));
		 size = n;
	}
	virtual ~t_TreeList()
	{
	}
	void add(int k, int newdata)
	{
		while (k <= size)
		{
			data[k] += newdata;
			k += lowbit(k);
		}
	}
	int getsum(int k) //get sum for 1 to k
	{
		int sum = 0;
		while (k > 0)
		{
			sum += data[k];
			k -= lowbit(k);
		}
		return sum;
	}
	int getsum(int f, int t) //get sum for f to t
	{
		return (getsum(t) - getsum(f - 1));
	}
	
private:
	int data[SIZE];
	int size;
	int lowbit(const int x)
	{
		return (x & (x ^ (x - 1)));
	}
};

t_TreeList treelist(20010);

int main()
{
	int i, n, id, highest, r;
	cin >> n >> id >> highest >> r;
	treelist.add(1, highest);
	for (i = 1; i <= r; ++i)
	{
		int st, ed;
		cin >> st >> ed;
		if (st > ed)
		{
			swap(st, ed);
		}
		treelist.add(st + 1, -1);
		treelist.add(ed, 1);
	}
	for (i = 1; i <= n; ++i)
	{
		cout << treelist.getsum(i) << endl;
	}
	return 0;
}
