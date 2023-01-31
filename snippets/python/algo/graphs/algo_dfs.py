dfs_seen = set()
def do_dfs(node):
	if node in dfs_seen:
		return 0
	dfs_seen.add(node)

	all_results = []
	for child in voisins[node]:
		r = do_dfs(child)
		all_results.append(r)

	return 1 + sum(all_results)