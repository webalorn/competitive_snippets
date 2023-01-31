//@title Functions for quick access to common mathematical operations
//@defines pgcd, ppcm, genRange, divisorsOf, factorial
//@doc Mathematical functions
//@
template<typename T> vector<T> divisorsOf(T n){vector<T> d;for (T k=1;k<=n;k++){if(n%k==0){d.push_back(k);}}return d;}

template<typename T> T pgcd(T a, T b) { return (b == 0) ? a : pgcd(b, a%b); }
template<typename T> T ppcm(T a, T b) { return a * b / pgcd(a, b); }
template<typename T> T pgcd(vector<T> nums){T r=nums[0];for(int i=1;i<(int)nums.size();i++){r=pgcd(r,nums[i]);}return r;}
template<typename T> T ppcm(vector<T> nums){T r=nums[0];for(int i=1;i<(int)nums.size();i++){r=ppcm(r,nums[i]);}return r;}

template<typename T=int> vector<T> genRange(T startAt,T endBefore,T step=1) {vector<T> r;while ((step > 0 && startAt < endBefore) || (step < 0 && startAt > endBefore)) {r.push_back(startAt);startAt += step;}return r;}

template<typename T> bool isNumPalindrom(T n, T base=10) {
	T n2 = n; T inv = 0; while (n2 > 0) { inv = inv * base + n2 % base; n2 /= base; }
	return inv == n;}

template<class T> T factorial(T n) {T r=1;while(n){r *= n;n--;}return r;}
template<class T> T binom(T k, T n) {T a=1,b=1;while(k){a*=(n-k+1);b*=k;k--;}return a/b;}