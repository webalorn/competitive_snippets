/* Min cost Max Flow algorithm using Dijkstra on a graph represented with an adjacency list */
struct Edge { int from, to, cap, flow, reversedId; };

int nbVertices=0, nbEdges, source, puit; // Init with values
int maxEdgeCapInGraph = 0;
vector<vector<Edge>> flowEdges;
vector<int> lastDfs;

void addVertex(int from, int to, int cap) {
	flowEdges.resize(max((int)flowEdges.size(), max(from+1, to+1)));
	flowEdges[from].emplace_back(Edge{from, to, cap, 0, (int)flowEdges[to].size()});
	flowEdges[to].emplace_back(Edge{to, from, 0, 0, (int)flowEdges[from].size()-1});
	maxEdgeCapInGraph = max(maxEdgeCapInGraph, cap);
}

int maxFlowCanPush(int pos, int minCap, int minOnPath, int dfsId) {
	if (pos == puit) return minOnPath;
	if (lastDfs[pos] == dfsId) return 0;
	lastDfs[pos] = dfsId;
	for (Edge& e : flowEdges[pos]) {
		if (e.cap - e.flow >= minCap) {
			int flow = maxFlowCanPush(e.to, minCap, min(minOnPath, e.cap-e.flow), dfsId);
			if (flow) {
				e.flow += flow;
				flowEdges[e.to][e.reversedId].flow -= flow;
				return flow;
			}
		}
	}
	return 0;
}

int getMaxFlow() { // return {minCost, maxFlow}
	nbVertices = max(nbVertices, (int)flowEdges.size());
	flowEdges.resize(nbVertices); lastDfs.resize(nbVertices, -1);

	int dfsId = 0, maxFlow = 0, pushFlow = 1;
	while (pushFlow * 2 <= maxEdgeCapInGraph) { pushFlow *= 2; }

	while (pushFlow) {
		int pushed = maxFlowCanPush(source, pushFlow, INF, dfsId++);
		if (pushed) maxFlow += pushed;
		else pushFlow /= 2;
	}
	return maxFlow;
}

// void readMaxFlow() {
// 	cin >> nbVertices >> nbEdges >> source >> puit;

// 	for (int iEdge = 0; iEdge < nbEdges; iEdge++) {
// 		int vertex1, vertex2, capVertex;
// 		cin >> vertex1 >> vertex2 >> capVertex;

// 		addVertex(vertex1, vertex2, capVertex);
// 	}
// }