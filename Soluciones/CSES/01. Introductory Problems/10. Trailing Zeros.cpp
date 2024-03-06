#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n, x, res = 0;
	cin>>n;
	x = 5;
	while(x <= n){
		res += n / x;
		x *= 5;
	}
	cout<<res<<"\n";
	return 0;
}
