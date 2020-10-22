#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n, a, b = 0, res = 0;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a;
		if(a < b){
			res += b - a;
			a = b;
		}
		b = a;
	}
	cout<<res<<endl;
	return 0;
}
