#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[55][55][55];
ll obtener(int n, int k, int m){
	if(n < 1) return 0;
	if(dp[n][k][m] != -1) return dp[n][k][m];
	if(k == 1){
		ll res = (m >= n)? 1 : 0;
		dp[n][k][m] = res;
		return res;
	}
	ll res = 0;
	for(int i = max(1, n - m); i < n; i++) res += obtener(i, k - 1, m);
	dp[n][k][m] = res;
	return res;
}
int main(){
	memset(dp, -1, sizeof(dp));
	int n, k, m;
	while(cin>>n){
		cin>>k>>m;
		cout<<obtener(n, k, m)<<endl;
	}
}
