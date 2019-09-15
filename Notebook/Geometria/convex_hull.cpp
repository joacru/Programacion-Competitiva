vector<punto> convexhull(vector<punto> p){
	int n = p.size();
	if(n < 3) return vector<punto>(); //Depende del problema
	vector<punto> hull;
	sort(p.begin(), p.end());
	hull.push_back(p[0]);
	hull.push_back(p[1]);
	punto sig;
	fori(i, 2, n){
		sig = p[i];
		while(hull.size() > 1 && giro(ult(hull, 2), ult(hull, 1), sig) > 0) hull.pop_back();
		hull.push_back(sig);
	}
	int k = hull.size();
	forrt(i, n - 2){
		sig = p[i];
		while(hull.size() > k && giro(ult(hull, 2), ult(hull, 1), sig) > 0) hull.pop_back();
		hull.push_back(sig);
	}
	n = hull.size();
	return hull;
}