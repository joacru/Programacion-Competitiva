#include<bits/stdc++.h>
#define sp system("pause")
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, a, n) for(int i = a; i < n; i++)
#define forit(i, a, n) for(int i = a; i <= n; i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int MAXN = 5E5 + 1, LOG = 19;
int p;
int val[MAXN], cnt[MAXN], parent[MAXN], size[MAXN];
bool taken[MAXN];
vector<int> adj[MAXN];
int lsb(int x){
	return x & -x;
}
int bindex(int x){
	return __builtin_clz(1) - __builtin_clz(x);
}
struct rmq{
	int n, m, b, cols, first[MAXN]; //N tiene la cantidad de bloques y M la cantidad real
	vector<int> euler, level, nse; //nse: bitmask de nearest smaller element
	vector<vector<int> > sparse;
	void add(int u, int l){
		first[u] = euler.size();
		euler.push_back(u);
		level.push_back(l);
	}
	void construct(){
		b = LOG;
		int m = euler.size(), n = (m - 1) / b + 1;
		sparse.resize(n);
		cols = log2(n) + 1;
		int k = 1;
		forn(i, n) sparse[i].push_back(i * b);
		forn(i, m) if(level[i] < level[sparse[i / b][0]]) sparse[i / b][0] = i;
		fori(e, 1, cols){
			forn(i, n){
				if(i + k * 2 > n) break;
				if(level[sparse[i + k][e - 1]] < level[sparse[i][e - 1]]){
					sparse[i].push_back(sparse[i + k][e - 1]);
				} else{
					sparse[i].push_back(sparse[i][e - 1]);
				}
			}
			k *= 2;
		}
		int mask = 0;
		nse.resize(m);
		forn(i, m){
			mask = (mask<<1); //Desplaza todo un bit a la izquierda
			if(i % b == 0) mask = 0;
			while(mask && level[i - bindex(lsb(mask))] > level[i]){
				mask ^= lsb(mask);
			}
			mask ^= 1; //Se prede a si mismo
			nse[i] = mask;
		}
	}
	int cut(int l, int r){ //Hace cortes en un mismo bloque - Devuelve el índice del menor
		int mask = nse[r]; //Tiene todos los menores, hay que apagar los innecesarios
		//int d = r - l + 1;
		//int k = (1<<d) - 1;
		//int k = (1<<(r - l + 1)) - 1;
		//mask &= k; //Apaga los innecesarios
		mask &= ((1<<(r - l + 1)) - 1);
		int ret = r - bindex(mask);
		return ret;
	}
	int lca(int x, int y){
		int l = first[x], r = first[y];
		if(l > r) swap(l, r);
		int bl = l / b, br = r / b; //bloqueizq, bloqueder
		if(bl == br){ //Si están en el mismo bloque
			return euler[cut(l, r)];
		}
		int ret;
		int lt = (bl + 1) * b - 1;
		int rt = br * b;
		bl++; //Para hacer query inclusiva exclusiva (incluye y el segundo ya está excluido)
		int d = br - bl;
		int u = cut(l, lt), v = cut(rt, r);
		if(d == 0){ //Si pisa el mismo bloque entonces se rompe todo
			if(level[u] < level[v]) return euler[u];
			else return euler[v];
		}
		if(level[v] < level[u]) u = v; //u mantiene el menor de los dos
		int k = log2(d); //Para acceder en la sparse
		d = (1<<k);
		int w;
		if(level[sparse[bl][k]] < level[sparse[br - d][k]]){
			w = sparse[bl][k];
		} else{
			w = sparse[br - d][k];
		}
		if(level[w] < level[u]) u = w;
		return euler[u];
	}
	int query(int x, int y){
		int z = lca(x, y);
		return cnt[x] + cnt[y] - cnt[z] * 2 + (val[z] < p);
	}
} ancestors;
void dfs(int u, int l, int f, int c){
	ancestors.add(u, l);
	cnt[u] = c + (val[u] < p);
	for(vi::iterator v = adj[u].begin(); v != adj[u].end(); v++){
		if(*v == f) continue;
		dfs(*v, l + 1, u, cnt[u]);
		ancestors.add(u, l);
	}
}
int calsize(int u, int f){
	size[u] = 1;
	for(vi::iterator v = adj[u].begin(); v != adj[u].end(); v++){
		if(*v == f || taken[*v]) continue;
		size[u] += calsize(*v, u);
	}
	return size[u];
}
void centroid(int u = 1, int f = 0, int l = 0, int sz = -1){
	if(sz == -1) sz = calsize(u, 0);
	for(vi::iterator v = adj[u].begin(); v != adj[u].end(); v++){
		if(taken[*v] || size[*v] <= sz / 2) continue;
		size[u] = 0;
		centroid(*v, f, l, sz);
		return;
	}
	taken[u] = 1;
	parent[u] = f;
	for(vi::iterator v = adj[u].begin(); v != adj[u].end(); v++){
		if(taken[*v]) continue;
		centroid(*v, u, l + 1, - 1);
	}
}
int main(){
	int n, k, u, v;
	scanf("%d %d %d", &n, &p, &k);
	forit(i, 1, n) scanf("%d", &val[i]);
	fori(i, 1, n){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0, 0, 0);
	ancestors.construct();
	forit(i, 1, n) parent[i] = -1;
	centroid();
	vector<int> adjcent[MAXN], subtree[MAXN];
	int root;
	forit(i, 1, n){
		int x = i;
		while(x != 0){
			subtree[x].push_back(i);
			x = parent[x];
		}
		if(parent[i]) adjcent[parent[i]].push_back(i);
	}
	ll res = 0;
	ll calc[MAXN];
	forn(i, MAXN) calc[i] = 0;
	forit(x, 1, n){
		int t = adjcent[x].size();
		if(!t){
			if((k == 2 && val[x] < p) || (k == 1 && val[x] > p)) res += 2;
			continue;
		}
		if((val[x] < p) == k - 1) res += 2;
		calc[0] = ll(x) * MAXN + 1;
		forn(i, t){
			u = adjcent[x][i];
			int s = subtree[u].size();
			forn(e, s){
				v = subtree[u][e];
				int y = ancestors.query(x, v);
				if(y == k - 1) res++;
				y -= (val[x] < p);
				subtree[u][e] = y;
				if(calc[y] < ll(x) * MAXN) calc[y] = ll(x) * MAXN;
				calc[y]++;
			}
		}
		forn(i, t){
			u = adjcent[x][i];
			for(vi::iterator w = subtree[u].begin(); w != subtree[u].end(); w++) calc[*w]--;
			for(vi::iterator w = subtree[u].begin(); w != subtree[u].end(); w++){
				int y = *w + (val[x] < p);
				if(y >= k) continue;
				res += max(calc[k - y - 1] - ll(x) * MAXN, 0LL);
			}
			for(vi::iterator w = subtree[u].begin(); w != subtree[u].end(); w++) calc[*w]++;
		}
	}
	res /= 2;
	printf("%lld\n", res);
	return 0;
}
