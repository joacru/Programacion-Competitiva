#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
int main(){
	int n, a, actual, mejor;
	cin>>n;
	while(n != 0){
		actual = 0;
		mejor = 0;
		forn(i, n){
			cin>>a;
			actual = max(0, actual + a);
			mejor = max(mejor, actual);
		}
		if(mejor == 0) cout<<"Losing streak.\n";
		else cout<<"The maximum winning streak is "<<mejor<<".\n";
		cin>>n;
	}
}
