def cumul(l, inplace=False):
	if not inplace: l = l[:]
	for i in range(1, len(l)): l[i] += l[i-1]
	return l

$0