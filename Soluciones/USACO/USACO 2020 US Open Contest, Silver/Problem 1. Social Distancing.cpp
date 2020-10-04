#include<bits/stdc++.h>
#define sp system("pause")
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll INF = 1E18 + 5;
int main(){
	ifstream cin("socdist.in");
	ofstream cout("socdist.out");
	int n, m;
	cin>>n>>m;
	vector<pair<ll, ll> > intervals(m);
	forn(i, m) cin>>intervals[i].first>>intervals[i].second;
	sort(intervals.begin(), intervals.end());
	ll bi = 0, bd = INF, bm;
	while(bd - bi > 1){
		int e = 0;
		ll x = -INF;
		bm = (bi + bd) / 2;
		forn(i, n){
			while(e < m && intervals[e].second < x) e++;
			if(e == m) break;
			x = max(x, intervals[e].first);
			x += bm;
		}
		if(e == m) bd = bm;
		else bi = bm;
	}
	cout<<bi<<"\n";
	return 0;
}
