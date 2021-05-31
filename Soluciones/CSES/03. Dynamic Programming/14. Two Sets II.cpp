#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const int MAXN = 501, MOD = (1E9 + 7) * 2, MAXS = 126000, MAXR = MAXS * 2 + 1;
int main(){
  int n;
  ll aux = 0;
  int dp[MAXN][MAXR];
  forn(i, MAXN) forn(j, MAXR) dp[i][j] = 0;
  cin>>n;
  dp[0][MAXS] = 1;
  for(int i = 1; i <= n; i++){
    forn(j, MAXR){
      if(j + i < MAXR){
        aux = ll(dp[i][j + i]) + dp[i - 1][j];
        aux %= MOD;
        dp[i][j + i] = aux;
      }
      if(j - i >= 0){
        aux = ll(dp[i][j - i]) + dp[i - 1][j];
        aux %= MOD;
        dp[i][j - i] = aux;
      }
    }
  }
  /*for(int j = MAXR - 1; j >= 0; j--){
    for(int i = 0; i <= n; i++){
      cout<<dp[i][j]<<" ";
    }
    cout<<"\n";
  }*/
  cout<<(dp[n][MAXS] / 2)<<"\n";
  return 0;
}