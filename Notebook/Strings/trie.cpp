const short ALP;
typedef struct tnodo *pnodo;
struct tnodo{
  bool f;
  pnodo *m;
};
pnodo nuevo(){
  pnodo aux = new tnodo;
  aux->f = false;
  aux->m = new tnodo[ALP];
  forn(i, ALP) aux->m[i] = NULL;
  return aux;
}
struct trie{
  pnodo raiz;
  void init(){
    raiz = nuevo();
    raiz->f = false;
  }
  void agregar(const string &s){
    int n = s.size(), index;
    pnodo actual = raiz;
    forn(i, n){
      index = s[i] - 'a';
      if(actual->m[index] == NULL) actual->m = nuevo();
      actual = actual->m[index];
    }
    actual->f = true;
  }
  bool buscar(const string &s){
    int n = s.size(), index;
    pnodo actual = raiz;
    forn(i, n){
      index = s[i] - 'a';
      if(actual->m[index] == NULL) return false;
      actual = actual->m[index];
    }
    return actual->f;
  }
  bool eliminar(const string &s){
    int n = s.size(), index;
    pnodo actual = raiz;
    forn(i, n){
      index = s[i] - 'a';
      if(actual->m[index] == NULL) return false;
      actual = actual->m[index];
    }
    if(actual->f){
      actual->f = false;
      return true;
    } else return false;
  }
};