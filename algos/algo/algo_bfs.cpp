/*@
@ Algo de BFS
@ */
int bfs_tMin[MAX_NODES+1];

struct __BFS_Init {
	__BFS_Init() {
		fill(bfs_tMin, bfs_tMin + MAX_NODES, INF);
	}
} __bFS_Init;

void bfsFrom(int source) {
	fill(bfs_tMin, bfs_tMin+nbNodes+1, INF);

	bfs_tMin[source] = 0;
	deque<int> bfsQ;
	bfsQ.push_back(source);

	while (!bfsQ.empty()) {
		int node = bfsQ.front();
		bfsQ.pop_front();
		for (auto& v : voisins[node]) {
			if (bfs_tMin[v.dest] == INF) {
				bfs_tMin[v.dest] = bfs_tMin[node] + 1;
				bfsQ.push_back(v.dest);
			}
		}
	}
}

