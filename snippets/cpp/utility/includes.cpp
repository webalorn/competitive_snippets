#include <bits/stdc++.h>
using namespace std;

#define pb push_back

using lli = long long int;
using ulli = unsigned long long int;
using ld = long double;
template<class T> using heap = priority_queue<T,vector<T>,greater<T> >;

const int INF = 1e9;
const lli LLINF = 4*1e18;
const lli MOD = 1e9+7;
const lli MOD_EDU = 998244353;
const ld PI = 3.141592653589793;

// sz, carr, minset, maxset, modul, sum
template<class T> inline int sz(T structure) {return (int)structure.size();}
template<typename T> inline T carr(T val) {return val * val;}
template<class T>inline void minset(T& a,T b){if(b < a)a=b;}template<class T>inline void maxset(T& a,T b){if(a<b)a=b;}
template<typename T> T modul(T val, T __modulo = MOD) {return (val%__modulo+__modulo)%__modulo;}
template<class V> typename V::value_type sum(const V& els){auto s=0;for (const auto& e : els){s+=e;};return s;}
struct __RM_UNUSED{__RM_UNUSED(){(void)INF; (void)LLINF; (void)PI;}};// Disable warning for unused consts

string tostr(char c) { return string(1, c); } template<typename T> string tostr(T c) { return to_string(c); }
int toint(char c) {return c-'0';} int toint(string s) { return stoi(s); } // stoi, stol, stolling(c); }
int toint(char c) {return c-'0';} int toint(string s) { return stoi(s); } // stoi, stol, stoll

$0