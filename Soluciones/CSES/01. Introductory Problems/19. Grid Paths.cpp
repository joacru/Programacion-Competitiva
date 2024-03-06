#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
 
#define  DBG(x         ) cerr<<#x<<" = "<<(x)<<endl
#define DBG2(x, y      ) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<endl
#define DBG3(x, y, z   ) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<", "<<#z<<" = "<<(z)<<endl
#define DBG4(x, y, z, w) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<", "<<#z<<" = "<<(z)<<", "<<#w<<" = "<<(w)<<endl
#define RAYA cerr<<" =============== "<<endl
#define sp system("pause")
 
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
 
const short RC = 7, SIZE = 49 - 1;
 
int res = 0;
string s;
bool vis[RC][RC];
 
//UDLR
int rv[4] = {-1, 1, 0, 0}, cv[4] = {0, 0, -1, 1};
 
bool valid(int r, int c){
	return r >= 0 && r < RC && c >= 0 && c < RC && !vis[r][c];
}
 
void solve(int r, int c, int cnt){
	//DBG3(r, c, cnt);
	if(r == RC - 1 && c == 0){
		if(cnt == SIZE){
			//DBG3(r, c, cnt);
			//sp;
			res++;
		}
		return;
	}
	if(cnt == SIZE) return;
	//Chequear si se puede seguir
	if(valid(r - 1, c) == valid(r + 1, c) && valid(r - 1, c) != valid(r, c - 1) && valid(r, c - 1) == valid(r, c + 1)){
		//DBG4(valid(r - 1, c), valid(r + 1, c), valid(r, c - 1), valid(r, c + 1));
		//DBG("Se divide en dos");
		return; //La grilla se divide en dos
	}
	//Avanzar
	int mini = 0, maxi = 4;
	switch(s[cnt]){
		case 'U':
			mini = 0;
			break;
		case 'D':
			mini = 1;
			break;
		case 'L':
			mini = 2;
			break;
		case 'R':
			mini = 3;
			break;
	}
	if(s[cnt] != '?') maxi = mini + 1;
	fori(i, mini, maxi){
		int nr = r + rv[i], nc = c + cv[i];
		if(!valid(nr, nc)) continue;
		vis[nr][nc] = 1;
		solve(nr, nc, cnt + 1);
		vis[nr][nc] = 0;
	}
}
 
int main(){
 
    #ifdef LOCAL
        freopen("input.in", "r", stdin);
    #else
    #endif
 
	cin>>s;
	
	vis[0][0] = 1;
	solve(0, 0, 0);
	
	cout<<res<<"\n";
 
    return 0;
}
