#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	char c;
	string inp("");
	int tram(0);
	int trolleybus(0);
	while (scanf("%c", &c) != EOF)
	{
		if ((c >= 'a') && (c <= 'z'))
		{
			inp += c;
		}
		else
		{
			if (inp == "tram")
			{
				++tram;
			}
			else if (inp == "trolleybus")
			{
				++trolleybus;
			}
			inp = "";
		}
	}
	if (inp == "tram")
	{
		++tram;
	}
	else if (inp == "trolleybus")
	{
		++trolleybus;
	}
	if (tram > trolleybus)
	{
		cout << "Tram";
	}
	else if (tram < trolleybus)
	{
		cout << "Trolleybus";
	}
	else
	{
		cout << "Bus";
	}
	cout << " driver" << endl;
	return 0;
}
