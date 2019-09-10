#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 101;
const int MOD =  1000000;
ll dp[MAX][MAX]; //[N][K]
ll maneras(int n, int k){
	if(dp[n][k] != -1) return dp[n][k];
	if(k == 1){
		dp[n][k] = 1;
		return dp[n][k];
	}
	dp[n][k] = 0;
	for(int i = 0; i <= n; i++){
		dp[n][k] += maneras(n - i, k - 1);
		dp[n][k] %= MOD;
	}
	return dp[n][k];
}
int main(){
	int n, k;
	memset(dp, -1, sizeof(dp));
	cin>>n>>k;
	while(n != 0 || k != 0){
		cout<<maneras(n, k)<<endl;
		cin>>n>>k;
	}
}
