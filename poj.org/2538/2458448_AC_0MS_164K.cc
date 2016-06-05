#include <stdio.h>

char change[300];

int main()
{
	for (int i = 0; i <= 255; ++i)
	{
		change[i] = i;
	}
	change[(int)'1'] = '`';
	change[(int)'2'] = '1';
	change[(int)'3'] = '2';
	change[(int)'4'] = '3';
	change[(int)'5'] = '4';
	change[(int)'6'] = '5';
	change[(int)'7'] = '6';
	change[(int)'8'] = '7';
	change[(int)'9'] = '8';
	change[(int)'0'] = '9';
	change[(int)'-'] = '0';
	change[(int)'='] = '-';
	
	change[(int)'W'] = 'Q';
	change[(int)'E'] = 'W';
	change[(int)'R'] = 'E';
	change[(int)'T'] = 'R';
	change[(int)'Y'] = 'T';
	change[(int)'U'] = 'Y';
	change[(int)'I'] = 'U';
	change[(int)'O'] = 'I';
	change[(int)'P'] = 'O';
	change[(int)'['] = 'P';
	change[(int)']'] = '[';
	change[(int)'\\'] = ']';
	
	change[(int)'S'] = 'A';
	change[(int)'D'] = 'S';
	change[(int)'F'] = 'D';
	change[(int)'G'] = 'F';
	change[(int)'H'] = 'G';
	change[(int)'J'] = 'H';
	change[(int)'K'] = 'J';
	change[(int)'L'] = 'K';
	change[(int)';'] = 'L';
	change[(int)'\''] = ';';
	
	change[(int)'X'] = 'Z';
	change[(int)'C'] = 'X';
	change[(int)'V'] = 'C';
	change[(int)'B'] = 'V';
	change[(int)'N'] = 'B';
	change[(int)'M'] = 'N';
	change[(int)','] = 'M';
	change[(int)'.'] = ',';
	change[(int)'/'] = '.';
	
	char inp;
	while (scanf("%c", &inp) != EOF)
	{
		printf("%c", change[(int)inp]);
	}
	return 0;
}
