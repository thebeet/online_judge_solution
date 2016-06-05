#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    double k[4];
    cin >> k[1] >> k[2] >> k[3];
    cout << (int)(1000.0 / (1.0 / k[1] + 1.0 / k[2] + 1.0 / k[3]) + 0.5) << endl;
    return 0;
}
