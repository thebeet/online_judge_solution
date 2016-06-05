#include <iostream>

using namespace std;

int main()
{
	char inp;
	int x, y, dx, dy;
	while (scanf("%c", &inp) != EOF)
	{
		x = 300;
		y = 420;
		dx = 10;
		dy = 0;
		cout << x << " " << y << " moveto" << endl;
		x += dx;
		cout << x << " " << y << " lineto" << endl;
		if (inp == 'A')
		{
			int tx = dx;
			int ty = dy;
			dx = ty;
			dy = -tx;
		}
		else
		{
			int tx = dx;
			int ty = dy;
			dx = -ty;
			dy = tx;
		}
		x += dx;
		y += dy;
		cout << x << " " << y << " lineto" << endl;
		while (scanf("%c", &inp), inp != '\n')
		{
			if (inp == 'A')
			{
				int tx = dx;
				int ty = dy;
				dx = ty;
				dy = -tx;
			}
			else
			{
				int tx = dx;
				int ty = dy;
				dx = -ty;
				dy = tx;
			}
			x += dx;
			y += dy;
			cout << x << " " << y << " lineto" << endl;
		}
		cout << "stroke" << endl << "showpage" << endl;
	}
	return 0;
}
