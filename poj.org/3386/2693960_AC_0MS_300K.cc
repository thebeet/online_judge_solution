#include <iostream>

using namespace std;

int main()
{
	int a, b, A, B, p;
	cin >> A >> a >> B >> b >> p;
	if (A > B)
	{
		swap(A, B);
		swap(a, b);
	}
	if ((p >= B) && ((b >= A) || (p >= (A + B))))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}
