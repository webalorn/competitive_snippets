/* Min cost Max Flow algorithm using Dijkstra on a graph represented with an adjacency list */
struct Edge { int from, to, cap, cost, flow, reversedId; };

int nbVertices=0, nbEdges, source, puit; // Init with values
vector<vector<Edge>> flowEdges;

void addVertex(int from, int to, int cap, int cost) {
	flowEdges.resize(max((int)flowEdges.size(), max(from+1, to+1)));
	flowEdges[from].emplace_back(Edge{from, to, cap, cost, 0, (int)flowEdges[to].size()});
	flowEdges[to].emplace_back(Edge{to, from, 0, -cost, 0, (int)flowEdges[from].size()-1});
}

// Used internally by the algorithm
vector<int> potential, distMin;
vector<Edge*> dijPrev;

struct FlowSit { int pos, time; };
bool operator < (const FlowSit& a, const FlowSit& b) {
	return a.time > b.time;
}

bool canPushDijPath() {
	fill(distMin.begin(), distMin.end(), INF);
	distMin[source] = 0;

	priority_queue<FlowSit> sits;
	sits.push({source, 0});
	while (!sits.empty()) { // Dijkstra
		int pos = sits.top().pos, time = sits.top().time;
		sits.pop();
		if (time == distMin[pos]) {
			for (int iEdge = 0; iEdge < (int)flowEdges[pos].size(); iEdge++) {
				Edge& e = flowEdges[pos][iEdge];
				if (e.cap - e.flow) {
					int t2 = time + e.cost + potential[e.from] - potential[e.to];
					if (t2 < distMin[e.to]) {
						dijPrev[e.to] = &flowEdges[pos][iEdge];
						distMin[e.to] = t2;
						sits.push({e.to, t2});
					}
				}
			}
		}
	}
	return distMin[puit] != INF;
}

pair<int, int> getMinCostMaxFlow() { // return {minCost, maxFlow}
	nbVertices = max(nbVertices, (int)flowEdges.size());
	potential.resize(nbVertices, 0); distMin.resize(nbVertices);
	flowEdges.resize(nbVertices); dijPrev.resize(nbVertices, nullptr);

	int minCost = 0, maxFlow = 0;
	while (canPushDijPath()) {
		for (int iVertex = 0; iVertex < nbVertices; iVertex++) {
			potential[iVertex] += distMin[iVertex];
		}
		int delta = INF;
		for (int iVertex = puit; iVertex != source; iVertex = dijPrev[iVertex]->from) {
			delta = min(delta, dijPrev[iVertex]->cap - dijPrev[iVertex]->flow);
		}
		for (int iVertex = puit; iVertex != source; iVertex = dijPrev[iVertex]->from) {
			dijPrev[iVertex]->flow += delta;
			flowEdges[iVertex][dijPrev[iVertex]->reversedId].flow -= delta;
			minCost += delta * dijPrev[iVertex]->cost;
		}
		maxFlow += delta;
	}
	return {minCost, maxFlow};
}

// void readMinCostFlow() {
// 	cin >> nbVertices >> nbEdges >> source >> puit;

// 	for (int iEdge = 0; iEdge < nbEdges; iEdge++) {
// 		int vertex1, vertex2, capVertex, costVertex;
// 		cin >> vertex1 >> vertex2 >> capVertex >> costVertex;

// 		addVertex(vertex1, vertex2, capVertex, costVertex);
// 	}
// }