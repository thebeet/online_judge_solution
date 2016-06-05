#include <stdio.h>
#include <iostream>

using namespace std;

class t_TreeList
{
public:
	t_TreeList(const int n)
	{
		 data = new int[n];
		 memset(data, 0, sizeof(int) * n);
		 size = n - 1;
	}
	~t_TreeList()
	{
		 delete [] data;
	}
	void add(int k, int newdata)
	{
		while (k < size)
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
	int *data;
	int size;
	int lowbit(const int x)
	{
		return (x & (x ^ (x - 1)));
	}
};

t_TreeList treelist(32001);
int ans[32001];
int use[32001];

int main()
{
	int i, n;
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d%*d", x);
		ans[i] = treelist.getsum(x);
		treelist.add(x, 1);
	}
	for (i = 1; i <= n; ++i)
	{
		++use[ans[i]];
	}
	for (i = 0; i < n; ++i)
	{
		cout << use[i] << endl;
	}
	return 0;
}
