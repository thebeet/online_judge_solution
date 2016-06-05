#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char fmt[65536];
char oup[524288];
char buf[65536];
int dx = 0;

int main()
{
	//freopen("inp", "r", stdin);
	gets(fmt);
	for (char *i = fmt; ((*i != '\0') && (*i != '\n')); ++i)
	{
		if ((*i) == '%')
		{
			++i;
			switch (*i)
			{
				case '%':
				{
					oup[dx++] = '%';
					break;
				}
				case 's':
				{
					if ((gets(buf) == NULL) || (buf[0] == '\n') || (buf[0] == '\0'))
					{
						printf("ERROR\n");
						return 0;
					}
					sscanf(buf, "%s", oup + dx);
					while (oup[dx] != '\0')
					{
						++dx;
					}
					break;
				}
				case 'd':
				{
					if ((gets(buf) == NULL) || (buf[0] == '\n') || (buf[0] == '\0'))
					{
						printf("ERROR\n");
						return 0;
					}
					int tmp = 0;
					for (char *i = buf; ((*i != '\0') && (*i != '\n')); ++i)
					{
						if (((*i) > '9') || ((*i) < '0'))
						{
							printf("ERROR\n");
							return 0;
						}
						(tmp *= 10) += (*i - '0');
					}
					sprintf(oup + dx, "%d", tmp);
					while (oup[dx] != '\0')
					{
						++dx;
					}
					break;
				}
				default:
				{
					printf("ERROR\n");
					return 0;
				}
			}
		}
		else
		{
			oup[dx++] = *i;
		}
	}
	if ((gets(buf) == NULL) || (buf[0] == '\n') || (buf[0] == '\0'))
	{
		printf("%s\n", oup);
	}
	else
	{
		printf("ERROR\n");
	}
	return 0;
}
