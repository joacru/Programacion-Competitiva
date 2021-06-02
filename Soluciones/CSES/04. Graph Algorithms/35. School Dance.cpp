#include<bits/stdc++.h>
#define sp system("pause")
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
const int MAXNM = 500, MAXK = 1000;
struct edge{
  int u, v;
  bool inv;
  int getTo(){
    return inv? u : v;
  }
  void invert(){
    inv = !inv;
  }
};
edge edges[MAXK];
vector<int> adj[MAXNM * 2];
bool vis[MAXNM * 2], matched[MAXNM * 2];
int res = 0;
bool dfs(int u){
  vis[u] = 1;
  if(!matched[u] && u >= MAXNM){
    matched[u] = 1;
    res++;
    return 1;
  }
  for(int x : adj[u]){
    int v = edges[x].getTo();
    if(v == u || vis[v]) continue; //No puedo pasar por acá
    if(dfs(v)){
      matched[u] = 1;
      edges[x].invert();
      return 1;
    }
  }
  return 0;
}
int main(){
  int n, m, k;
  cin>>n>>m>>k;
  forn(i, k){
    int a, b;
    cin>>a>>b;
    a--; b--;
    edges[i] = {a, b + MAXNM, 0};
    adj[a].push_back(i);
    adj[b + MAXNM].push_back(i);
  }
  bool possible = 1;
  while(possible){
    forn(i, MAXNM * 2) vis[i] = 0;
    possible = 0;
    forn(i, n){
      if(vis[i] || matched[i]) continue;
      if(dfs(i)){
        possible = 1;
        break;
      }
    }
  }
  cout<<res<<"\n";
  forn(i, k){
    if(!edges[i].inv) continue;
    cout<<(edges[i].u + 1)<<" "<<(edges[i].v - MAXNM + 1)<<"\n";
  }
  return 0;
}