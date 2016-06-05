#include <iostream>
using namespace std;
int main()
{int n;while(cin >> n){if(n<=4){cout<<n-1<<endl;for(int i=1;i<n;++i){cout<<"1 1 "<<n-i<<endl;}}else{cout<<(n/2)+1<<endl;if((n&1)==0){cout<<"1 1 "<<n-1<<endl;--n;}for(int i=0;i<(n/2);++i){cout<<1+i+(n/2)<<" 2 "<<i<<endl;}cout<<1+(n/2)<<" "<<(n/2)<<" 0"<<endl;}}return 0;}
