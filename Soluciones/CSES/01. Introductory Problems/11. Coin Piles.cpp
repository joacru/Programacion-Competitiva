#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int a, b;
		cin>>a>>b;
		if(a == 0 || b == 0){
			if(a == b){
				cout<<"YES\n";
			} else{
				cout<<"NO\n";
			}
		} else if((2 * b - a >= 0 && (2 * b - a) % 3 == 0 && (2 * b - a) / 3 <= a)
			|| (2 * a - b >= 0 && (2 * a - b) % 3 == 0 && (2 * a - b) / 3 <= b)){
			cout<<"YES\n";
		} else{
			cout<<"NO\n";
		}
	}
	return 0;
}
