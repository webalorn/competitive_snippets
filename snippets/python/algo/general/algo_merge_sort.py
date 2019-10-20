def merge_sort(l):
	if len(l)<2: return l
	n = len(l)//2
	l1, l2 = merge_sort(l[:n]), merge_sort(l[n:])
	i, j, n, m, l = 0, 0, len(l1), len(l2), []

	while i < n and j < m:
		if l1[i] < l2[j]: # Comparison
			l.append(l1[i])
			i += 1
		else:
			l.append(l2[j])
			j += 1
	l.extend(l1[i:] + l2[j:])
	
	return l

$0