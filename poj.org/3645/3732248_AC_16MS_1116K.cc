#include <iostream>
#include <string>
#include <sstream>

using namespace std;

char buf[1024];

double input(istream &in)
{
	char c;
	in >> c;
	if (c != '(')
	{
		in.putback(c);
		double d;
		in >> d;
		return d;
	}
	else
	{
		double e, p1, p2;
		e = input(in);
		p1 = input(in);
		p2 = input(in);
		in >> c;
		return (p1 + p2 * e - p2 * (1 - e));
	}
}

int main()
{	
	while (cin.getline(buf, 1024))
	{
		string inp(buf);
		if (inp == string("()"))
		{
			return 0;
		}	
		stringstream sstrm(inp);
		printf("%.2lf\n", input(sstrm));
	}
	return 0;
}