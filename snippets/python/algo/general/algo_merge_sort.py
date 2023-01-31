def merge_sort(seq):
	if len(seq)<2: return seq
	n = len(seq)//2
	left, right = merge_sort(seq[:n]), merge_sort(seq[n:])
	i, j, n, m, seq = 0, 0, len(left), len(right), []

	while i < n and j < m:
		if left[i] < right[j]: # <Comparison>
			seq.append(left[i])
			i += 1
		else:
			seq.append(right[j])
			j += 1
	seq.extend(left[i:])
	seq.extend(right[j:])
	return seq

$0