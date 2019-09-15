#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct pirate{
	int can, buc;
	bool inv, cer;
};
typedef pirate *pst;
typedef struct tst{
	pst st;
	int tam;
	ll construirST(int izq, int der, int index){
		st[index].inv = false;
		st[index].cer = false;
		if(izq == der - 1) return st[index].buc;
		int m = (izq + der) / 2;
		st[index].buc = construirST(izq, m, index * 2 + 1) +
						construirST(m, der, index * 2 + 2);
		st[index].can = st[index * 2 + 1].can + st[index * 2 + 2].can;
	}
	void init(const string &s, int n){
		int x = ceil(log2(n));
		int piso = pow(2, x);
		tam = 2 * piso - 1;
		st = new pirate[tam];
		int e = 0;
		for(int i = tam / 2; i < tam; i++){
			st[i].can = (e < n)? 1 : 0;
			st[i].buc = (e < n && s[e] == '1')? 1 : 0;
			st[i].inv = false;
			st[i].cer = false;
			e++;
		}
		//construirST(0, tam / 2 + 1, 0);
		for(int i = tam / 2 - 1; i > -1; i--){
			st[i].can = st[i * 2 + 1].can + st[i * 2 + 2].can;
			st[i].buc = st[i * 2 + 1].buc + st[i * 2 + 2].buc;
			st[i].inv = false;
			st[i].cer = false;
		}
	}
	ll query(int qizq, int qder, int sizq, int sder, int index){
		if(st[index].inv || st[index].cer){
			if(st[index].inv && !st[index].cer){
				st[index].buc = st[index].can - st[index].buc;
				if(sizq != sder - 1){
					st[index * 2 + 1].inv = !st[index * 2 + 1].inv;
					st[index * 2 + 2].inv = !st[index * 2 + 2].inv;
				}
			} else if(!st[index].inv && st[index].cer){
				st[index].buc = 0;
				if(sizq != sder - 1){
					st[index * 2 + 1].cer = true;
					st[index * 2 + 1].inv = false;
					st[index * 2 + 2].cer = true;
					st[index * 2 + 2].inv = false;
				}
			} else if(st[index].inv && st[index].cer){
				st[index].buc = st[index].can;
				if(sizq != sder - 1){
					st[index * 2 + 1].cer = true;
					st[index * 2 + 1].inv = true;
					st[index * 2 + 2].cer = true;
					st[index * 2 + 2].inv = true;
				}
			}
			st[index].inv = false;
			st[index].cer = false;
		}
		if(sizq >= sder || sder <= qizq || sizq >= qder) return 0;
		if(sizq >= qizq && sder <= qder) return st[index].buc;
		int m = (sizq + sder) / 2;
		return 	query(qizq, qder, sizq, m, index * 2 + 1) +
				query(qizq, qder, m, sder, index * 2 + 2);
	}
	ll consultar(int qizq, int qder){
		return query(qizq, qder, 0, tam / 2 + 1, 0);
	}
	void update(int uizq, int uder, int sizq, int sder, int index, int operacion){
		if(st[index].inv || st[index].cer){
			if(st[index].inv && !st[index].cer){
				st[index].buc = st[index].can - st[index].buc;
				if(sizq != sder - 1){
					st[index * 2 + 1].inv = !st[index * 2 + 1].inv;
					st[index * 2 + 2].inv = !st[index * 2 + 2].inv;
				}
			} else if(!st[index].inv && st[index].cer){
				st[index].buc = 0;
				if(sizq != sder - 1){
					st[index * 2 + 1].cer = true;
					st[index * 2 + 1].inv = false;
					st[index * 2 + 2].cer = true;
					st[index * 2 + 2].inv = false;
				}
			} else if(st[index].inv && st[index].cer){
				st[index].buc = st[index].can;
				if(sizq != sder - 1){
					st[index * 2 + 1].cer = true;
					st[index * 2 + 1].inv = true;
					st[index * 2 + 2].cer = true;
					st[index * 2 + 2].inv = true;
				}
			}
			st[index].inv = false;
			st[index].cer = false;
		}
		if(sizq >= sder || sder <= uizq || sizq >= uder) return;
		if(sizq >= uizq && sder <= uder){
			if(operacion == 1){ //Invertir
				st[index].buc = st[index].can - st[index].buc;
			} else if(operacion == 2){ //Ceros
				st[index].buc = 0;
			} else if(operacion == 3){ //Unos
				st[index].buc = st[index].can;
			}
			if(sizq != sder - 1){
				if(operacion == 1){
					st[index * 2 + 1].inv = !st[index * 2 + 1].inv;
					st[index * 2 + 2].inv = !st[index * 2 + 2].inv;
				} else if(operacion == 2){
					st[index * 2 + 1].cer = true;
					st[index * 2 + 1].inv = false;
					st[index * 2 + 2].cer = true;
					st[index * 2 + 2].inv = false;
				} else if(operacion == 3){
					st[index * 2 + 1].cer = true;
					st[index * 2 + 1].inv = true;
					st[index * 2 + 2].cer = true;
					st[index * 2 + 2].inv = true;
				}
			}
			return;
		}
		int m = (sizq + sder) / 2;
		update(uizq, uder, sizq, m, index * 2 + 1, operacion);
		update(uizq, uder, m, sder, index * 2 + 2, operacion);
		st[index].buc = st[index * 2 + 1].buc + st[index * 2 + 2].buc;
	}
	void actualizar(int uizq, int uder, int operation){
		update(uizq, uder, 0, tam / 2 + 1, 0, operation);
	}
};
int convertir(char c){
	switch(c){
		case 'I': return 1; break;
		case 'E': return 2; break;
		case 'F': return 3; break;
	}
}
int main(){
	int t, n, m, r, q, left, right;
	char c;
	string s, a;
	cin>>t;
	for(int cases = 1; cases <= t; cases++){
		vector<ll> res;
		s = "";
		cin>>m;
		for(int i = 0; i < m; i++){
			cin>>r>>a;
			for(int e = 0; e < r; e++) s += a;
		}
		n = s.size();
		//Preparar ST
		tst st;
		st.init(s, n);
		//Fin de preparacion
		cin>>q;
		for(int i = 0; i < q; i++){
			cin>>c>>left>>right;
			right++;
			if(c == 'S'){
				res.push_back(st.consultar(left, right));
			} else{
				st.actualizar(left, right, convertir(c));
			}
		}
		cout<<"Case "<<cases<<":\n";
		n = res.size();
		for(int i = 0; i < n; i++){
			cout<<"Q"<<(i + 1)<<": "<<res[i]<<"\n";
		}
	}
}
