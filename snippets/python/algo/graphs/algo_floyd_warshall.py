def floyd_warshall(edges, oriented):
	nodes = {v for v, _, _ in edges}
	nodes.update({v for _, v, _ in edges})
	dists = {(a, b): 0 if a == b else LLINF for a in nodes for b in nodes}
	for a, b, length in edges:
		dists[(a, b)] = min(dists[(a, b)], length)
		if not oriented:
			dists[(b, a)] = min(dists[(b, a)], length)
	for pivot in nodes:
		for dest in nodes:
			for source in nodes:
				dists[(source, dest)] = min(dists[(source, dest)], dists[(source, pivot)] + dists[(pivot, dest)])
	return dists

