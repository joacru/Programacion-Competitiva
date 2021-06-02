#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
const int MAXN = 1E5 + 5, MAXM = 2E5 + 5;
struct edge{
  int u, v;
};
int vis[MAXN], comp[MAXN], compC = 0;
edge edges[MAXM];
vector<int> adj[MAXN];
stack<int> kos;
void dfsOne(int u){
  vis[u] = 1;
  for(int x : adj[u]){
    int v = edges[x].v;
    if(u == v || vis[v]) continue;
    dfsOne(v);
  }
  kos.push(u);
}
void dfsTwo(int u){
  comp[u] = compC;
  for(int x : adj[u]){
    int v = edges[x].u;
    if(u == v || comp[v]) continue;
    dfsTwo(v);
  }
}
int main(){
  int n, m;
  cin>>n>>m;
  forn(i, m){
    int u, v;
    cin>>u>>v;
    u--, v--;
    edges[i] = {u, v};
    adj[u].push_back(i);
    adj[v].push_back(i);
  }
  forn(i, n){
    if(vis[i]) continue;
    dfsOne(i);
  }
  while(kos.size()){
    int u = kos.top();
    kos.pop();
    if(comp[u]) continue;
    compC++;
    dfsTwo(u);
  }
  cout<<compC<<"\n";
  forn(i, n) cout<<comp[i]<<" ";
  cout<<"\n";
  return 0;
}