#include <iostream>
#include <string>

using namespace std;

char isend[262144];
int queue[262144];
bool who[262144];

bool issame(int st, int a, int b, int c)
{
	int sa = (st & (3 << (a << 1))) >> (a << 1);
	int sb = (st & (3 << (b << 1))) >> (b << 1);
	int sc = (st & (3 << (c << 1))) >> (c << 1);
	if ((sa == sb) && (sa == sc) && (sa != 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkisend(int st)
{
	int i;
	for (i = 0; i < 9; ++i)
	{
		if ((st & (3 << (i << 1))) == 0)
		{
			break;
		}
	}
	if (i == 9)
	{
		return true;
	}
	return (issame(st, 0, 1, 2) || issame(st, 3, 4, 5) || issame(st, 6, 7, 8) ||
			issame(st, 0, 3, 6) || issame(st, 1, 4, 7) || issame(st, 2, 5, 8) ||
			issame(st, 2, 4, 6) || issame(st, 0, 4, 8));
}

int main()
{
	int i, j;
	memset(isend, 0, sizeof(isend));
	memset(queue, 0, sizeof(queue));
	memset(who, false, sizeof(who));
	queue[0] = 1;
	who[1] = true;
	queue[1] = 0;
	isend[0] = 1;
	for (i = 1; i <= queue[0]; ++i)
	{
		int cv = 1;
		if (who[i])
		{
			cv <<= 1;
		}
		for (j = 0; j < 9; ++j)
		{
			if ((queue[i] & (11 << (j << 1))) == 0)
			{
				if (isend[queue[i] | (cv << (j << 1))] == 0)
				{
					queue[++queue[0]] = queue[i] | (cv << (j << 1));
					who[queue[0]] = !who[i];
					if (checkisend(queue[queue[0]]) == true)
					{
						isend[queue[queue[0]]] = 2;
						--queue[0];
					}
					else
					{
						isend[queue[queue[0]]] = 1;
					}
				}
			}
		}
	}
	
	string inp;
	while ((cin >> inp), inp != "end")
	{
		int st = 0;
		for (i = 0; i < 9; ++i)
		{
			if (inp[i] == 'X')
			{
				st |= (2 << (i << 1));
			}
			else if (inp[i] == 'O')
			{
				st |= (1 << (i << 1));
			}
		}
		if (isend[st] == 2)
		{
			cout << "valid" << endl;
		}
		else
		{
			cout << "invalid" << endl;
		}
	}
	return 0;
}
