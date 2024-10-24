#include <bits/stdc++.h>

#define  DBG(x      ) cerr<<#x<<" = "<<(x)<<endl
#define DBGY(x      ) cerr<<#x<<" = "<<(x)<<", ";
#define DBG2(x,y    ) {DBGY(x) DBG(y);}
#define DBG3(x,y,z  ) {DBGY(x) DBGY(y) DBG(z);}
#define DBG4(x,y,z,w) {DBGY(x) DBGY(y) DBGY(z) DBG(w);}
#define RAYA cerr<<" ============================== "<<endl

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define fort(i,n) for(int i = 0; i <= int(n); i++)
#define fori(i,a,n) for(int i = a; i < int(n); i++)
#define forit(i,a,n) for(int i = a; i <= int(n); i++)

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

using namespace std;

template<typename T>
ostream & operator<<(ostream &os, const vector<T> &v){
    os<<"[";
    forn(i, (int) v.size()){
        if(i) os<<", ";
        os<<v[i];
    }
    os<<"]";
    return os;
}

template<typename S, typename T>
ostream & operator<<(ostream &os, const pair<S, T> &p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int MAXN = 2e5+5;

vector<int> adj[MAXN];
int col[MAXN], dp[MAXN], ans[MAXN];

int dfsFst(int u, int p){
	dp[u] = col[u]? 1 : -1;
	for(int v : adj[u]){
		if(v == p) continue;
		dp[u] += max(0,dfsFst(v,u));
	}
	return dp[u];
}

void dfsSnd(int u, int p, int x){
	ans[u] = dp[u] + x;
	x += dp[u];
	for(int v : adj[u]){
		if(v == p) continue;
		dfsSnd(v,u,max(0,x-(dp[v] > 0? dp[v] : 0)));
	}
}

void solve(){
	
	int n;
	cin>>n;
	
	forn(i,n) cin>>col[i];
	
	fori(i,1,n){
		int u,v;
		cin>>u>>v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfsFst(0,0);
	dfsSnd(0,0,0);
	
	forn(i,n) cout<<ans[i]<<" ";
	cout<<"\n";

}

int main(){

	cin.tie(NULL);
	ios::sync_with_stdio(0);

    #ifdef LOCAL
        freopen("input.in", "r", stdin);
    #else
        //~ freopen("input.in", "r", stdin);
        //~ freopen("output.out", "w", stdout);
    #endif

    //~ #ifdef LOCAL
    
    //~ int tcs;
    //~ cin>>tcs;
    //~ while(tcs--) solve();
    
    //~ #else
    
    solve();
    
    //~ #endif

    return 0;
}
