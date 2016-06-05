#include <iostream>

using namespace std;

int seq[65536];

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, j, n, st, ed;
		cin >> n;
		st = 1;
		ed = 1;
		
		for (i = n; i >= 1; --i)
		{
			seq[ed++] = i;
			for (j = 1; j <= i; ++j)
			{
				seq[ed++] = seq[st++];
			}
		}
		for ( --ed; ed > st; --ed)
		{
			cout << seq[ed] << " ";
		}
		cout << seq[ed] << endl;
	}
	return 0;
}
