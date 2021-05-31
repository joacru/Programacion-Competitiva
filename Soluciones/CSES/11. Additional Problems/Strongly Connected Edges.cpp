#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define forit(i, a, n) for(int i = a; i <= n; i++)
using namespace std;
const int MAXN = 1E5 + 5, MAXM = 2E5 + 5;
struct edge{
  int u, v;
  int getTo(int x){
    return (x ^ u) ^ v;
  }
  void setFrom(int x){
    if(v == x) swap(u, v);
  }
};
int dfsN[MAXN], dfsM[MAXN], dfsC = 0;
vector<int> adj[MAXN];
edge edges[MAXM];
void dfs(int u, int p){
  dfsN[u] = dfsM[u] =  ++dfsC;
  for(int x : adj[u]){
    int v = edges[x].getTo(u);
    if(dfsN[v] == 0){
      edges[x].setFrom(u);
      dfs(v, u);
      dfsM[u] = min(dfsM[u], dfsM[v]);
      if(dfsN[u] < dfsM[v]){
        cout<<"IMPOSSIBLE\n";
        exit(0);
      }
    } else if(v != p && dfsN[u] > dfsN[v]){
      dfsM[u] = min(dfsM[u], dfsN[v]);
      edges[x].setFrom(u);
      //cout<<"Seteado: "<<u<<" "<<edges[x].u<<" "<<edges[x].v<<"\n";
    }
  }
}
int main(){
  int n, m;
  cin>>n>>m;
  forn(i, m){
    int a, b;
    cin>>a>>b;
    edges[i] = {a, b};
    adj[a].push_back(i);
    adj[b].push_back(i);
  }
  dfs(1, 0);
  forit(i, 1, n){
    if(dfsN[i] == 0){
      cout<<"IMPOSSIBLE\n";
      return 0;
    }
  }
  forn(i, m) cout<<edges[i].u<<" "<<edges[i].v<<"\n";
  return 0;
}