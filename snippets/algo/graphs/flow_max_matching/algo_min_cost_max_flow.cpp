/* Min cost Max Flow algorithm using Dijkstra. Weights must be positive */
#define MAX_VERTICES 300

int nbVertices, nbEdges, source, puit; // Init with values

int cap[MAX_VERTICES][MAX_VERTICES]; // Init at 0 or cap
int cost[MAX_VERTICES][MAX_VERTICES]; // Init at cost
int flowOnEdge[MAX_VERTICES][MAX_VERTICES]; // Set by the algorithm

// Used internally by the algorithm
vector<int> vertexVois[MAX_VERTICES]; // Improve performances if the graph is sparse
int potential[MAX_VERTICES], distMin[MAX_VERTICES], dijPrev[MAX_VERTICES];

struct FlowSit { int pos, time; };
bool operator < (const FlowSit& a, const FlowSit& b) {
	return a.time > b.time;
}

inline const pair<int, int> getEdgeCapCost(const int a, const int b) {
	if (flowOnEdge[b][a] > 0) {
		return {flowOnEdge[b][a], - cost[b][a] + potential[a] - potential[b]};
	}
	return {cap[a][b] - flowOnEdge[a][b], cost[a][b] + potential[a] - potential[b]};
}
inline int updateAndCost(const int a, const int b, const int delta) {
	if (flowOnEdge[b][a] > 0) {
		flowOnEdge[b][a] -= delta;
		return - delta * cost[b][a];
	}
	flowOnEdge[a][b] += delta;
	return delta * cost[a][b];
}

bool canPushDijPath() {
	fill(distMin, distMin+MAX_VERTICES, INF);
	distMin[source] = 0;

	priority_queue<FlowSit> sits;
	sits.push({source, 0});
	while (!sits.empty()) { // Dijkstra
		int pos = sits.top().pos, time = sits.top().time;
		sits.pop();
		if (time == distMin[pos]) {
			for (int v : vertexVois[pos]) {
				auto capCost = getEdgeCapCost(pos, v);
				if (capCost.first) {
					int t2 = time + capCost.second;
					if (t2 < distMin[v]) {
						dijPrev[v] = pos;
						distMin[v] = t2;
						sits.push({v, t2});
					}
				}
			}
		}
	}
	return distMin[puit] != INF;
}

pair<int, int> getMinCostMaxFlow() { // return {minCost, maxFlow}
	fill(flowOnEdge[0], flowOnEdge[0]+MAX_VERTICES*MAX_VERTICES, 0);
	for (int iVertex = 0; iVertex < nbVertices; iVertex++) {
		for (int iVois = 0; iVois < nbVertices; iVois++) {
			if (cap[iVertex][iVois] != 0 || cap[iVois][iVertex] != 0) {
				vertexVois[iVertex].emplace_back(iVois);
			}
		}
	}
	int minCost = 0, maxFlow = 0;
	while (canPushDijPath()) {
		for (int iVertex = 0; iVertex < nbVertices; iVertex++) {
			potential[iVertex] += distMin[iVertex];
		}
		int delta = INF;
		for (int iVertex = puit; iVertex != source; iVertex = dijPrev[iVertex]) {
			auto capCost = getEdgeCapCost(dijPrev[iVertex], iVertex);
			delta = min(delta, capCost.first);
		}
		for (int iVertex = puit; iVertex != source; iVertex = dijPrev[iVertex]) {
			minCost += updateAndCost(dijPrev[iVertex], iVertex, delta);
		}
		maxFlow += delta;
	}
	return {minCost, maxFlow};
}