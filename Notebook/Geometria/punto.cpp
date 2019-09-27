struct punto{
	double x, y;
	bool operator <(const punto &b) const{
		if(x == b.x) return y < b.y;
		return x < b.x;
	}
	bool operator ==(const punto &b) const{ return x == b.x && y == b.y; }
};
double giro(punto a, punto b, punto c){ //Segmentos AB y BC
	c.x -= b.x;
	c.y -= b.y;
	b.x -= a.x;
	b.y -= a.y;
	//Ahora los vectores son b y c
	return b.x * c.y - c.x * b.y; //Producto cruzado
};