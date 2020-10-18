int MAXN = 2E5 + 5, LOG = 19;
bool vis[MAXN];
vector<int> adj[MAXN], travel;
struct lcatable{
  int level[MAXN], sparse[MAXN][LOG];
  void construct(int u, int l){
    level[u] = l;
    int t = travel.size();
    for(int i = 0, k = 1; k <= t; i++, k *= 2) sparse[u][i] = travel[t - k];
  }
  int lca(int a, int b){
    if(level[a] < level[b]) swap(a, b);
    int i, k;
    for(i = 0, k = 1; level[a] - k > level[b]; i++, k *= 2);
    for(; level[a] != level[b]; i--, k /= 2){ //Poner a y b en el mismo nivel
      if(level[a] - k < level[b]) continue;
      a = sparse[a][i];
    }
    if(a == b) return a; //Si a es descendiente de b
    for(i = 0; sparse[a][i] != sparse[b][i]; i++);
    for(; i >= 0; i--){
      if(sparse[a][i] == sparse[b][i]) continue;
      a = sparse[a][i];
      b = sparse[b][i];
    }
    return sparse[a][0];
  }
} lca;
void dfs(int u, int p, int l){
  int t = adj[u].size();
  vis[u] = 1;
  lca.construct(u, l);
  travel.push_back(u);
  for(int i = 0; i < t; i++){
    int u = adj[u][i];
    if(u == p) continue;
    dfs(v, u, l + 1);
  }
  travel.pop_back();
}