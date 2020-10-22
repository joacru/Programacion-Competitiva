#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n;
	cin>>n;
	while(n != 1){
		cout<<n<<" ";
		n = (n % 2)? n * 3 + 1 : n / 2;
	}
	cout<<1<<endl;
	return 0;
}
