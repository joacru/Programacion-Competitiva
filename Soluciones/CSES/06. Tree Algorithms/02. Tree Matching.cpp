#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2E5 + 5;
int dp[MAXN][2];
vector<int> adj[MAXN];
void dfs(int u, int p){
  int sum = 0;
  for(int v : adj[u]){
    if(v == p) continue;
    dfs(v, u);
    sum += max(dp[v][0], dp[v][1]); //Suma el que no incluye
  }
  dp[u][0] = sum;
  for(int v : adj[u]){
    if(v == p) continue;
    dp[u][1] = max(dp[u][1], sum - max(dp[v][0], dp[v][1]) + dp[v][0] + 1);
  }
}
int main(){
  int n, m;
  cin>>n;
  m = n - 1;
  while(m--){
    int a, b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  cout<<max(dp[1][0], dp[1][1])<<"\n";
  return 0;
}