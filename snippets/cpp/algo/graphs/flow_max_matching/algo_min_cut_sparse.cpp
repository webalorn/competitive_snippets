vector<Edge> minCutEdges;
vector<int> minCutIsVisited;

void minCutMarkNodes(int iVertex) {
	if (!minCutIsVisited[iVertex]) {
		minCutIsVisited[iVertex] = true;
		for (auto& e : flowEdges[iVertex]) {
			if (e.flow < e.cap) {
				minCutMarkNodes(e.to);
			}
		}
	}
}

int getMinCut() { // Require algo_flow_sparse, return maxFlow, min cut is in minCutEdges
	int maxFlow = getMaxFlow();
	fill(minCutIsVisited.begin(), minCutIsVisited.end(), false);
	minCutIsVisited.resize(nbVertices, false);
	minCutEdges.clear();

	minCutMarkNodes(source);

	for (int iVertex = 0; iVertex < nbVertices; iVertex++) {
		if (minCutIsVisited[iVertex]) {
			for (auto& e : flowEdges[iVertex]) {
				if (!minCutIsVisited[e.to]) {
					minCutEdges.emplace_back(e);
				}
			}
		}
	}
	return maxFlow;
}