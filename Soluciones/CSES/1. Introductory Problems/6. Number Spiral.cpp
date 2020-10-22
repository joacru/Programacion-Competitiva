#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n, a, b, res;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a>>b;
		if(a < b){
			if(b % 2 == 1) res = b * b - a + 1;
			else res = (b - 1) * (b - 1) + a;
		} else{
			if(a % 2 == 0) res = a * a - b + 1;
			else res = (a - 1) * (a - 1) + b;
		}
		cout<<res<<endl;
	}
	return 0;
}
