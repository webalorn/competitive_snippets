
vector<int> crible_primes(int borneMax, int nbGenMax = INF) {
	vector<int> primesTab;
	if (borneMax >= 2) {
		primesTab = {2};
	}
	for (int p = 3; p <= borneMax && (int)primesTab.size() < nbGenMax; p += 2) {
		bool isPrime = true;
		for (int pp : primesTab) {
			if (p%pp == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			primesTab.push_back(p);
		}
	}
	return primesTab;
}
vector<int> genNPrimes(int nbPrimesYouWant) {
	return crible_primes(INF, nbPrimesYouWant);
}
vector<int> genPrimesUnder(int borneMax) {
	return crible_primes(borneMax, INF);
}

lli pgcd(lli a, lli b) { return (b == 0) ? a : pgcd(b, a%b); }
lli ppcm(lli a, lli b) { return a * b / pgcd(a, b); }


