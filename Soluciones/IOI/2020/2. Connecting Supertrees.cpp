#include "supertrees.h"
#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;

struct line{
	vector<int> nodes; //Nodos de la linea - [0] es el representante
	vector<int> dist; //Distribución de los 1s y 2s
};

int construct(std::vector<std::vector<int>> p) {
	int n = p.size();
	forn(i, n) forn(j, n) if(p[i][j] == 3) return 0;
	int used[n], parents[n];
	vector<vector<int> > ret(n, vector<int>(n, 0));
	vector<line> lines;
	forn(i, n) used[i] = 0;
	//Primero voy a formar líneas
	forn(i, n){
		if(used[i]) continue; //Ya está en una línea
		line aux;
		aux.dist = p[i];
		aux.nodes.push_back(i);
		forn(j, n){
			/*if(p[i][j] != 1){
				if(p[i][j] == 2) p[i][j] = 1; //Lo marca como 1 para después picantearla
				continue; //No me interesa
			}*/
			if(p[i][j] != 1) continue;
			if(used[j]) return 0;
			if(p[i] != p[j]) return 0; //No puede seguir
			//aux.dist[j] = 2; //Pone como 2 para luego hacer lo de los círculos
			parents[j] = i; //Agarra el representante
			used[j] = 1; //Marcar como usado
			if(i == j) continue; //No hace falta push backear al primero
			aux.nodes.push_back(j);
			ret[i][j] = 1;
			ret[j][i] = 1;
		}
		forn(j, n){
			if(p[i][j] == 2){
				p[i][j] = 1;
			}
		}
		lines.push_back(aux);
	}
	//Ahora a formar los circulitos
	for(line l : lines){ //Línea por línea ahora
		if(used[l.nodes[0]] == 2) continue; //Ya fue usado para un circulo
		vector<int> group(n, 0);
		forn(i, n){
			if(l.dist[i] == 0) continue;
			if(used[i] == 2) return 0; //Creo que la cosa va por acá
			used[i] = 2;
			if(p[parents[i]] != p[l.nodes[0]]) return 0; //Si tiene alguna diferencia
			group[parents[i]] = 1; //Lo marca como necesario
		}
		vector<int> circle;
		forn(i, n){
			if(!group[i]) continue;
			circle.push_back(i);
		}
		if(circle.size() == 1) continue;
		if(circle.size() == 2) return 0;
		forn(i, circle.size()){
			ret[circle[i]][circle[(i + 1) % circle.size()]] = ret[circle[(i + 1) % circle.size()]][circle[i]] = 1;
		}
	}
	//forn(i, n) ret[i][i] = 0; //No poner aristas en sí mismo
	build(ret);
	return 1;
}
