//@
//@title Algo de BFS
//@
using BFS_Sit = int;

int bfs_tMin[MAX_NODES+1];

struct __BFS_Init {
	__BFS_Init() {
		fill(bfs_tMin, bfs_tMin + MAX_NODES, INF);
	}
} __bFS_Init;

void bfsFrom(vector<BFS_Sit> sources) {
	fill(bfs_tMin, bfs_tMin+nbNodes+1, INF);

	deque<BFS_Sit> bfsQ;
	for (BFS_Sit& s : sources) {
		bfs_tMin[s] = 0;
		bfsQ.push_back(s);
	}

	while (!bfsQ.empty()) {
		BFS_Sit node = bfsQ.front();
		bfsQ.pop_front();
		for (auto& v : voisins[node]) {
			if (bfs_tMin[v.dest] == INF) {
				bfs_tMin[v.dest] = bfs_tMin[node] + 1;
				bfsQ.push_back(v.dest);
			}
		}
	}
}

void bfsFrom(BFS_Sit source) { bfsFrom({source}); }