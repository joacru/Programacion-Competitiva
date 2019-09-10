#include<bits/stdc++.h>
#define forr(i, a, n) for(int i = a; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define ii pair<int,int>
#define vii vector<ii>
using namespace std;
int main(){
	int m, n, r;
	while(cin>>m){
		cin>>n;
		vii ady[n];
		forn(i, m){
			cin>>r;
			vii ind(r);
			forn(e, r) cin>>ind[e].first;
			forn(e, r) cin>>ind[e].second;
			forn(e, r){
				ady[ind[e].first - 1].push_back({i + 1, ind[e].second});
			}
		}
		cout<<n<<" "<<m<<endl;
		forn(i, n){
			sort(ady[i].begin(), ady[i].end());
			r = ady[i].size();
			cout<<r;
			if(r > 0) cout<<" "<<ady[i][0].first;			
			forr(e, 1, r) cout<<" "<<ady[i][e].first;
			cout<<endl;
			if(r > 0) cout<<ady[i][0].second;
			forr(e, 1, r) cout<<" "<<ady[i][e].second;
			cout<<endl;
		}
	}
}
