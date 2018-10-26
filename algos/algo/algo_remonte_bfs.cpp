vector<int> bfsRemonte(int node) {
	vector<int> path;
	while (node != -1) {
		path.push_back(node);
		if (bfs_tMin[node] == 0) {
			node = -1;
		} else {
			for (auto& arc : voisins[node]) {
				if (bfs_tMin[arc.dest] == bfs_tMin[node]-1) {
					node = arc.dest;
					break;
				}
			}
		}
	}
	reverse(path.begin(), path.end());
	return path;
}

