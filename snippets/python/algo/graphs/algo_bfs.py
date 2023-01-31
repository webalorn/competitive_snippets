def do_bfs_list(sources, bfs_voisins=None):
	bfs_t_tmin = [INF] * MAX_NODES
	prev = [None] * MAX_NODES
	queue = copy(sources)
	for src in queue:
		bfs_t_tmin[src] = 0
	cur_pos_id = 0
	while cur_pos_id < len(queue):
		cur_pos = queue[cur_pos_id]
		cur_pos_id += 1
		cur_voisins = bfs_voisins[cur_pos] # <TODO: change if needed>
		for vois in cur_voisins:
			if bfs_t_tmin[vois] == INF:
				bfs_t_tmin[vois] = bfs_t_tmin[cur_pos]+1
				prev[vois] = cur_pos
				queue.append(vois)
	return bfs_t_tmin, prev

def do_bfs_any(sources, bfs_voisins=None): 
	bfs_t_tmin, prev = {}, {}
	queue = deque(copy(sources))
	for src in queue:
		bfs_t_tmin[src] = 0
		prev[src] = None
	while queue:
		cur_pos = queue.popleft()
		cur_voisins = bfs_voisins[cur_pos] # <TODO: change if needed>
		# cur_voisins = [(x+dx, y+dy) for dx, dy in moves if is_pos_valid(x+dx, y+dy, n)]
		for vois in cur_voisins:
			if vois not in bfs_t_tmin:
				dt = 1 # <Can be set to 0 and 1> # 1 if grid[vois[0]][vois[1]] == ? else 0
				bfs_t_tmin[vois] = bfs_t_tmin[cur_pos]+dt
				prev[vois] = cur_pos
				if dt: queue.append(vois)
				else: queue.appendleft(vois)
	return bfs_t_tmin, prev

def get_bfs_path(prev, target):
	path = [target]
	while prev[path[-1]] is not None:
		path.append(prev[path[-1]])
	return path[::-1]