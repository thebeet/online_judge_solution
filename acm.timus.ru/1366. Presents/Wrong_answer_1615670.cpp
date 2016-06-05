#include <stdio.h>
#include <string.h>

#define MAXN 1000
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
	hp1[1] = n