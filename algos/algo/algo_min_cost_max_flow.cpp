#define MAX_VERTICES 1000

int cap[MAX_VERTICES][MAX_VERTICES];
int cost[MAX_VERTICES][MAX_VERTICES];
int flowOnEdge[MAX_VERTICES][MAX_VERTICES];

vector<int> vertexVois[MAX_VERTICES];
int flowDijNext[MAX_VERTICES], flowDijDepth[MAX_VERTICES];
int label[MAX_VERTICES];

int nbVertices, nbEdges, source, puit;

inline int edgeCost(const int from, const int to) {
	return flowDijDepth[from] + label[from] - label[to];
}

bool canPushWithDijkstra() {
	for (int iVertex = 0; iVertex < nbVertices; iVertex++) {
		flowDijDepth[iVertex] = INF;
		flowDijNext[iVertex] = -1;
	}
	flowDijDepth[source] = 0;
	flowDijNext[source] = -nbVertices - 1;

	while (true) {
		int vertDepthMin = -1, minDepth = INF;
		for (int iVertex = 0; iVertex < nbVertices; iVertex++) {
			if (flowDijNext[iVertex] < 0 && flowDijDepth[iVertex] < minDepth) {
				vertDepthMin = iVertex;
				minDepth = flowDijDepth[iVertex];
			}
		}
		if (minDepth == INF) {
			break;
		}

		// relax edge (vertDepthMin, iVertex) or (iVertex, vertDepthMin) for all iVertex
		flowDijNext[vertDepthMin] = -flowDijNext[vertDepthMin] - 1;
		for (int iVertex : vertexVois[vertDepthMin]) {
			if (flowDijNext[iVertex] >= 0) {
				continue;
			}
			if (flowOnEdge[iVertex][vertDepthMin] && flowDijDepth[iVertex] > edgeCost(vertDepthMin, iVertex) - cost[iVertex][vertDepthMin]) { 
				flowDijDepth[iVertex] = edgeCost(vertDepthMin, iVertex) - cost[iVertex][vertDepthMin];
				flowDijNext[iVertex] = -vertDepthMin-1;
			}
		
			// try edge vertDepthMin->iVertex
			if (flowOnEdge[vertDepthMin][iVertex] < cap[vertDepthMin][iVertex]
					&& flowDijDepth[iVertex] > edgeCost(vertDepthMin, iVertex) + cost[vertDepthMin][iVertex]) {
				flowDijDepth[iVertex] = edgeCost(vertDepthMin, iVertex) + cost[vertDepthMin][iVertex];
				flowDijNext[iVertex] = -vertDepthMin - 1;
			}
		}
	}

	for (int iVertex = 0; iVertex < nbVertices; iVertex++) {
		if (label[iVertex] < INF) {
			label[iVertex] += flowDijDepth[iVertex];
		}
	}

	return flowDijNext[puit] >= 0;
}

pair<int, int> getMinCostMaxFlow() { // return {min_cost, max_flow}
	fill(flowOnEdge[0], flowOnEdge[0] + MAX_VERTICES*MAX_VERTICES, 0);
	fill(label, label + MAX_VERTICES, 0);

	for (int iVertex = 0; iVertex < nbVertices; iVertex++) {
		for (int iNext = 0; iNext < nbVertices; iNext++) {
			if (cap[iVertex][iNext] || cap[iNext][iVertex]) {
				vertexVois[iVertex].push_back(iNext);
			}
		}
	}
	
	int flow = 0, flowCost = 0;
	
	while (canPushWithDijkstra()) {
		int capMinPath = INF;
		for (int iVertex = puit, iNext = flowDijNext[iVertex]; iVertex != source; iVertex = iNext, iNext = flowDijNext[iVertex]) {
			if (flowOnEdge[iVertex][iNext]) {
				capMinPath = min(capMinPath, flowOnEdge[iVertex][iNext]);
			} else {
				capMinPath = min(capMinPath, cap[iNext][iVertex] - flowOnEdge[iNext][iVertex]);
			}
		}

		// update the flow network
		for (int iVertex = puit, iNext = flowDijNext[iVertex]; iVertex != source; iVertex = iNext, iNext = flowDijNext[iVertex]) {
			if (flowOnEdge[iVertex][iNext]) {
				flowOnEdge[iVertex][iNext] -= capMinPath;
				flowCost -= capMinPath * cost[iVertex][iNext];
			} else {
				flowOnEdge[iNext][iVertex] += capMinPath;
				flowCost += capMinPath * cost[iNext][iVertex];
			}
		}
	
		flow += capMinPath;
	}
  
	return {flowCost, flow};
}

