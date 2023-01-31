// Base functions for Geometry

using vint = lli;  // Change to lli if needed, or vfloat
using vfloat = long double;
struct Vect {
	vint x, y;
	vint normSquare() { return x*x + y*y; }
	vfloat norm() { return sqrt((vfloat)(x*x + y*y)); }
};
ostream& operator<<(ostream& os, const Vect& v) { os << v.x << " " << v.y; return os; }
istream& operator>>(istream& is, Vect& v) { is >> v.x >> v.y; return is; }
bool operator < (const Vect& a, const Vect& b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
bool operator == (const Vect& a, const Vect& b) { return a.x == b.x && a.y == b.y; }
bool operator != (const Vect& a, const Vect& b) { return !(a == b); }
Vect operator + (const Vect& a, const Vect& b) { return {a.x + b.x, a.y + b.y}; }
Vect operator - (const Vect& a, const Vect& b) { return {a.x - b.x, a.y - b.y}; }

Vect operator * (const Vect& a, vint b) { return {a.x * b, a.y * b}; } // Product by a scalar
Vect operator * (vint b, const Vect& a) { return {a.x * b, a.y * b}; }
vint operator * (const Vect& a, const Vect& b) { return a.x * b.x + a.y * b.y; } // Scalar product
vint det(const Vect& a, const Vect& b) { return a.x * b.y - b.x * a.y; } // = oriented area

// Basic geometric functions
vfloat distLineOriented(const Vect& point, const Vect& lineA, const Vect& lineB) { // Oriented distance
	return det(lineB-lineA, point-lineA) / (lineB-lineA).norm();
}
vfloat projOnLineDistOriented(const Vect& point, const Vect& lineA, const Vect& lineB) { // Oriented distance
	return (vfloat)((lineB-lineA) * (point-lineA)) / (lineB-lineA).norm();
}
vfloat angleBtw(const Vect& v1, const Vect& v2) { return atan2(det(v1, v2), v1 * v2); }
vfloat angleBtw(const Vect& center, const Vect& pt1, const Vect& pt2){return angleBtw(pt1-center, pt2-center);}
vfloat rad2deg(vfloat a) { return 180 * a / PI; } vfloat deg2rad(vfloat a) { return PI * a / 180; }