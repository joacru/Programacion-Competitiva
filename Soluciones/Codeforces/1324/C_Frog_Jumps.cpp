#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>

#define  DBG(x         ) cerr<<#x<<" = "<<(x)<<endl
#define DBG2(x, y      ) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<endl
#define DBG3(x, y, z   ) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<", "<<#z<<" = "<<(z)<<endl
#define DBG4(x, y, z, w) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<", "<<#z<<" = "<<(z)<<", "<<#w<<" = "<<(w)<<endl
#define RAYA cerr<<" =============== "<<endl

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fort(i, n) for(int i = 0; i <= int(n); i++)
#define fori(i, a, n) for(int i = a; i < int(n); i++)
#define forit(i, a, n) for(int i = a; i <= int(n); i++)

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

int main(){

    #ifdef LOCAL
        freopen("input.in", "r", stdin);
    #else
        //freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
    #endif

    int tcs;
    cin>>tcs;
    while(tcs--){
        
        string s;
        cin>>s;
		
		int n = s.size();
		vector<int> idx = {-1};
		forn(i, n) if(s[i] == 'R') idx.push_back(i);
		idx.push_back(n);
		
		int maxDist = 0;
		
		fori(i, 1, idx.size()) maxDist = max(maxDist, idx[i] - idx[i - 1]);
		
		cout<<maxDist<<"\n";
        
    }

    return 0;
}
