//@title Functions for quick access to common mathematical operations
//@defines crible_primes, genNPrimes, genNPrimesLli, genPrimesUnder, genPrimesUnderLli
//@doc Include functions for prime numbers
//@
/* Return a vector of all the prime factors of an integer, in ascending order */
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