#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, string> morse;
map<string, char> inmorse;
void init()
{
	morse['A'] = ".-";
	morse['B'] = "-...";
	morse['C'] = "-.-.";
	morse['D'] = "-..";
	morse['E'] = ".";
	morse['F'] = "..-.";
	morse['G'] = "--.";
	morse['H'] = "....";
	morse['I'] = "..";
	morse['J'] = ".---";
	morse['K'] = "-.-";
	morse['L'] = ".-..";
	morse['M'] = "--";
	morse['N'] = "-.";
	morse['O'] = "---";
	morse['P'] = ".--.";
	morse['Q'] = "--.-";
	morse['R'] = ".-.";
	morse['S'] = "...";
	morse['T'] = "-";
	morse['U'] = "..-";
	morse['V'] = "...-";
	morse['W'] = ".--";
	morse['X'] = "-..-";
	morse['Y'] = "-.--";
	morse['Z'] = "--..";
	for (char i = 'A'; i <= 'Z'; ++i)
	{
		inmorse[morse[i]] = i;
	}
	morse['_'] = "..--";
	morse['.'] = "---.";
	morse[','] = ".-.-";
	morse['?'] = "----";
	inmorse[morse['_']] = '_';
	inmorse[morse['.']] = '.';
	inmorse[morse[',']] = ',';
	inmorse[morse['?']] = '?';
}

int main()
{
	string inp;
	string mos;
	int lens[128];
	int ti, tn;
	init();
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i;
		cin >> inp;
		mos = "";
		for (i = 0; i < inp.size(); ++i)
		{
			mos += morse[inp[i]];
			lens[i] = morse[inp[i]].size();
		}
		int p = 0;
		for (i = inp.size() - 1; i >= 0; --i)
		{
			cout << inmorse[mos.substr(p, lens[i])];
			p += lens[i];
		}
		cout << endl;
	}
	return 0;
}
