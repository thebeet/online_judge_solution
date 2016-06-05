#include <iostream>
#include <algorithm>
#include <cstring>

int main()
{
	for (int n; cin >> n, n > 0; )
	{
		cout << ((n >= 3) ? "Bob" : "Alice") << endl;
	}
	return 0;
}
