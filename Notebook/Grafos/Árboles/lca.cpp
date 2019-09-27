struct arbol{
  vector<int> ady[NODOS], lcasparse[NODOS], dfs;
  int profundidad[NODOS];
  bool visitado[NODOS];
  int raiz, m;
  void construirLCA(int nodo){
    int t = dfs.size(), sig;
    for(int i = 1; i <= t; i <<= 1) lcasparse[nodo].push_back(dfs[t - i]);
    visitado[nodo] = true;
    profundidad[nodo] = dfs.size();
    forn(i, t){
      if(visitado[nodo]) continue;
      construirLCA(ady[nodo][i]);
    }
    dfs.pop_back();
  }
  void construirLCA(){
    dfs.clear();
    memset(visitado, false, sizeof(visitado));
    construirLCA(raiz);
  }
  int lca(int a, int b){
    if(a == b) return a;
    if(a == raiz || b == raiz) return raiz;
    if(profundidad[a] < profundidad[b]) swap(a, b);
    int diferencia, index, t, valido;
    while(profunidad[a] != profunidad[b]){
      diferencia = profundidad[a] - profunidad[b];
      index = floor(log2(diferencia));
      a = lcasparse[a][index];
    }
    while(a != b){
      t = lcasparse[a].size();
      valido = -1;
      forn(i, t){
        if(lcasparse[a][i] == lcasparse[b][i]) break;
        valido = i;
      }
      if(valido == -1) return lcasparse[a][0];
      a = lcasparse[a][valido]; b = lcasparse[b][valido];
    }
  }
}