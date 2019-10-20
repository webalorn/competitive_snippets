def is_prime(n, primes):
	for p in primes:
		if not n%p: return False
	return True

def crible_primes(borne_max, nb_gen_max=INF):
	primes = [] if borne_max < 2 else [2]
	for p in range(3, borne_max+1, 2):
		if len(primes) >= nb_gen_max: return primes
		if is_prime(p, primes): primes.append(p)
	return primes

def gen_n_primes(n): return crible_primes(INF, n)
def gen_primesUnder(p_max): return crible_primes(p_max, INF)

def get_primes_factors(n):
	k, f = 2, []
	while k*k <= n:
		if n%k==0:
			f.append(k)
			n //=k
		else: k+=1
	return f

def pgcd(a, b): return a if not b else pgcd(b, a%b)
def ppcm(a, b): return a*b // pgcd(a, b)

def fact(n): return reduce(lambda x,y:x*y, list(range(1,n+1)), 1)
def binom(k, n): return fact(n) // (fact(k) * fact(n-k))
def is_palindrom(n): return str(n) == str(n)[::-1]

