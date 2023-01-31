def min_cost_max_flow_init_bellman_ford(flow_edges, sources):
	dist_min = {vertex: LLINF for vertex in flow_edges}
	dist_min.update({s: 0 for s in sources})
	for step in range(len(flow_edges)-1):
		for vertex, v_edges in flow_edges.items():
			if dist_min[vertex] != LLINF:
				for e_to, e_cost, e_flow, e_cap, e_rev_id in v_edges:
					dist_min[e_to] = min(dist_min[e_to], dist_min[vertex] + e_cost)
	return dist_min

def dijkstra_find_flow_paths(flow_edges, potential, sources, sinks):
	dist_min = {vertex: LLINF for vertex in flow_edges}
	dist_min.update({s: 0 for s in sources})
	dij_prev = {v: None for v in flow_edges}

	sits = [(s, 0) for s in sources]
	heapq.heapify(sits)
	while sits: # Dijkstra
		vertex, time = heapq.heappop(sits)
		if time == dist_min[vertex]:
			for i_edge, (e_to, e_cost, e_flow, e_cap, e_rev_id) in enumerate(flow_edges[vertex]):
				t2 = time + e_cost + potential[vertex] - potential[e_to]
				if e_cap > e_flow and t2 < dist_min[e_to]:
					dij_prev[e_to] = (vertex, i_edge)
					dist_min[e_to] = t2
					heapq.heappush(sits, (e_to, t2))
	return any(dist_min[s] != LLINF for s in sinks), dist_min, dij_prev

def min_cost_max_flow_of_graph(edges, sources, sinks):
	""" This implementation of min-cos max-flow works with positive AND negative costs, but no negative cycle """
	# Edges should be a list of [from, to, flow_cap, cost]
	if len(sources) > 5:
		sources = set(sources)
	# flow_edges: [from: (to, cost, flow, cap, reverse_id)]
	flow_edges = {v: [] for v, _, _, _ in edges}
	flow_edges.update({v: [] for _, v, _, _ in edges})

	for e_from, e_to, e_cap, e_cost in edges:
		id_from, id_to = len(flow_edges[e_from]), len(flow_edges[e_to])
		flow_edges[e_from].append([e_to,  e_cost, 0, e_cap, id_to])
		flow_edges[e_to].append([e_from, -e_cost, 0, 0, id_from])

	potential = min_cost_max_flow_init_bellman_ford(flow_edges, sources)
	min_cost, max_flow = 0, 0
	while True:
		can_push_dij, dist_min, dij_prev = dijkstra_find_flow_paths(flow_edges, potential, sources, sinks)
		if not can_push_dij:
			break
		for v in flow_edges:
			potential[v] += dist_min[v]

		path = [([s for s in sinks if dist_min[s] != LLINF][0], None)]
		while path[-1][0] not in sources:
			path.append(dij_prev[path[-1][0]])
		path = path[1:][::-1] # Remove the sink node as we don't need it
		
		delta = min([flow_edges[e_from][e_id][3] - flow_edges[e_from][e_id][2] for e_from, e_id in path])
		for e_from, e_id in path:
			e_to, e_cost, e_flow, e_cap, e_rev_id = flow_edges[e_from][e_id]
			flow_edges[e_from][e_id][2] += delta # 2 = e_flow
			flow_edges[e_to][e_rev_id][2] -= delta # 2 = e_flow
			min_cost += delta * e_cost
		max_flow += delta

	return min_cost, max_flow, flow_edges