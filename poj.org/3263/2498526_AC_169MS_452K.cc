#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 10010

void swap(int &d1, int &d2)
{
	int tmp = d1;
	d1 = d2;
	d2 = tmp;
}

class t_TreeList
{
public:
	t_TreeList()
	{
		 memset(data, 0, sizeof(data));
	}
	virtual ~t_TreeList()
	{
	}
	void setsize(const int n)
	{
		size = n;
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
	
private:
	int data[SIZE];
	int size;
	int lowbit(const int x)
	{
		return (x & (x ^ (x - 1)));
	}
};

t_TreeList treelist;
struct inp
{
	int st, ed;
}inps[10010];

bool cmp(inp inp1, inp inp2)
{
	if (inp1.st == inp2.st)
	{
		return (inp1.ed < inp2.ed);
	}
	else
	{
		return (inp1.st < inp2.st);
	}
}

int main()
{
	int i, n, id, highest, r;
	cin >> n >> id >> highest >> r;
	treelist.setsize(n);
	treelist.add(1, highest);
	for (i = 1; i <= r; ++i)
	{
		cin >> inps[i].st >> inps[i].ed;
		if (inps[i].st > inps[i].ed)
		{
			swap(inps[i].st, inps[i].ed);
		}
	}
	sort(inps + 1, inps + 1 + r, cmp);
	for (i = 1; i <= r; ++i)
	{
		if ((inps[i].st != inps[i - 1].st) || (inps[i].ed != inps[i - 1].ed))
		{
			treelist.add(inps[i].st + 1, -1);
			treelist.add(inps[i].ed, 1);
		}
	}
	for (i = 1; i <= n; ++i)
	{
		cout << treelist.getsum(i) << endl;
	}
	return 0;
}
