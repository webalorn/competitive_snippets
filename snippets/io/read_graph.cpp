void readGraph() {
	cin >> nbNodes >> nbArcs;
	for (int iArc = 0; iArc < nbArcs; iArc++) {
		int node1, node2;
		cin >> node1 >> node2;
		node1 -= IDS_FIRST; node2 -= IDS_FIRST;
		voisins[node1].push_back({node2});
		graph_parents[node2].push_back({node1});
	}
}


