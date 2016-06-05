/*
 * Anagrammatic_Distance.cpp
 *
 *  Created on: Sep 25, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char inp1[1024];
char inp2[1024];

int total[256];

int main()
{
	int n;
	scanf("%d", &n);
	fgets(inp1, 1024, stdin);
	for (int i = 0; i < n; ++i)
	{
		memset(total, 0, sizeof(total));
		fgets(inp1, 1024, stdin);
		fgets(inp2, 1024, stdin);
		for (char *c = inp1; *c != '\0'; ++c)
		{
			++total[(int)*c];
		}
		for (char *c = inp2; *c != '\0'; ++c)
		{
			--total[(int)*c];
		}
		for (char c = 'a'; c != 'z'; ++c)
		{
			total[0] += abs(total[(int)c]);
		}
		printf("Case #%d:  %d\n", i + 1, total[0]);
	}
	return 0;
}
