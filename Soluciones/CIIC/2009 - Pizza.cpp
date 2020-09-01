#include<bits/stdc++.h>
using namespace std;
const int MAXX = 1E5 + 1, INF = 1E9;
struct segtree{
	int n;
	vector<int> st;
	segtree(){
		n = 2 * pow(2, ceil(log2(MAXX))) - 1;
		st.resize(n, INF);
	}
	void update(int i, int v){
		i += (n / 2);
		if(v >= st[i]) return;
		st[i] = v;
		while(i != 0){
			i = (i - 1) / 2;
			st[i] = min(st[i * 2 + 1], st[i * 2 + 2]);
		}
	}
	int query(int qi, int qd, int si, int sd, int i){
		if(si >= qd || sd <= qi) return INF;
		if(si >= qi && sd <= qd) return st[i];
		int sm = (si + sd) / 2;
		return min(query(qi, qd, si, sm, i * 2 + 1), query(qi, qd, sm, sd, i * 2 + 2));
	}
	int query(int qi, int qd){
		return query(qi, qd, 0, n / 2 + 1, 0);
	}
};
int main(){
	int n, x, y, res;
	char c;
	segtree pizzaleft, pizzaright;
	cin>>n;
	while(n--){
		cin>>c;
		if(c == 'I'){
			cin>>x>>y;
			pizzaleft.update(x, y - x);
			pizzaright.update(x, x + y);
		} else{
			cin>>x;
			res = pizzaleft.query(0, x) + x;
			res = min(res, pizzaright.query(x, MAXX) - x);
			cout<<res<<"\n";
		}
	}
	return 0;
}
