#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	char c;
	while (scanf("%c", &c) != EOF)
	{
		switch (c)
		{
			case ' ':
			{
				printf("%%20");
				break;
			}
			case '!':
			{
				printf("%%21");
				break;
			}
			case '$':
			{
				printf("%%24");
				break;
			}
			case '%':
			{
				printf("%%25");
				break;
			}
			case '(':
			{
				printf("%%28");
				break;
			}
			case ')':
			{
				printf("%%29");
				break;
			}
			case '*':
			{
				printf("%%2a");
				break;
			}
			case '#':
			{
				return 0;
			}
			default:
			{
				printf("%c", c);
			}
		}
	}
	return 0;
}
