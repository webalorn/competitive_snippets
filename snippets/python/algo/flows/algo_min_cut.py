# <This algorithm needs algo_max_flow>

def min_cut_from_flow(sources, flow, capacity):
	voisins = voisins_from_edges([(e1, e2, c) for (e1, e2), c in capacity.items() if c > 0])

	seen_nodes = set()
	for src in sources:
		if src not in seen_nodes:
			stack = [src]
			seen_nodes.add(src)
			while stack:
				node = stack.pop()
				for vois in voisins[node]:
					if vois not in seen_nodes and flow[(node, vois)] < capacity[(node, vois)]:
						seen_nodes.add(vois)
						stack.append(vois)

	cut_edges = [e for e, cap in capacity.items()
		if cap > 0 and cap == flow[e] and e[0] in seen_nodes and e[1] not in seen_nodes
	]
					
	return cut_edges