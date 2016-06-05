#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
    int r, x, y;
    cin >> hex >> r >> dec;
    cin.ignore(1, ',');
    cin >> x; 
    cin.ignore(1, ',');
    cin >> y;

    r &= 0xffffffff ^ (0x1 << x);
    r &= 0xffffffff ^ (0x1 << (y-2));
    r |= 0x3 << (y-1);
    
    cout << hex << r << endl;
    return 0;

}
