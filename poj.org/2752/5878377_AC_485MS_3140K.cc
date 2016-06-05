/*
 * string.cpp
 *
 *  Created on: 2009-9-18
 *      Author: Administrator
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int KMPGenNext(const char str[], const int len, int next[])
{
	int i(0), j(-1);
	next[0] = -1;
	while (i < len)
	{
		while ((j >= 0) && (str[i] != str[j]))
		{
			j = next[j];
		}
		next[++i] = ++j;
		/*++i; ++j;
		if (str[i] == str[j])
		{
			next[i] = next[j];
		}
		else
		{
			next[i] = j;
		}*/
	}
}

int KMP(const char str1[], const int len1, const char str2[], const int len2)
{
	int *next = new int[len2];
	KMPGenNext(str2, len2, next);
	int j(-1);
	for (int i = 0; i < len1; ++i)
	{
		while ((j >= 0) && (str2[j + 1] != str2[i]))
		{
			j = next[j];
		}
		if (str2[j + 1] == str2[i]) ++j;
		if (j == len2)
		{
			return i - len2;
		}
	}
	return -1;
}

char inp[400010];
int next[400010];
int ans[400010];

int main()
{
	while (scanf("%s", inp) != EOF)
	{
		int n = strlen(inp);
		KMPGenNext(inp, n, next);
		int ansn(0);
		int p(n);
		for (int p = n; p > 0; p = next[p])
		{
			ans[ansn++] = p;
		}
		for (int i = ansn - 1; i >= 0; --i)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
