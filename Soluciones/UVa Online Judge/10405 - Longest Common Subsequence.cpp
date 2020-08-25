#include<bits/stdc++.h>
using namespace std;
int main(){
	string s, t;
	while(getline(cin, s) && getline(cin, t)){
		int n = s.size(), m = t.size();
		int dp[n + 1][m + 1];
		for(int i = 0; i <= n; i++) dp[i][0] = 0;
		for(int i = 0; i <= m; i++) dp[0][i] = 0;
		for(int i = 1; i <= n; i++){
			for(int e = 1; e <= m; e++){
				dp[i][e] = max(dp[i - 1][e], dp[i][e - 1]);
				if(s[i - 1] == t[e - 1]){
					dp[i][e] = max(dp[i][e], dp[i - 1][e - 1] + 1);
				}
			}
		}
		cout<<dp[n][m]<<"\n";
	}
	return 0;
}
