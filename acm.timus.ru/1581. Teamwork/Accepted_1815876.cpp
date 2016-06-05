#include <iostream>

#include <algorithm>



using namespace std;



int main()

{

	int i, n, pr, s, m;

	s = 1;

	cin >> n >> pr;

	for (i = 2; i <= n; ++i)

	{

		cin >> m;

		if (m == pr)

		{

			++s;

		}

		else

		{

			cout << s << " " << pr << " ";

			s = 1;

			pr = m;

		}

	}

	cout << s << " " << pr;

	return 0;

}


