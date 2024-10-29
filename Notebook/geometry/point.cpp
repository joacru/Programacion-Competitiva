typedef long long T;

struct Pt{
	T x,y;
	
	Pt operator+(const Pt& o) const{
		return {x+o.x,y+o.y};
	}
	Pt operator-(const Pt& o) const{
		return {x-o.x,y-o.y};
	}
	T operator*(const Pt& o) const{
		return {x*o.y-o.x*y};
	}
	T operator^(const Pt& o) const{
		return {x*o.x+y*o.y};
	}
	bool ccw(const Pt& o) const{
		return *this*o>=0;
	}
	bool ccw2(const Pt& o) const{
		return *this*o>0;
	}
	
	bool operator<(const Pt& o) const{
		if(x != o.x) return x < o.x;
		return y < o.y;
	}
	
	bool operator==(const Pt& o) const{
		return x == o.x && y == o.y;
	}
};

bool ccw(Pt a, Pt b, Pt c){
	a=b-a; b=c-b;
	return a.ccw(b);
}
bool ccw2(Pt a, Pt b, Pt c){
	a=b-a; b=c-b;
	return a.ccw2(b);
}

ostream& operator<<(ostream& os, const Pt& a){
	os<<"("<<a.x<<","<<a.y<<")";
	return os;
}
