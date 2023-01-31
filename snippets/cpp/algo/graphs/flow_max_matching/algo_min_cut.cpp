vector<pair<int, int>> minCutArcs;
int minCutIsVisited[MAX_NODES];

void minCutMarkNodes(int node) {
	if (!minCutIsVisited[node]) {
		minCutIsVisited[node] = true;
		for (int v = 0; v < MAX_NODES; v++) {
			if (flow[node][v] < cap[node][v]) {
				minCutMarkNodes(v);
			}
		}
	}
}

int getMinCut() { // Require algo_flow, return maxFlow, min cut is in minCutArcs
	int maxFlow = getMaxFlow();
	fill(minCutIsVisited, minCutIsVisited + MAX_NODES, false);
	minCutMarkNodes(sourceId);

	for (int node1 = 0; node1 < MAX_NODES; node1++) {
		for (int node2 = 0; node2 < MAX_NODES; node2++) {
			if (cap[node1][node2] > 0 && cap[node1][node2] == flow[node1][node2] && minCutIsVisited[node1] && !minCutIsVisited[node2]) {
				minCutArcs.push_back({node1, node2});
			}
		}
	}
	return maxFlow;
}

