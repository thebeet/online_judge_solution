/*
 * MooFest.cpp
 *
 *  Created on: 2009-8-30
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class TreeArray
{
public:
	TreeArray(const int n)
	{
		 data = new int[n];
		 memset(data, 0, sizeof(int) * n);
		 size = n - 1;
	}
	~TreeArray()
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
		return (x & (-x));
	}
};

int main()
{
	int n;
	cin >> n;
	vector< pair<int, int> > cows(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> cows[i].second >> cows[i].first;
	}
	sort(cows.begin(), cows.end());
	long long sum(0LL);
	{
		TreeArray tav(20010);
		TreeArray tan(20010);
		for (int i = 0; i < n; ++i)
		{
			int gsv = tav.getsum(cows[i].second);
			int gsn = tan.getsum(cows[i].second);
			sum += (long long)(gsn * cows[i].first - gsv) * (long long)cows[i].second;
			tav.add(cows[i].second, cows[i].first);
			tan.add(cows[i].second, 1);
		}
	}
	{
		TreeArray tav(20010);
		TreeArray tan(20010);
		for (int i = n - 1; i >= 0; --i)
		{
			int gsv = tav.getsum(cows[i].second - 1);
			int gsn = tan.getsum(cows[i].second - 1);
			sum += (long long)(gsv - gsn * cows[i].first) * (long long)cows[i].second;
			tav.add(cows[i].second, cows[i].first);
			tan.add(cows[i].second, 1);
		}
	}
	cout << sum << endl;
	return 0;
}
