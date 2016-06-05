#include <stdio.h>
#include <string.h>

#define MAXN 2010
#define w 3

long hp[10][MAXN];
long rw, sizeL;

void hp_init()
{
	long i;
	memset(hp, 0, sizeof(hp));
	rw = 1;
	for (i = 1; i <= w; i++)
	{
		rw *= 10;
	}
	sizeL = MAXN * 4;
}

long mx(long a, long b)
{
	return (a > b) ? a : b;
}

void tzup(long hp1[])
{
	long i;
	for (i = 1; i <= hp1[0]; i++)
	{
		hp1[i + 1] += (hp1[i] / rw);
		hp1[i] %= rw;
	}
	while (hp1[hp1[0] + 1]>0)
	{
		hp1[0]++;
		hp1[hp1[0] + 1] += (hp1[hp1[0]] / rw);
		hp1[hp1[0]] %= rw;
	}
}

void tzdown(long hp1[])
{
	long i;
	for (i = 1; i <= hp1[0]; i++)
	{
		hp1[i + 1] += ((hp1[i] - rw + 1) / rw);
		hp1[i] = (hp1[i] % rw + rw) % rw;
	}
	while ((hp1[hp1[0]] == 0) && (hp1[0] > 1))
		hp1[0]--;
}

void hp_eq_hp(long hp1[], long hp2[])
{
	memcpy(hp1, hp2, sizeL);
}

void hp_eq_num(long hp1[], long n1)
{
	memset(hp1, 0, sizeL);
	hp1[0] = 1;
	hp1[1] = n1;
	tzup(hp1);
}

long hp_iseq_hp(long hp1[], long hp2[])
{
	long i,l;
	if (hp1[0] > hp2[0]) return 1;
	if (hp2[0] > hp1[0]) return -1;
	l = hp1[0];
	for (i = l; i >= 1; i--)
	{
		if (hp1[i] > hp2[i]) return 1;
		if (hp2[i] > hp1[i]) return -1;
	}
	return 0;
}

void hp_inp(long hp1[])
{
	long i, j, k, l, t;
	char inp[MAXN];
	memset(hp1, 0, sizeL);
	memset(inp, 0, sizeof(inp));
	scanf("%s", inp);
	l = strlen(inp);
	k = 0;
	for (i = l - 1; i >= 0;i -= w)
	{
		if (inp[i] == 0) break;
		k++;
		t = i - w + 1;
		if (t < 0) t = 0;
		for (j = t; j <= i; j++)
		{
			if (inp[i] > 0)
				hp1[k] = hp1[k] * 10 + inp[j] - 48;
		}
	}
	hp1[0] = k;
}

void hp_add_hp(long hp1[], long hp2[], long hp3[])//hp3 = hp1 + hp2
{
	long i, l;
	memset(hp3, 0, sizeL);
	l=mx(hp1[0], hp2[0]);
	for (i = 1; i <= l; i++)
		hp3[i] = hp1[i] + hp2[i];
	hp3[0] = l;
	tzup(hp3);
}

void hp_dec_hp(long hp1[], long hp2[], long hp3[]) //make sure hp1 > hp2
{
	long i, l;
	memset(hp3, 0, sizeL);
	l = hp1[0];
	for (i = 1; i <= l; i++)
		hp3[i] = hp1[i] - hp2[i];
	hp3[0] = hp1[0];
	tzdown(hp3);
}

void hp_mul_num(long hp1[], long n1, long hp2[])
{
	long i, l;
	memset(hp2, 0, sizeL);
	l = hp1[0];
	for (i = 1; i <= l; i++)
		hp2[i] = hp1[i] * n1;
	hp2[0] = l;
	tzup(hp2);
}

void hp_mul_hp(long hp1[], long hp2[], long hp3[])
{
	long