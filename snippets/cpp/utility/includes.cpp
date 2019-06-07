// TODO: includes

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

using lli = long long int;
using ulli = unsigned long long int;
using ld = long double;

const int INF = 1e9;
const lli LLINF = 4*1e18;
const lli MOD = 1e9+7;
const ld PI = 3.141592653589793;

// sz, carr, minset, maxset, modul, char_to_string, stoi (for char), sum
template<class T> inline int sz(T structure) {return (int)structure.size();}
template<typename T> inline T carr(T val) {return val * val;}
template<class T>inline void minset(T& a,T b){if(b < a)a=b;}template<class T>inline void maxset(T& a,T b){if(a<b)a=b;}
template<typename T> T modul(T val, T __modulo = MOD) {return (val%__modulo+__modulo)%__modulo;}
template<typename T> T modul(T val, T __modulo = MOD) {return val<0?(val%__modulo+__modulo):val%__modulo;}
struct __RM_UNUSED{__RM_UNUSED(){(void)INF; (void)PI;}};// Disable warning for unused consts
string char_to_string(char c) { return string(1, c); }
int stoi(char c, size_t* idx = 0, int base = 10) { return stoi(char_to_string(c), idx, base); }
template<typename T> T sum(vector<T> els){T s=0;for (const auto& e : els){s+=e;};return s;}