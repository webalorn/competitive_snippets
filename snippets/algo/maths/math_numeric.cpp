template<class T> T factorielle(T n) {
	T r = 1;
	while (n) {
		r *= n;
		n--;
	}
	return r;
}

