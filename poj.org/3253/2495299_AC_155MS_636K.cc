#include <iostream>

using namespace std;

#define INT long long

INT woods[20010];
INT queue[20010];
INT queueend;

int getmin()
{
	if (woods[woods[0]] < queue[queue[0]])
	{
		return woods[woods[0]++];
	}
	else
	{
		return queue[queue[0]++];
	}
}

int main()
{
	INT i, n;
	INT sum = 0;
	cin >> n;
	memset(woods, 1, sizeof(woods));
	woods[0] = 1;
	
	for (i = 1; i <= n; ++i)
	{
		cin >> woods[i];
	}
	
	sort(woods + 1, woods + 1 + n);
	
	memset(queue, 1, sizeof(queue));
	queue[0] = 1;
	queueend = 0;
	
	for (i = 1; i < n; ++i)
	{
		int minsum = getmin() + getmin();
		queue[++queueend] = minsum;
		sum += minsum;
	}
	
	cout << sum << endl;
	return 0;
}
