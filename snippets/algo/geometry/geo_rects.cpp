// Geometry functions for rectangles. Requires geo_base

struct Rect { // Defined by min x/y and max x/y corners
	Vect cor1, cor2;
	vint area(){ Vect diag = cor2 - cor1; return abs(diag.x * diag.y); }
	Rect intersect(const Rect& other) {
		Rect r = {{max(cor1.x, other.cor1.x), max(cor1.y, other.cor1.y)},
					{min(cor2.x, other.cor2.x), min(cor2.y, other.cor2.y)}};
		r.cor2 = {max(r.cor1.x, r.cor2.x), max(r.cor1.y, r.cor2.y)};
		return r;
	}
};
ostream& operator<<(ostream& os, const Rect& r) { os << r.cor1 << " " << r.cor2; return os; }
istream& operator>>(istream& is, Rect& r) { is >> r.cor1 >> r.cor2; return is; }