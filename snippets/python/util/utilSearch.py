def lower_bound(n, l):
	a, b = 0, len(l)
	while a+1<b:
		m = (a+b-1)//2
		if l[m] >= n: b = m+1
		else: a = m+1
	return a

def upper_bound(n, l):
	a, b = 0, len(l)
	while a+1<b:
		m = (a+b)//2
		if l[m] <= n: a = m+1
		else: b = m+1
	return a

def get_val_range(n, l): return (lower_bound(n, l), upper_bound(n, l))

def is_in_sorted(n, l):
	i = lower_bound(n, l)
	return i < len(l) and l[i] == n