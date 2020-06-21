#include<bits/stdc++.h>
#define sp system("pause")
#define forn(i, n) for(int i = 0; i < n; i++)
#define forit(i, a, n) for(int i = a; i <= n; i++)
using namespace std;
const int MAXN = 1005, NOV = 0, EXP = 1, VIS = 2;
int cdfs, ndfs[MAXN], ldfs[MAXN], pdfs[MAXN], vdfs[MAXN];
vector<int> ady[MAXN];
vector<pair<int, int> > res;
void tarjan(int u){
	vdfs[u] = EXP;
	ndfs[u] = ldfs[u] = ++cdfs;
	int t = ady[u].size(), v;
	forn(i, t){
		v = ady[u][i];
		if(ndfs[v] == NOV){
			pdfs[v] = u;
			tarjan(v);
			if(ldfs[v] > ndfs[u]){ //Es un puente
				res.push_back({v, u});
			}
			res.push_back({u, v});
			ldfs[u] = min(ldfs[u], ldfs[v]);
		} else if(pdfs[u] != v){
			ldfs[u] = min(ldfs[u], ldfs[v]);
			if(vdfs[v] != VIS) res.push_back({u, v});
		}
	}
	vdfs[u] = VIS;
}
int main(){
	//ifstream cin("00610.in");
	int caso = 0;
	while(++caso){
		int n, m;
		cin>>n>>m;
		if(n == 0 && m == 0) return 0;
		res.clear();
		cdfs = 0;
		forn(i, MAXN) ndfs[i] = NOV, pdfs[i] = NOV, vdfs[i] = NOV, ady[i].clear(); //No visitado
		int a, b;
		forn(i, m){
			cin>>a>>b;
			ady[a].push_back(b);
			ady[b].push_back(a);
		}
		tarjan(1);
		m = res.size();
		cout<<caso<<"\n\n";
		forn(i, m) cout<<res[i].first<<" "<<res[i].second<<"\n";
		cout<<"#\n";
	}
	return 0;
}
