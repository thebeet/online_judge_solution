/*
 * Yachts.cpp
 *
 *  Created on: 2008-11-13
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	long long n, d;
	stack<pair<long long, long long> > ys;
	long long sold(0);
	long long gold(0);
	scanf("%I64d%I64d", &n, &d);
	for (long long i = 0; i < n; ++i)
	{
		long long acq;
		scanf("%I64d", &acq);
		if (acq < d)
		{
			sold += acq;
			ys.push(make_pair(d - acq, i));
		}
		else if (acq == d)
		{
			sold += acq;
		}
		else if (acq > d)
		{
			sold += d;
			acq -= d;
			while (ys.empty() == false)
			{
				pair<long long, long long> top = ys.top();
				ys.pop();
				if (top.first < acq)
				{
					sold += top.first;
					gold += top.first * (i - top.second);
					acq -= top.first;
				}
				else if (top.first == acq)
				{
					sold += top.first;
					gold += top.first * (i - top.second);
					break;
				}
				else
				{
					sold += acq;
					gold += acq * (i - top.second);
					top.first -= acq;
					ys.push(top);
					break;
				}
			}
		}
	}
	cout << sold << " " << gold << endl;
	return 0;
}
