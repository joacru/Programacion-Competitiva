const int NODOS = 1000000; //Maxima cantidad de nodos

//Grafo no pesado
vector<int> grafo[NODOS + 1];

//Grafo pesado
typedef pair<int, ll> arista;
vector<arista> grafo[NODOS + 1];