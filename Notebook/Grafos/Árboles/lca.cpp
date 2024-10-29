const int MAXN = 2e5+5;

vector<int> adj[MAXN];

struct LCA{
	const int LOG = 18;
	
	int n,root;
	vector<int> level;
	vector<vector<int>> sparse;
	
	LCA(int _n, int _root) : n(_n), root(_root) {
		level.resize(n+root);
		sparse.resize(n+root,vector<int>(LOG));
		level[root] = -1;
		dfs(root,root);
	}
	
	void dfs(int u, int p){
		level[u] = level[p]+1;
		sparse[u][0] = p;
		fori(i,1,LOG) sparse[u][i] = sparse[sparse[u][i-1]][i-1];
		for(int v : adj[u]) if(v != p) dfs(v,u);
	}
	
	int lca(int u, int v){
		if(level[u] < level[v]) swap(u,v);
		for(int i=LOG-1; i>=0; i--){
			if(level[u] - (1<<i) >= level[v]) u = sparse[u][i];
		}
		if(u == v) return u;
		for(int i=LOG-1; i>=0; i--){
			if(sparse[u][i] == sparse[v][i]) continue;
			u = sparse[u][i];
			v = sparse[v][i];
		}
		return sparse[u][0];
	}
	
	int query(int u, int v){
		int w = lca(u,v);
		return level[u] + level[v] - 2*level[w];
	}
};
