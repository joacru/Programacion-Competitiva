#include<bits/stdc++.h>
using namespace std;
const int MOD = 1E9 + 7;
int main(){
	int n;
	long long res = 1;
	cin>>n;
	while(n--) res *= 2, res %= MOD;
	cout<<res<<"\n";
	return 0;
}
