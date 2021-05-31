#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define forit(i, a, n) for(int i = a; i <= n; i++)
using namespace std;
typedef long long ll;
const ll INF = 1E18;
int main(){
  int n;
  cin>>n;
  ll add[n + 1], dp[n + 1][n + 1];
  add[0] = 0;
  forit(i, 1, n){
    int x;
    cin>>x;
    add[i] = add[i - 1] + x;
  }
  //[a, b]
  forn(k, n){ //Inicio
    forit(i, 1, n){ //Final
      int j = i + k;
      if(j > n) break;
      if(i == j){
        dp[i][j] = add[j] - add[i - 1];
        continue;
      }
      ll score = -INF, sum = add[j] - add[i - 1];
      score = max(score, sum - dp[i + 1][j]);
      score = max(score, sum - dp[i][j - 1]);
      dp[i][j] = score;
    }
  }
  /*forit(i, 1, n){
    forit(j, 1, n){
      cout<<dp[i][j]<<" ";
    }
    cout<<"\n";
  }*/
  cout<<dp[1][n]<<"\n";
  return 0;
}