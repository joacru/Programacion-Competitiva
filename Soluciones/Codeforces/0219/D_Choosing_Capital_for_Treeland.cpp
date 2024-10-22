#include<iostream>
#include<assert.h>
#include<algorithm>
#include<vector>

#define  DBG(x         ) cerr<<#x<<" = "<<(x)<<endl
#define DBG2(x, y      ) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<endl
#define DBG3(x, y, z   ) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<", "<<#z<<" = "<<(z)<<endl
#define DBG4(x, y, z, w) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<", "<<#z<<" = "<<(z)<<", "<<#w<<" = "<<(w)<<endl
#define RAYA cerr<<" =============== "<<endl

#define forn(i, n) for(int i = 0; i < n; i++)
#define fort(i, n) for(int i = 0; i <= n; i++)
#define fori(i, a, n) for(int i = a; i < n; i++)
#define forit(i, a, n) for(int i = a; i <= n; i++)

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

typedef long long ll;
typedef long double ld;

const int MAXN = 2E5 + 5;
int res = MAXN, dp[MAXN];
vector<pair<int, bool> > adj[MAXN];

int dfsFst(int u, int p){
	int ret = 0;
	for(auto v : adj[u]){
		if(v.first == p) continue;
		ret += !v.second + dfsFst(v.first, u);
	}
	return dp[u] = ret;
}

void dfsSnd(int u, int p, int q){
	//DBG3(q, dp[u], res);
	for(auto v : adj[u]){
		if(v.first == p) continue;
		//DBG2(v.first, dp[v.first]);
		dfsSnd(v.first, u, q + dp[u] - dp[v.first] - !v.second + v.second);
	}
	res = min(res, q + dp[u]);
	dp[u] += q;
}

int main(){

    #ifdef LOCAL
        freopen("input.in", "r", stdin);
    #endif

    int n;
    cin>>n;
    forn(i, n - 1){
		int s, t;
		cin>>s>>t;
		adj[s].push_back({t, 1});
		adj[t].push_back({s, 0});
	}
	dfsFst(1, 0);
	dfsSnd(1, 0, 0);
	cout<<res<<"\n";
	forit(i, 1, n) if(dp[i] == res) cout<<i<<" ";
	cout<<"\n";

    return 0;
}
