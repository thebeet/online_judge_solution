#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1("Emperor");
    string s2("Macaroni");
    string s3("Little");
    
    int i, n;
    int m1, m2, m3;
    m1 = m2 = m3 = 0;
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
	string sinp;
	cin >> sinp;
	if (sinp == s1) ++m1;
	if (sinp == s2) ++m2;
	if (sinp == s3) ++m3;
	cin >> sinp;
    }
    if ((m1 > m2) && (m1 > m3))
    {
	cout << s1 << " " << "Penguin" << endl; 
    }
    if ((m2 > m1) && (m2 > m3))
    {
	cout << s2 << " " << "Penguin" << endl; 
    }
    if ((m3 > m2) && (m3 > m1))
    {
	cout << s3 << " " << "Penguin" << endl; 
    }
    return 0;
}