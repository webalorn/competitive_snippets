def max_2ffix_of_prefixs(seq):
	max_len = [0]*len(seq)
	prev_len = 0
	for i_el in range(1, len(seq)):
		while True:
			if seq[prev_len] == seq[i_el]:
				prev_len += 1
				break
			elif prev_len > 0:
				prev_len = max_len[prev_len-1]
			else:
				break
		max_len[i_el] = prev_len
	return max_len

def max_2ffix_of_suffixs(seq):
	return max_2ffix_of_prefixs(seq[::-1])[::-1]