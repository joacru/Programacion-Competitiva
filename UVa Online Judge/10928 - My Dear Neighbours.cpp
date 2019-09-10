#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
const int MAX = 1010;
int main(){
	int T, n, t, grado, menor;
	string s;
	int grados[MAX];
	cin>>T;
	while(T--){
		memset(grados, 0, sizeof(grados));
		menor = MAX;
		cin>>n;
		getline(cin, s);
		forn(i, n){
			grado = 1;
			getline(cin, s);
			t = s.size();
			forn(e, t) if(s[e] == ' ') grado++;
			grados[i] = grado;
			menor = min(grado, menor);
		}
		int prim;
		for(prim = 0; prim < n; prim++){
			if(grados[prim] == menor){
				cout<<(prim + 1);
				break;
			}
		}
		for(int i = prim + 1; i < n; i++){
			if(grados[i] == menor) cout<<" "<<(i + 1);
		}
		cout<<endl;
	}
}
