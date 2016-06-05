#include <cstdio>
#include <cstring>

typedef __int64 INT;
#define fmt "%I64d"

const int SIZE = 100010;

INT pp;

INT change(INT n)
{
	n %= pp;
	if (n < 0)
	{
		n += pp;
	}
	return n;
}

class t_TreeArray
{
public:
	void init(const INT n)
	{
		 memset(data, 0, sizeof(data[0]) * (n + 1));
		 size = n;
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

t_TreeArray ta, ta2, ta3, ta4;
INT ans[8];

void calc(INT k, INT l, INT r)
{
	ans[0] = 1;
	if (k == 0) return;
	INT s = change(ta.getsum(l, r));
	ans[1] = s;
	if (k == 1) return;
	INT s2 = change(ta2.getsum(l, r));
	ans[2] = change((s * s - s2) / 2);
	if (k == 2) return;
	INT s3 = change(ta3.getsum(l, r));
	ans[3] = change((ans[2] * s - s2 * s + s3) / 3);
	if (k == 3) return;
	INT s4 = change(ta4.getsum(l, r));
	ans[4] = change((ans[3] * s - s2 * ans[2] + s3 * s - s4) / 4);
	
}

int main()
{
	INT i, n, m, d;
	char op[4];
	scanf(fmt fmt fmt, &n, &m, &pp);
	ta.init(n);
	ta2.init(n);
	ta3.init(n);
	ta4.init(n);
	for (i = 1; i <= n; ++i)
	{
		INT dd;
		scanf(fmt, &d);
		d %= pp;
		ta.add(i, d);
		dd = (d * d) % pp;
		ta2.add(i, dd);
		(dd *= d) %= pp;
		ta3.add(i, dd);
		(dd *= d) %= pp;
		ta4.add(i, dd);
	}
	for (i = 1; i <= m; ++i)
	{
		scanf("%s", op);
		switch (op[0])
		{
			case 'C':
			{
				INT left, right, k, j;
				scanf(fmt fmt fmt, &left, &right, &k);
				calc(k, left, right);
				printf("1");
				for (j = 1; j <= k; ++j)
				{
					printf(" " fmt, ans[j]);
				}
				printf("\n");
				break;
			}
			case 'I':
			{
				INT id, d, dd, o, oo, nw;
				scanf(fmt fmt, &id, &d);
				o = ta.getsum(id, id);
				d += o;
				ta.add(id, d - o);
				dd = (d * d) % pp;
				oo = (o * o) % pp;
				ta2.add(id, dd - oo);
				(dd *= d) %= pp;
				(oo *= o) %= pp;
				ta3.add(id, dd - oo);
				(dd *= d) %= pp;
				(oo *= o) %= pp;
				ta4.add(id, dd - oo);
			}
		}
	}
	return 0;
}
