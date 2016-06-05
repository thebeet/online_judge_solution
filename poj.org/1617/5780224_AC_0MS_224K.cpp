/*
 * Crypto_Columns.cpp
 *
 *  Created on: 2009-8-29
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

struct KeyChar
{
	char c;
	int id;
};

bool operator < (const KeyChar &kc1, const KeyChar &kc2)
{
	return ((kc1.c == kc2.c) ? (kc1.id < kc2.id) : (kc1.c < kc2.c));
}

char mat[128][128];

int main()
{
	for (string key; (cin >> key), key != "THEEND"; )
	{
		KeyChar kc[1024];
		for (int i = 0; i < key.size(); ++i)
		{
			kc[i].c = key[i];
			kc[i].id = i;
		}
		sort(kc, kc + key.size());
		string ciphertext;
		cin >> ciphertext;
		int m = ciphertext.size() / key.size();
		memset(mat, 0, sizeof(mat));
		for (int i = 0; i <  key.size(); ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				mat[j][kc[i].id] = ciphertext[i * m + j];
			}
		}
		for (int i = 0; i < m; ++i)
		{
			cout << mat[i];
		}
		cout << endl;
	}
	return 0;
}
