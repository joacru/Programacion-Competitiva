#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
const short ALP = 26;
int n;
typedef struct tnodo *pnodo;
struct tnodo{
	bool f;
	pnodo *a;
	int grado;
};
pnodo nuevonodo(){
	pnodo aux = new tnodo;
	aux->f = false;
	aux->a = new pnodo[ALP];
	forn(i, ALP) aux->a[i] = NULL;
	aux->grado = 0;
	return aux;
}
struct trie{
	pnodo raiz;
	float pres;
	void init(){
		raiz = nuevonodo();
		raiz->f = true;
		pres = 0;
	}
	void agregar(const string &s){
		int n = s.size(), index;
		pnodo actual = raiz;
		forn(i, n){
			index = s[i] - 'a';
			if(actual->a[index] == NULL){
				actual->a[index] = nuevonodo();
				actual->grado++;
			}
			actual = actual->a[index];
		}
		actual->f = true;
	}
	void recorrer(pnodo actual, int teclas){
		if(actual->f) pres += teclas;
		forn(i, ALP){
			if(actual->a[i] != NULL){
				recorrer(actual->a[i], (actual->grado > 1 || actual->f)? teclas + 1: teclas);
				delete actual->a[i];
			}
		}
	}
	void recorrer(){ recorrer(raiz, 0); }
};
int main(){
	int n;
	string s;
	trie t;
	while(cin>>n){
		t.init();
		forn(i, n){
			cin>>s;
			t.agregar(s);
		}
		t.recorrer();
		printf("%.2f\n", t.pres / float(n));
	}
}
