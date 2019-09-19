#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define forrt(i, n) for(int i = n; i >= 0; i--)
using namespace std;
struct coord{
	int x, y;
	bool operator <(const coord &b) const{
		return x < b.x;
	}
};
int main(){
	int TC, n;
	cin>>TC;
	while(TC--){
		cin>>n;
		coord c[n];
		forn(i, n) cin>>c[i].x>>c[i].y;
		sort(c, c + n);
		double my = 0, alt, hip, altpic, hippic, baspic, res = 0;
		forrt(i, n - 2){
			if(c[i].y < my) continue;
			alt = c[i].y - my;
			altpic = c[i].y - c[i + 1].y;
			baspic = c[i + 1].x - c[i].x;
			hippic = sqrt(pow(altpic, 2) + pow(baspic, 2));
			hip = alt * hippic / altpic;
			res += hip;
			my = max(my, double(c[i].y));
		}
		printf("%.2f\n", res);
	}
}
