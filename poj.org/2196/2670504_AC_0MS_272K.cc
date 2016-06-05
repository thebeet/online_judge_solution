#include <iostream>

using namespace std;

int main()
{
	int i;
	for (i = 2992; i <= 9999; ++i)
	{
		int ti, id, ih, it;
		int dec, hex, twl;
		dec = hex = twl = 0;
		id = ih = it = i;
		for (ti = 1; ti <= 4; ++ti)
		{
			dec += id % 10;
			hex += ih % 16;
			twl += it % 12;
			id /= 10;
			ih /= 16;
			it /= 12;
		}
		if ((dec == hex) && (hex == twl))
		{
			cout << i << endl;
		}
	}
	return 0;
}
