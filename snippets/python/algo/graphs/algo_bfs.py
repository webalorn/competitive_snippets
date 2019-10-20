bfs_t_tmin = [INF]*MAX_NODES

def do_bfs(sources):
	queue = copy(sources)
	for n in queue:
		bfs_t_tmin[n] = 0
	i = 0
	while i < len(queue):
		n = queue[i]
		for v in voisins[n]:
			if bfs_t_tmin[v] == INF:
				bfs_t_tmin[v] = bfs_t_tmin[n]+1
				queue.append(v)
	return bfs_t_tmin