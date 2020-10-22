#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gauss(ll n){
	return n * (n + 1) / 2;
}
int main(){
	int n;
	cin>>n;
	cout<<0<<"\n";
	for(ll k = 2; k <= n; k++){
		if(k == 2){
			cout<<6<<"\n";
			continue;
		} else if(k == 3){
			cout<<28<<"\n";
			continue;
		}
		ll res = gauss(k - 1) * k; //Colocarse arriba y abajo en cada fila
		for(int i = 0; i < k - 1; i++){
			if(k - i - 3 > 0){
				res += k * k * (k - i - 3); //Colocar los caballos en zona segura
			}
			//Ver casitos cuando se coloca en el borde de una columna
			res += 4 * (k - 1);
			//Ver casitos cuando el segundo termina dos columnas adelante
			if(i + 2 < k){
				res += 2 * (k - 1);
				res += 2 * (k - 2);
			}
			//Ver casitos normales cuando el segundo se coloca en la siguiente
			res += (k - 4) * (k - 2);
			//Ver casitos normales cuando el segundo se coloca dos columnas adelante
			if(i + 2 < k){
				res += (k - 4) * (k - 2);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
