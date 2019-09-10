
typedef struct tnodo *pnodo;
struct tnodo{
	int dato;
	pnodo ant, sig;
};
struct lista{
	pnodo ini, fin;
	int n;
	void init(){
		ini = NULL;
		fin = NULL;
		n = 0;
	}
	pnodo crearnodo(int dato){
		pnodo aux = new tnodo;
		aux->dato = dato;
		aux->ant = NULL;
		aux->sig = NULL;
		return aux;
	}
	void insertari(int dato){
		pnodo nuevo = crearnodo(dato);
		if(!n){
			ini = fin = nuevo;
			n = 1;
			return;
		}
		n++;
		nuevo->sig = ini;
		ini->ant = nuevo;
		ini = nuevo;
	}
	void insertarf(int dato){
		pnodo nuevo = crearnodo(dato);
		if(!n){
			ini = fin = nuevo;
			n = 1;
			return;
		}
		n++;
		nuevo->ant = fin;
		fin->sig = nuevo;
		fin = nuevo;
	}
	void insertard(int dato, pnodo pos){
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
	void insertara(int dato, pnodo pos){
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
	int quitari(){
		int sacado = NULL;
		if(n){
			sacado = ini->dato;
			if(ini == fin){
				ini = fin = NULL;
				n = 0;
			} else{
				ini = ini->sig;
				ini->ant = NULL;
			}
		}
		return sacado;
	}
	int quitarf(){
		int sacado = NULL;
		if(n){
			sacado = fin->dato;
			if(ini == fin){
				ini = fin = NULL;
				n = 0;
			} else{
				fin = fin->ant;
				fin->sig = NULL;
			}
		}
		return sacado;
	}
	int consultari(){
		if(n) return ini->dato;
		return NULL;
	}
	int consultarf(){
		if(n) return fin->dato;
		return NULL;
	}
	void unir(lista &b, bool inicio = true){
		if(!b.n) return;
		n += b.n;
		if(!n){
			ini = b.ini;
			fin = b.fin;
			n = b.n;
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
	void mostrar(){
		if(!n) return;
		cout<<ini->dato;
		for(pnodo p = ini->sig; p != NULL; p = p->sig) cout<<" "<<p->dato;
	}
};