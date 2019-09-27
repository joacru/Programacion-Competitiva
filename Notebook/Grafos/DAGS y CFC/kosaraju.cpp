const int NODOS = 100010;
vector<int> ady[NODOS], adyin[NODOS];
bool visitado[NODOS];
stack<int> kosaraju;void dfs1(int nodo){
	visitado[nodo] = true;
	int t = ady[nodo].size(), siguiente;
	for(int i = 0; i < t; i++){
		siguiente = ady[nodo][i];
		if(visitado[siguiente]) continue;
		dfs1(siguiente);
	}
	kosaraju.push(nodo);
}
int dfs2(int nodo){ //Devuelve el tamano de la CFC
	visitado[nodo] = true;
	int t = adyin[nodo].size(), siguiente, ans = 1;
	for(int i = 0; i < t; i++){
		siguiente = adyin[nodo][i];
		if(visitado[siguiente]) continue;
		ans += dfs2(siguiente);
	}
	return ans;
}
int main(){
	//Lista de adyacencia aca
	memset(visitado, false, sizeof(visitado));
	for(int i = 1; i <= n; i++){
		if(visitado[i]) continue;
		dfs1(i);
	}
	memset(visitado, false, sizeof(visitado));
	while(kosaraju.size()){
		nodo = kosaraju.top();
		kosaraju.pop();
		if(visitado[nodo]) continue;
		res = max(res, dfs2(nodo));
	}
	cout<<res<<endl; //Tamano de la CFC mas grande
	//(Claramente todo esto se puede modificar)
}
