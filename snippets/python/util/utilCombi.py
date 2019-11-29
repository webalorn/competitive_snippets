def get_permuts(l,r=None): return list(itertools.permutations(l, r))

def next_permutation(l):
	i=len(l)-2
	while i>=0 and l[i+1]<=l[i]:i-=1
	if i<0: return l[::-1]
	j=i
	while j+1<len(l) and l[j+1]>=l[i]:j+=1
	return l[:i] + [l[j]] + l[j+1:][::-1] + ([l[i]] if i-j else []) + l[i+1:j][::-1]