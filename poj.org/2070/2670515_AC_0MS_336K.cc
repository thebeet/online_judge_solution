#include <iostream>
#include <string>

using namespace std;

int main()
{
	double sp, wei, str;
	while (cin >> sp >> wei >> str)
	{
		string ans("");
		if ((sp + wei + str) < 1e-10)
		{
			return 0;
		}
		if ((sp < 4.5 + 1e-10) && (wei > 150.0 - 1e-10) && (str > 200 - 1e-10))
		{
			ans += "Wide Receiver ";
		}
		if ((sp < 6.0 + 1e-10) && (wei > 300.0 - 1e-10) && (str > 500 - 1e-10))
		{
			ans += "Lineman ";
		}
		if ((sp < 5.0 + 1e-10) && (wei > 200.0 - 1e-10) && (str > 300 - 1e-10))
		{
			ans += "Quarterback ";
		}
		if (ans == "")
		{
			ans = "No positions";
		}
		else
		{
			ans = ans.substr(0, ans.size() - 1);
		}
		cout << ans << endl;
	}
}
