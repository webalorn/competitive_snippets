//@title Functions for quick access to common mathematical operations
//@defines crible_primes, genNPrimes, genNPrimesLli, genPrimesUnder, genPrimesUnderLli, divisorsOf
//@defines pgcd, ppcm, genRange
//@doc Mathematical functions
//@doc Include functions for prime numbers
//@
template<typename T> vector<T> crible_primes(T borneMax, int nbGenMax = INF) {
	vector<T> primesTab;
	if (borneMax >= 2) { primesTab = {2}; }
	for (T p = 3; p <= borneMax && (int)primesTab.size() < nbGenMax; p += 2) {
		bool isPrime = true;
		for (auto pp : primesTab) {
			if (p%pp == 0) {
				isPrime = false;
				break;
		}} if (isPrime) { primesTab.push_back(p); }
	} return primesTab;
}
vector<int> genNPrimes(int nbPrimesYouWant) { return crible_primes<int>(INF, nbPrimesYouWant); }
vector<lli> genNPrimesLli(lli nbPrimesYouWant) { return crible_primes<lli>(LLINF, nbPrimesYouWant); }
vector<int> genPrimesUnder(int borneMax) { return crible_primes<int>(borneMax, INF); } // Including 'borneMax'
vector<lli> genPrimesUnderLli(lli borneMax) { return crible_primes<lli>(borneMax, INF); }// Including 'borneMax'

template<typename T> vector<T> divisorsOf(T n){vector<T> d;for (T k=1;k<=n;k++){if(n%k==0){d.push_back(k);}}return d;}

template<typename T> T pgcd(T a, T b) { return (b == 0) ? a : pgcd(b, a%b); }
template<typename T> T ppcm(T a, T b) { return a * b / pgcd(a, b); }
template<typename T> T pgcd(vector<T> nums){T r=nums[0];for(int i=1; i<(int)nums.size();i++){r=pgcd(r,nums[i]);}return r;}
template<typename T> T ppcm(vector<T> nums){T r=nums[0];for(int i=1; i<(int)nums.size(); i++){r=ppcm(r,nums[i]); }return r;}

template<typename T = int> vector<T> genRange(T startAt,T endBefore,T step=1) {vector<T> r;while ((step > 0 && startAt < endBefore) || (step < 0 && startAt > endBefore)) {r.push_back(startAt);startAt += step;}return r;}


/*
* Return a vector of all the prime factors of an integer, in ascending order
*/
template<typename T> vector<T> getPrimeFactors(T n) {
	T k = 2; vector<T> factors;
	while (k*k <= n) {
		if (n%k == 0) {
			factors.push_back(k);
			n /= k;
		} else { k++; }
	} if (n > 1) { factors.push_back(n); }
	return factors;
}

/*
* Return true iff n is a palindromic number in the given base
*/
template<typename T> bool isNumPalindrom(T n, T base=10) {
	T n2 = n; T inv = 0;
	while (n2 > 0) { inv = inv * base + n2 % base; n2 /= base; }
	return inv == n;
}