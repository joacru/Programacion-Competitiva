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

const int MAXN = 2e5+5, MAXI = 1e6+5;

struct State{
	int d, id, i;
	bool operator < (const State& o) const {
		if(d != o.d) return d > o.d;
		if(i != o.i) return i < o.i;
		return id < o.id;
	}
};

int n;

list<pair<int,int>> pos;
list<pair<int,int>>::iterator ptr[MAXI];
set<State> dis;

int arrive(int id){
	int ret = 0;
	if(!pos.size()){
		ptr[id] = pos.insert(pos.begin(),{1,id});
		ret = 1;
	} else{ // Si hay algún otro auto
		int begin = pos.begin()->first-1, end = n-pos.rbegin()->first;
		auto it = dis.begin();
		if(it != dis.end() && it->d > begin && it->d >= end){
			auto p = ptr[it->id], q = p;
			q--;
			int i = p->first, j = q->first, k = j + it->d;
			int a = (i-k)/2, b = (k-j)/2;
			ptr[id] = pos.insert(p, {k,id});
			int x = it->id;
			dis.erase(it);
			dis.insert({a,x,i});
			dis.insert({b,id,k});
			ret = k;
		} else if(begin >= end){
			auto p = pos.begin();
			int i = p->first, k = 1;
			int a = (i-k)/2;
			ptr[id] = pos.insert(p,{1,id});
			dis.insert({a,p->second,i});
			ret = k;
		} else{
			auto p = pos.rbegin();
			int i = p->first, k = n;
			int a = (k-i)/2;
			ptr[id] = pos.insert(pos.end(), {n,id});
			dis.insert({a,id,k});
			ret = k;
		}
	}
	//~ for(auto l : pos) DBG(l);
	//~ for(auto it : dis) DBG3(it.d, it.i, it.id);
	return ret;
}

void depart(int id){
	if(pos.size() == 1){
		pos.clear();
		dis.clear();
	} else{
		if(pos.begin()->second == id){
			int i = pos.begin()->first;
			pos.erase(pos.begin());
			State aux = {(pos.begin()->first-i)/2,pos.begin()->second,pos.begin()->first};
			dis.erase(aux);
		} else if(pos.rbegin()->second == id){
			int i = ptr[id]->first;
			pos.erase(ptr[id]);
			State aux = {(i-pos.rbegin()->first)/2,id,i};
			dis.erase(aux);
		} else{
			auto p = ptr[id], q = p, r = p;
			q--; r++;
			int a = (p->first-q->first)/2, b = (r->first-p->first)/2;
			dis.erase({a,id,p->first});
			dis.erase({b,r->second,r->first});
			dis.insert({(r->first-q->first)/2,r->second,r->first});
			pos.erase(p);
		}
	}
	//~ for(auto l : pos) DBG(l);
	//~ for(auto it : dis) DBG3(it.d, it.i, it.id);
}

void solve(){
	
	int m;
	cin>>n>>m;
	
	while(m--){
		//~ RAYA;
		int t,id;
		cin>>t>>id;
		if(t==1){
			cout<<arrive(id)<<"\n";
		} else{
			depart(id);
		}
	}

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
