#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
const int MAXN = 1E5 + 5;
struct edge{
  int u, v, comp;
  bool lucky;
  int getTo(int x){
    return (u ^ v) ^ x;
  }
};
int dfsN[MAXN], dfsM[MAXN], bicC = 0;
vector<int> adj[MAXN];
vector<bool> lucky(MAXN);
edge edges[MAXN];
stack<int> forBic;
void dfs(int u, int l, int p){
  dfsN[u] = dfsM[u] = l;
  for(int x : adj[u]){
    int v = edges[x].getTo(u);
    if(dfsN[v] == 0){
      forBic.push(x);
      dfs(v, l + 1, u);
      dfsM[u] = min(dfsM[u], dfsM[v]);
      if(dfsN[u] <= dfsM[v]){
        bicC++;
        while(forBic.size()){
          int i = forBic.top();
          forBic.pop();
          edges[i].comp = bicC;
          if((edges[i].u == u || edges[i].v == u) && !edges[i].lucky) break;
        }
      }
    } else if(v != p && dfsN[u] > dfsN[v]){
      dfsM[u] = min(dfsM[u], dfsN[v]);
      if((dfsN[u] - dfsN[v]) % 2 == 0){
        forBic.push(x);
        edges[x].lucky = 1;
      }
    }
  }
}
int main(){
  int tc;
  cin>>tc;
  while(tc--){
    int n, m;
    bicC = 0;
    while(forBic.size()) forBic.pop();
    cin>>n>>m;
    forn(i, MAXN) lucky[i] = 0;
    forn(i, n){
      dfsN[i] = 0;
      adj[i].clear();
    }
    forn(i, m){
      int a, b;
      cin>>a>>b;
      a--; b--;
      edges[i] = {a, b, 0, 0};
      adj[a].push_back(i);
      adj[b].push_back(i);
      lucky[i + 1] = 0;
    }
    forn(i, n){
      if(dfsN[i]) continue;
      dfs(i, 1, -1);
    }
    forn(i, m){
      if(!edges[i].lucky) continue;
      lucky[edges[i].comp] = 1;
    }
    int res = 0;
    forn(i, n){
      bool valid = 0;
      for(int x : adj[i]){
        if(lucky[edges[x].comp]) valid = 1;
      }
      res += valid;
    }
    cout<<res<<"\n";
  }
  return 0;
}