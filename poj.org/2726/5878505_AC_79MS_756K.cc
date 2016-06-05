/*
 * Holiday_Hotel.cpp
 *
 *  Created on: 2009-9-19
 *      Author: Administrator
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Hotel
{
	int price;
	int dist;
};

bool operator < (const Hotel &h1, const Hotel &h2)
{
	return ((h1.dist == h2.dist) ? (h1.price < h2.price) : (h1.dist < h2.dist));
}

Hotel hotels[10010];

int main()
{
	int n;
	while (scanf("%d", &n), n > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &hotels[i].dist, &hotels[i].price);
		}
		sort(hotels, hotels + n);
		int sum(1);
		int pr(hotels[0].price);
		for (int i = 1; i < n; ++i)
		{
			if (hotels[i].dist > hotels[i - 1].dist)
			{
				if (pr > hotels[i].price)
				{
					pr = hotels[i].price;
					++sum;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
