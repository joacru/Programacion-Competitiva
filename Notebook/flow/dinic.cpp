struct Edge{
	int u,v;
	ll cap, flow = 0;
	Edge(int _u, int _v, ll _cap) : u(_u), v(_v), cap(_cap) {}
};

struct Dinic{
	const ll INF = 1e18;
	
	vector<Edge> edges;
	vector<vector<int>> adj;
	int n,m = 0;
	int s,t;
	vector<int> level, ptr;
	queue<int> q;
	
	Dinic(int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
		adj.resize(n);
		level.resize(n);
		ptr.resize(n);
	}
	
	void addEdge(int u, int v, ll cap){
		edges.emplace_back(u,v,cap);
		edges.emplace_back(v,u,0);
		adj[u].push_back(m++);
		adj[v].push_back(m++);
	}
	
	bool bfs(){
		fill(all(level),-1);
		level[s] = 0;
		q.push(s);
		while(q.size()){
			int u = q.front();
			q.pop();
			for(int id : adj[u]){
				if(edges[id].cap == edges[id].flow) continue;
				if(level[edges[id].v] != -1) continue;
				level[edges[id].v] = level[u] + 1;
				q.push(edges[id].v);
			}
		}
		return level[t] != -1;
	}
	
	ll dfs(int u, ll pushed){
		if(pushed == 0) return 0;
		if(u == t) return pushed;
		for(int& idx = ptr[u]; idx < (int) adj[u].size(); idx++){
			int id = adj[u][idx];
			int v = edges[id].v;
			if(level[u] + 1 != level[v]) continue;
			ll tr = dfs(v,min(pushed, edges[id].cap - edges[id].flow));
			if(tr == 0) continue;
			edges[id].flow += tr;
			edges[id^1].flow -= tr;
			return tr;
		}
		return 0;
	}
	
	ll flow(){
		ll f = 0;
		while(1){
			if(!bfs()) break;
			fill(all(ptr),0);
			while(ll pushed = dfs(s,INF)) f += pushed;
		}
		return f;
	}
};
