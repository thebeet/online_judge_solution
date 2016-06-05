#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

long b,N;
double K = -1;

double myabs(const double a){
	return (a < 0)? -a : a;
}

int main(){
	//freopen("1010.in","r",stdin);
	//freopen("1010.out","w",stdout);
	double o,now;
	//read
		cin >> N >> o;
	//main
		long f;
		for(f=1;f<N;++f){
			cin >> now;
			if (myabs(o - now) > K){
				K = myabs(o - now);
				b = f;
			}
			o = now;
		}
	//print
		cout << b << ' ' << b + 1 << endl;
	return 0;
}
