#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct person
{
	int v;
	string name;
}ps[32];

bool operator < (const person &p1, const person &p2)
{
	return (p1.v < p2.v);
}

int main()
{
	int i, n;
	while ((cin >> n), n > 0)
	{
		int x, y, z;
		for (i = 0; i < n; ++i)
		{
			cin >> x >> y >> z >> ps[i].name;
			ps[i].v = x * y * z;
		}
		sort(ps, ps + n);
		cout << ps[n - 1].name << " took clay from " << ps[0].name << "." << endl;
	}
	return 0;
}
