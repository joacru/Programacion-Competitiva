#include<bits/stdc++.h>
#define sp system("pause")
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, a, n) for(int i = a; i < n; i++)
using namespace std;
const int MAXN = 1E5 + 5, MAXM = 2E5 + 5, LOG = 18;
struct edge{
  int u, v;
  int getTo(int x){
    return (x ^ u) ^ v;
  }
};
vector<bool> artPoint(MAXN);
vector<int> adj[MAXN];
set<int> artAdj[MAXN * 2];
stack<int> forBic;
edge edges[MAXM];
int dfsN[MAXN], dfsM[MAXN], bic[MAXM], dfsC = 0, bicC = 1, dfsRoot = 0;
void dfsBic(int u, int p){
  dfsN[u] = dfsM[u] = ++dfsC;
  //cout<<"Nodo: "<<u<<" "<<dfsN[u]<<"\n";
  for(int x : adj[u]){
    edge y = edges[x];
    int v = y.getTo(u);
    if(dfsN[v] == 0){
      forBic.push(x);
      dfsBic(v, u);
      dfsM[u] = min(dfsM[u], dfsM[v]);
      //cout<<u<<" "<<dfsN[u]<<" "<<v<<" "<<dfsM[v]<<"\n";
      if(dfsN[u] <= dfsM[v]){
        while(forBic.size()){
          int z = forBic.top();
          //cout<<z<<"\n";
          forBic.pop();
          bic[z] = bicC;
          if(edges[z].u == u || edges[z].v == u) break; //Llega al vértice bueno
        }
        //cout<<"Fin componente\n";
        bicC++;
      }
    } else if(v != p){
      dfsM[u] = min(dfsM[u], dfsN[v]); //Creo que esto estaría bien, creo
      //cout<<"Back edge desde: "<<u<<" a: "<<v<<" "<<dfsM[u]<<"\n";
    }
  }
}
void connect(int u){
  for(int x : adj[u]){
    if(bic[x] == 0) continue; //Seguro era una back edge
    artAdj[u].insert(bic[x] + MAXN); //Conecta más allá xD
    artAdj[bic[x] + MAXN].insert(u);
  }
}
struct LCATable{
  int level[MAXN * 2], sparse[MAXN * 2][LOG];
  LCATable(){
    level[0] = -1;
    forn(i, MAXN * 2) forn(j, LOG) sparse[i][j] = 0;
  }
  void construct(int u, int p){
    level[u] = level[p] + 1;
    sparse[u][0] = p;
    fori(i, 1, LOG) sparse[u][i] = sparse[sparse[u][i - 1]][i - 1];
  }
  int lca(int a, int b){
    if(level[a] < level[b]) swap(a, b);
    int i;
    for(i = 0; level[a] - (1<<i) > level[b]; i++);
    for(; level[a] != level[b]; i--){
      if(level[a] - (1<<i) < level[b]) continue;
      a = sparse[a][i];
    }
    if(a == b) return a;
    for(i = 0; sparse[a][i] != sparse[b][i]; i++);
    for(; i >= 0; i--){
      if(sparse[a][i] == sparse[b][i]) continue;
      a = sparse[a][i];
      b = sparse[b][i];
    }
    return sparse[a][0];
  }
  int dist(int a, int b){
    int c = lca(a, b);
    //cout<<c<<"\n";
    //cout<<level[a]<<" "<<level[b]<<" "<<level[c]<<"\n";
    return level[a] + level[b] - level[c] * 2;
  }
} lca;
void dfsLCA(int u, int p){
  //cout<<"Nodo: "<<u<<"\n";
  lca.construct(u, p);
  for(int v : artAdj[u]){
    if(v == p) continue;
    dfsLCA(v, u);
  }
}
int main(){
  int n, m, q;
  cin>>n>>m>>q;
  forn(i, m){
    int a, b;
    cin>>a>>b;
    edges[i] = {a, b};
    adj[a].push_back(i);
    adj[b].push_back(i);
  }
  dfsBic(1, 0);
  fori(i, 1, MAXN) connect(i);
  dfsLCA(1, 0);
  while(q--){
    int a, b, c;
    cin>>a>>b>>c;
    int fDist = lca.dist(a, b), sDist = lca.dist(a, c) + lca.dist(b, c);
    //cout<<fDist<<" "<<sDist<<"\n";
    if(fDist == sDist) cout<<"NO\n";
    else cout<<"YES\n";
  }
  return 0;
}