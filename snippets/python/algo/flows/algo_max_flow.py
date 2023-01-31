def max_flow_of_graph(edges, sources, sinks):
	# Edges should be a list of (from, to, flow_cap)
	flow = {}
	capacity = {}
	voisins = {}
	if len(sinks) > 5:
		sinks = set(sinks)
	for e_from, e_to, _ in edges:
		capacity[(e_from, e_to)] = 0
		capacity[(e_to, e_from)] = 0
		flow[(e_from, e_to)] = 0
		flow[(e_to, e_from)] = 0
		voisins[e_to] = []
		voisins[e_from] = []
	for e_from, e_to, e_cap in edges:
		capacity[(e_from, e_to)] += e_cap
		voisins[e_to].append(e_from)
		voisins[e_from].append(e_to)

	cap_max = max(capacity.values())
	try_to_push = 2**int(log2(max(1, cap_max)))
	pushed_flow = 0

	while try_to_push:
		for src in sources:
			pushed = False
			stack = [(src, 0)]
			seen_nodes = set([src])
			while stack and not pushed:
				node, i_vois = stack.pop()
				if node in sinks:
					pushed = True
					stack.append((node, 0))
					break

				while (i_vois < len(voisins[node])
					and capacity[(node, voisins[node][i_vois])] - flow[(node, voisins[node][i_vois])] < try_to_push):
					i_vois += 1 # We want only the residual edges (capacity >= try_to_push)
				if i_vois < len(voisins[node]):
					next_node = voisins[node][i_vois]
					stack.append((node, i_vois+1))
					if not next_node in seen_nodes:
						stack.append((next_node, 0))
						seen_nodes.add(next_node)

			if pushed:
				pushed_flow += try_to_push
				for (e1, _), (e2, _) in zip(stack, stack[1:]):
					flow[(e1, e2)] += try_to_push
					flow[(e2, e1)] -= try_to_push
				break
		else:
			try_to_push //= 2

	return pushed_flow, flow, capacity

