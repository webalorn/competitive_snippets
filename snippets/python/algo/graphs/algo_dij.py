def do_dij(sources, dij_voisins=None):
	tmin, prev = {}, {}
	# tmin = [INF] * MAX_NODES
	# prev = [None] * MAX_NODES
	# dij_voisins = dij_voisins or [[] for _ in range(MAX_NODES + 1)]

	sit_heap = [(0, s) for s in sources]
	heapq.heapify(sit_heap)
	for _t, _s in sit_heap:
		tmin[_s], prev[_s] = _t, None
	while sit_heap:
		cur_time, pos = heapq.heappop(sit_heap)
		if tmin[pos] == cur_time:
			for (vois, length) in dij_voisins[pos]:
				if cur_time + length < tmin.get(vois, LLINF):
					tmin[vois] = cur_time + length
					prev[vois] = pos
					heapq.heappush(sit_heap, (cur_time + length, vois))
	return tmin, prev

def get_dij_path(prev, target):
	path = [target]
	while prev[path[-1]] is not None:
		path.append(prev[path[-1]])
	return path[::-1]