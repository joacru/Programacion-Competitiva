#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<"The 1500'th ugly number is "<<859963392<<".\n";
}

//How I got it
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef set<ll>::iterator sllt;
const ll MAXN = 200000000000000000;
set<ll> res;
void next(ll n, int ant){
	if(n > MAXN) return;
	res.insert(n);
	if(ant <= 2) next(n * 2, 2);
	if(ant <= 3) next(n * 3, 3);
	if(ant <= 5) next(n * 5, 5);
	return;
}
int main(){
	next(1, 1);
	int n = 1;
	sllt it;
	for(it = res.begin(); n < 1500; it++, n++);
	cout<<(*it)<<"\n";
}*/
