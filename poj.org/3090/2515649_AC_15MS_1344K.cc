#include <iostream>

using namespace std;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

bool map[1024][1024];
int s[1024];

int main()
{
	int i, j;
	memset(map, true, sizeof(map));
	memset(s, 0, sizeof(s));
	map[0][0] = false;
	s[1] = 1;
	
	for (i = 2; i <= 1000; ++i)
	{
		map[i][0] = false;
		map[0][i] = false;
	}
	for (i = 1; i <= 1000; ++i)
	{
		for (j = i + 1; j <= 1000; ++j)
		{
			if (map[i][j])
			{
				int ti = i + i;
				int tj = j + j;
				for ( ; (ti <= 1000) && (tj <= 1000); ti += i, tj += j)
				{
					map[ti][tj] = false;
				}
				++s[j];
			}
		}
	}
	for (i = 2; i <= 1000; ++i)
	{
		s[i] += s[i - 1];
	}
	
	int tn;
	cin >> tn;
	for (int ti = 1; ti <= tn; ++ti)
	{
		int n;
		cin >> n;
		cout << ti << " " << n << " " << s[n] * 2 + 1 << endl;
	}
	return 0;
}
