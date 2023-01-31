// Geometry functions for segments. Requires geo_base

struct Seg {
	Vect pt1, pt2;
	vfloat normSquare() { return (pt2-pt1).normSquare(); }
	vfloat norm() { return (pt2-pt1).norm(); }
	vfloat distTo(Vect pt) {
		vfloat proj = projOnLineDistOriented(pt, pt1, pt2);
		if (proj >= 0 && proj <= this->norm()) {
			return abs(distLineOriented(pt, pt1, pt2));
		}
		return min((pt-pt1).norm(), (pt-pt2).norm());
	}
	bool isOnLine(Vect point) { return det(point-pt1, pt2-pt1) == 0; }
	bool isOnSeg(Vect point) {
		auto v = (point-pt1) * (pt2-pt1);
		return det(point-pt1, pt2-pt1) == 0 && v >= 0 && v <= this->normSquare();
	}
};
ostream& operator<<(ostream& os, const Seg& s) { os << s.pt1 << " " << s.pt2; return os; }
istream& operator>>(istream& is, Seg& s) { is >> s.pt1 >> s.pt2; return is; }
vfloat distLineOriented(const Vect& point, const Seg& s) { return distLineOriented(point, s.pt1, s.pt2); }
vfloat projOnLineDistOriented(const Vect& p, const Seg& s){return projOnLineDistOriented(p, s.pt1, s.pt2);}

Vect intersetLines(const Seg& a, const Seg& b) { // Works only if vint = float / double
	return b.pt1 + (det(a.pt2-a.pt1, a.pt2-b.pt1) / (vfloat)det(a.pt2-a.pt1, b.pt2-b.pt1)) * (b.pt2-b.pt1);
}
bool isThereIntersection(const Seg& a, const Seg& b) {
	if (det(a.pt2-a.pt1, b.pt2-b.pt1) == 0) return false;
	vfloat t1 = (vfloat)det(a.pt2-a.pt1, a.pt2-b.pt1) / (vfloat)det(a.pt2-a.pt1, b.pt2-b.pt1);
	vfloat t2 = (vfloat)det(b.pt2-b.pt1, b.pt2-a.pt1) / (vfloat)det(b.pt2-b.pt1, a.pt2-a.pt1);
	return 0 <= t1 && t1 <= 1 && 0 <= t2 && t2 <= 1;
}