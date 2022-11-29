#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

using lli = long long int;
using ulli = unsigned long long int;
using ld = long double;
template<class T> using heap = priority_queue<T,vector<T>,greater<T> >;
template<class A, class B> using hmap = unordered_map<A, B>;
template<class T> using hset = unordered_set<T>;
template<class T> struct Matrix : public vector<vector<T>> {Matrix(int dim1=0, int dim2=0, T v=T()) : vector<vector<T>>(dim1, vector<T>(dim2, v)) {}};

namespace std {template<class T> struct hash<vector<T>> { size_t operator() (vector<T> const& v) const {
		size_t c = v.size();for(auto& e : v) { c ^= (size_t)e + 0x9e3779b9 + (c << 6) + (c >> 2); }return c;}};}

const int INF = 1e9;
const lli LLINF = 4*1e18;
const lli MOD = 1e9+7;
const ld PI = 3.141592653589793;

// sz, carr, minset, maxset, modul, sum
template<typename T> inline T sqr(T val) {return val * val;}
template<class T>inline void minset(T& a,T b){if(b < a)a=b;}template<class T>inline void maxset(T& a,T b){if(a<b)a=b;}
template<typename T> T modul(T val, T __modulo = MOD) {return (val%__modulo+__modulo)%__modulo;}
template<class V> typename V::value_type sum(const V& els){auto s=0;for (const auto& e : els){s+=e;};return s;}
template<class V> typename V::value_type min(const V& els){return *min_element(els.begin(), els.end());}
template<class V> typename V::value_type max(const V& els){return *max_element(els.begin(), els.end());}
struct __RM_UNUSED{__RM_UNUSED(){(void)INF; (void)LLINF; (void)PI;}};// Disable warning for unused consts

string tostr(char c) { return string(1, c); } template<typename T> string tostr(T c) { return to_string(c); }
int toint(char c) {return c-'0';} int toint(string s, int base=10) { return stoi(s,0,base); } // stoi, stol, stoll

template<class T> inline T readget(){T v;cin>>v;return v;}
template <typename T, typename std::enable_if<!std::is_same<T,std::string>::value>::type* = nullptr >
istream& operator>>(istream& is,T& v){for(auto& e:v){is>>e;}return is;}
auto rng = std::default_random_engine {};
// -----------------------------------------------------------

$0