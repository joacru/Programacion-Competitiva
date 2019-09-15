#include<bits/stdc++.h>
using namespace std;
typedef struct tnodo *pnodo;
struct tnodo{
	char dato;
	pnodo ant, sig;
};
struct lista{
	pnodo ini, fin;
	int n;
	void init(){
		ini = fin = NULL;
		n = 0;
	}
	pnodo crearnodo(char dato){
		pnodo aux = new tnodo;
		aux->dato = dato;
		aux->ant = NULL;
		aux->sig = NULL;
		return aux;
	}
	void insertari(char dato){
		pnodo nuevo = crearnodo(dato);
		if(ini == NULL){
			ini = fin = nuevo;
			n = 1;
			return;
		}
		n++;
		nuevo->sig = ini;
		ini->ant = nuevo;
		ini = nuevo;
	}
	void insertarf(char dato){
		pnodo nuevo = crearnodo(dato);
		if(ini == NULL){
			ini = fin = nuevo;
			n = 1;
			return;
		}
		n++;
		nuevo->ant = fin;
		fin->sig = nuevo;
		fin = nuevo;
	}
	void insertard(char dato, pnodo pos){
		n++;
		pnodo nuevo = crearnodo(dato);
		if(fin == pos){
			pos->sig = nuevo;
			nuevo->ant = pos;
			fin = nuevo;
		} else{
			nuevo->sig = pos->sig;
			pos->sig = nuevo;
			nuevo->ant = pos;
			nuevo->sig->ant = nuevo;
		}
	}
	void insertara(char dato, pnodo pos){
		n++;
		pnodo nuevo = crearnodo(dato);
		if(ini == pos){
			pos->ant = nuevo;
			nuevo->sig = pos;
			ini = nuevo;
		} else{
			nuevo->ant = pos->ant;
			pos->ant = nuevo;
			nuevo->sig = pos;
			nuevo->ant->sig = nuevo;
		}
	}
	char quitari(){
		char sacado = NULL;
		if(ini != NULL){
			n--;
			sacado = ini->dato;
			if(ini == fin){
				//delete ini;
				//delete fin;
				ini = fin = NULL;
				n = 0;
			} else{
				//delete ini;
				ini = ini->sig;
				ini->ant = NULL;
			}
		}
		return sacado;
	}
	char quitarf(){
		char sacado = NULL;
		if(fin != NULL){
			n--;
			sacado = fin->dato;
			if(ini == fin){
				//delete ini;
				//delete fin;
				ini = fin = NULL;
				n = 0;
			} else{
				//delete ini;
				fin = fin->ant;
				fin->sig = NULL;
			}
		}
		return sacado;
	}
	char consultari(){
		if(ini != NULL) return ini->dato;
		return NULL;
	}
	char consultarf(){
		if(fin != NULL) return fin->dato;
		return NULL;
	}
	void unir(lista &b, bool inicio = true){
		if(b.vacia()) return;
		n += b.n;
		if(vacia()){
			ini = b.ini;
			fin = b.fin;
			n = b.n;
			b.init();
			return;
		}
		if(inicio){
			b.fin->sig = ini;
			ini->ant = b.fin;
			ini = b.ini;
		} else{
			b.ini->ant = fin;
			fin->sig = b.ini;
			fin = b.fin;
		}
		b.init();
	}
	bool vacia(){
		return (ini == NULL || fin == NULL);
	}
	void mostrar(){
		if(!n) return;
		cout<<ini->dato;
		for(pnodo p = ini->sig; p != NULL; p = p->sig) cout<<" "<<p->dato;
	}
	void liberar(){
		if(vacia()) return;
		pnodo disp;
		for(pnodo p = ini; p != NULL; p){
			disp = p;
			p = p->sig;
			delete disp;
		}
	}
};
const bool uno = false;
const bool dos = true;
const int MAX = 52;
int main(){
	int estado, contador;
	string s;
	bool jugador;
	char ultimo;
	lista mano[2], pila;
	cin>>s;
	while(s[0] != '#'){
		mano[uno].init();
		mano[dos].init();
		pila.init();
		jugador = uno;
		mano[jugador].insertari(s[1]);
		for(int i = 1; i < MAX; i++){
			jugador = !jugador;
			cin>>s;
			mano[jugador].insertari(s[1]);
		}
		jugador = uno;
		estado = 1;
		while(!mano[jugador].vacia()){
			ultimo = mano[jugador].quitari();
			pila.insertarf(ultimo);
			if(estado == 1){ //Descartar hasta que aparezca una "cara"
				switch(ultimo){
					case 'J':
						estado = 2;
						contador = 1;
						break;
					case 'Q':
						estado = 2;
						contador = 2;
						break;
					case 'K':
						estado = 2;
						contador = 3;
						break;
					case 'A':
						estado = 2;
						contador = 4;
						break;
				}
				jugador = !jugador;
			} else if(estado == 2){ //Descartar tanto como contador o hasta "cara"
				contador--;
				switch(ultimo){
					case 'J':
						jugador = !jugador;
						contador = 1;
						break;
					case 'Q':
						jugador = !jugador;
						contador = 2;
						break;
					case 'K':
						jugador = !jugador;
						contador = 3;
						break;
					case 'A':
						jugador = !jugador;
						contador = 4;
						break;
					default:
						if(contador == 0){
							estado = 1;
							jugador = !jugador;
							mano[jugador].unir(pila, false);
						}
						break;
				}
			}
		}
		printf("%d%3d\n", jugador + 1, mano[!jugador].n);
		mano[0].liberar();
		mano[1].liberar();
		pila.liberar();
		cin>>s;
	}
}
