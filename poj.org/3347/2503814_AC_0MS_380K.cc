#include <iostream>

using namespace std;

int length[100];
int pos[100];
struct color
{
	int id;
	int height;
}view[7000];

#define d 100

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

void cover(int f, int t, int height, int id)
{
	int i;
	for (i = f; i <= t; ++i)
	{
		if (view[i + d].height < height)
		{
			view[i + d].height = height;
			view[i + d].id = id;
		}
	}
}			

bool appear[100];
int ans[100];

int main()
{
	int i, j, n;
	while ((cin >> n), n > 0)
	{
		memset(length, 0, sizeof(length));
		memset(view, 0, sizeof(view));
		
		cin >> length[1];
		pos[1] = length[1];
		length[1] <<= 1;
		
		cover(1, length[1], length[1], 1);
			
		for (i = 2; i <= n; ++i)
		{
			cin >> length[i];
			length[i] <<= 1;
			
			pos[i] = 0;
			for (j = i - 1; j >= 1; --j)
			{
				if (length[i] <= length[j])
				{
					pos[i] = MAX(pos[i], pos[j] + length[i]);
					break;
				}
				if ((length[i] << 1) <= length[j])
				{
					pos[i] = MAX(pos[i], pos[j] + length[j]);
					break;
				}
				pos[i] = MAX(pos[i], pos[j] + length[j]);
			}
			cover(pos[i] - (length[i] >> 1) + 1, pos[i] + (length[i] >> 1), length[i], i);	
		}
		
		memset(appear, false, sizeof(appear));
		
		for (i = 1; i <= 5000; ++i)
		{
			appear[view[i].id] = true;
		}
		
		memset(ans, 0, sizeof(ans));
		for (i = 1; i <= n; ++i)
		{
			if (appear[i])
			{
				ans[++ans[0]] = i;
			}
		}
		
		for (i = 1; i < ans[0]; ++i)
		{
			cout << ans[i] << " ";
		}
		cout << ans[i] << endl;
	}
	return 0;
}
