#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
const int MAXN = 2E5 + 5;
int res[MAXN], parent[MAXN];
set<int> colors[MAXN];
vector<int> adj[MAXN];
int merge(int u, int v){
  u = parent[u], v = parent[v];
  if(colors[u].size() < colors[v].size()) swap(u, v);
  for(int x : colors[v]) colors[u].insert(x);
  return u;
}
void dfs(int u, int p){
  for(int v : adj[u]){
    if(v == p) continue;
    dfs(v, u);
    parent[u] = merge(u, v);
  }
  res[u] = colors[parent[u]].size();
}
int main(){
  int n, m;
  cin>>n;
  m = n;
  forn(i, n){
    int c;
    cin>>c;
    colors[i].insert(c);
    parent[i] = i;
  }
  while(--m){
    int u, v;
    cin>>u>>v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, 0);
  forn(i, n) cout<<res[i]<<" ";
  cout<<"\n";
  return 0;
}