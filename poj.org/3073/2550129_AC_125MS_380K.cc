#include <iostream>
#include <string>

using namespace std;
string assign[256];
string inp;
string inp_t;

int ans[1024];

void init()
{
	assign[(int)'A'] = "4";
	assign[(int)'B'] = "|3";
	assign[(int)'C'] = "(";
	assign[(int)'D'] = "|)";
	assign[(int)'E'] = "3";
	assign[(int)'F'] = "|=";
	assign[(int)'G'] = "6";
	assign[(int)'H'] = "#";
	assign[(int)'I'] = "|";
	assign[(int)'J'] = "_|";
	assign[(int)'K'] = "|<";
	assign[(int)'L'] = "|_";
	assign[(int)'M'] = "|\\/|";
	assign[(int)'N'] = "|\\|";
	assign[(int)'O'] = "0";
	assign[(int)'P'] = "|0";
	assign[(int)'Q'] = "(,)";
	assign[(int)'R'] = "|?";
	assign[(int)'S'] = "5";
	assign[(int)'T'] = "7";
	assign[(int)'U'] = "|_|";
	assign[(int)'V'] = "\\/";
	assign[(int)'W'] = "\\/\\/";
	assign[(int)'X'] = "><";
	assign[(int)'Y'] = "-/";
	assign[(int)'Z'] = "2";
}

int main()
{
	init();
	while ((cin >> inp), inp != "end")
	{
		int i, j;
		inp_t = "";
		for (i = 0; i < inp.size(); ++i)
		{
			inp_t += assign[(int)inp[i]];
		}
		
		memset(ans, 0, sizeof(ans));
		ans[0] = 1;
		for (i = 1; i <= inp_t.size(); ++i)
		{
			for (j = 'A'; j <= 'Z'; ++j)
			{
				if (assign[j].size() <= i)
				{
					if (assign[j] == inp_t.substr(i - assign[j].size(), assign[j].size()))
					{
						ans[i] += ans[i - assign[j].size()];
					}
				}
			}
		}
		cout << ans[inp_t.size()] << endl;
	}
	return 0;
}
