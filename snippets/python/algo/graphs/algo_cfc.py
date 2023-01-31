def transpose_graph(voisins):
	voisins_T = [[] for _ in range(len(voisins))]
	for a, l in enumerate(voisins):
		for b in l:
			voisins_T[b].append(a)
	return voisins_T

def compute_cfc(voisins):
	n_nodes = len(voisins)
	seen = [False] * n_nodes
	seen_order = []
	for start in range(n_nodes):
		if not seen[start]:
			stack = [(start, 0)]
			while stack:
				cur, step = stack.pop()
				if step == 0 and not seen[cur]:
					seen[cur] = True
					stack.append((cur, 1))
					stack.extend([(v, 0) for v in voisins[cur] if not seen[v]])
				elif step == 1:
					seen_order.append(cur)

	cfcs = []
	seen = [False] * n_nodes
	voisins_T = transpose_graph(voisins)
	for start in seen_order[::-1]:
		if not seen[start]:
			cfcs.append([])
			stack = [start]
			while stack:
				cur = stack.pop()
				if not seen[cur]:
					seen[cur] = True
					cfcs[-1].append(cur)
					stack.extend([v for v in voisins_T[cur] if not seen[v]])
	return cfcs