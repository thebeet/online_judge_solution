#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int notes_value[6] = {10, 50, 100, 500, 1000, 5000};
int notes_number[6];

int main()
{
	int firstnonezero = 6;
	for (int i = 0; i < 6; ++i)
	{
		cin >> notes_number[i];
		if ((firstnonezero > i) && (notes_number[i] > 0))
		{
			firstnonezero = i;
		}
	}
	int ticket;
	cin >> ticket;
	int sum = 0;
	for (int i = 5; i >= 0; --i)
	{
		sum += notes_number[i] * notes_value[i];	
	}
	int sum2 = sum - notes_value[firstnonezero];
	int total = sum / ticket;
	int total2 = sum2 / ticket;
	cout << total - total2 << endl;
	for (int i = total2 + 1; i <= total; ++i)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
