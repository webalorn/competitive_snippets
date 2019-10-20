dfs_last_seen = [-1 for _ in range(MAX_NODES)]
dfs_round = 0

def do_dfs(node):
	if dfs_last_seen[node] == dfs_round:
		return 0
	dfs_last_seen[node] = dfs_round

	all_results = []
	for child in voisins[node]:
		r = do_dfs(child)
		all_results.append(r)

	return 1 + sum(all_results)