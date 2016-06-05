#include <stdio.h>

#include <string.h>

#include <iostream>

#include <algorithm>



#define INT long long

#define fmt "%lld"



using namespace std;



#define SIZE 4096



class t_TreeList

{

public:

	void init(const INT n)

	{

		 memset(data, 0, sizeof(data));

		 size = n - 1;

	}

	virtual ~t_TreeList()

	{

	}

	void add(INT k, INT newdata)

	{

		while (k <= size)

		{

			data[k] += newdata;

			k += lowbit(k);

		}

	}

	INT getsum(INT k) //get sum for 1 to k

	{

		INT sum = 0;

		while (k > 0)

		{

			sum += data[k];

			k -= lowbit(k);

		}

		return sum;

	}

	INT getsum(INT f, INT t) //get sum for f to t

	{

		return (getsum(t) - getsum(f - 1));

	}

	

private:

	INT data[SIZE];

	INT size;

	INT lowbit(const INT x)

	{

		return (x & (x ^ (x - 1)));

	}

};



t_TreeList treelist;

INT inp[SIZE][SIZE];



int main()

{

	INT tn;

	scanf(fmt, &tn);

	for (INT ti = 1; ti <= tn; ++ti)

	{

		INT i, n, m, k;

		scanf(fmt fmt fmt, &n, &m, &k);

		treelist.init(m);

		for (i = 1; i <= k; ++i)

		{

			INT f, t;

			scanf(fmt fmt, &f, &t);

			inp[f][++inp[f][0]] = t;

		}

		

		INT ans = 0;

		for (i = 1; i <= n; ++i)

		{

			for (INT j = 1; j <= inp[i][0]; ++j)

			{

				ans += treelist.getsum(m - inp[i][j]);

			}

			for (INT j = 1; j <= inp[i][0]; ++j)

			{

				treelist.add(m - inp[i][j] + 1, 1);

			}

		}

		printf("Test case " fmt ": " fmt "\n", ti, ans);

	}

	return 0;

}

