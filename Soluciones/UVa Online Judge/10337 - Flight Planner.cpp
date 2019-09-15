#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
const int MAXN = 1010, MAXA = 10, INF = 1E8;
int main(){
	int T, n, valaux;
	cin>>T;
	int dp[MAXN][MAXA], val[MAXN][MAXA];
	while(T--){
		memset(dp, 100000000, sizeof(dp));
		cin>>n;
		n /= 100;
		for(int e = MAXA - 1; e >= 0; e--) forn(i, n){
			cin>>val[i][e];
			dp[i][e] = INF;
		}
		dp[n][0] = INF;
		dp[0][0] = 0;
		forn(i, n){
			forn(e, MAXA){
				if(dp[i][e] == INF) continue;
				valaux = dp[i][e] - val[i][e];
				//Arriba
				if(e < 9) dp[i + 1][e + 1] = min(dp[i + 1][e + 1], valaux + 60);
				//Mantiene
				dp[i + 1][e] = min(dp[i + 1][e], valaux + 30);
				//Abajo
				if(e > 0) dp[i + 1][e - 1] = min(dp[i + 1][e - 1], valaux + 20);
			}
		}
		cout<<dp[n][0]<<endl<<endl;
	}
}
