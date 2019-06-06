#include <bits/stdc++.h>
using namespace std;

#define pb push_back

using lli = long long int;
using ulli = unsigned long long int;
using ld = long double;

const int INF = 1e9;
const lli MOD = 1e9+7;
const ld PI = 3.141592653589793;

// sz, carr, ri, pi, minset, maxset, modul
template<class T> inline int sz(T structure) {return (int)structure.size();}
template<typename T> inline T carr(T val) {return val * val;}
char __ri_str[100];void ri(){}inline void ri(int& val) {scanf("%d", &val);}inline void ri(char& val) {scanf(" %c", &val);}inline void ri(double& val) {scanf("%lf", &val);}
inline void ri(string& val) {scanf("%s", __ri_str);val=__ri_str;}template<typename T, typename ... T2> inline void ri(T& val, T2& ... rest) {ri(val); ri(rest...);}
void pi(){}inline void pi(const int& val) {printf("%d", val);}inline void pi(const char& val) {printf("%c", val);}inline void pi(const double& val) {printf("%lf", val);}
inline void pi(const string& val) {printf("%s", val.c_str());}inline void pi(const char* val) {printf("%s", val);}
template<typename T, typename ... T2> inline void pi(const T val, const T2 ... rest) {pi(val); pi(rest...);}
template<class T> void minset(T& a, T b) { if (b < a) a = b; }template<class T> void maxset(T& a, T b) { if (b>a) a = b; }
template<typename T> T modul(T val, T __modulo = MOD) { return (val%__modulo + __modulo)%__modulo; }
struct __RM_UNUSED{__RM_UNUSED(){(void)INF; (void)PI;}};


