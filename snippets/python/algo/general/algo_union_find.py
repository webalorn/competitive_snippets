NB_ELEMS = 1000

UF_parent = [-1]*NB_ELEMS
UF_rank = [1]*NB_ELEMS

def Find(a):
	if UF_parent[a] == -1: return a
	UF_parent[a] = Find(UF_parent[a])
	return UF_parent[a]

def Union(a, b):
	a, b = Find(a), Find(b)
	if a==b:return False
	if UF_rank[a] < UF_rank[b]: a, b = b, a
	UF_rank[a], UF_parent[b] = max(UF_rank[a], UF_rank[b]+1), a
	return True