void readGraphPondere() {
	cin >> nbNodes >> nbArcs;
	for (int iArc = 0; iArc < nbArcs; iArc++) {
		int node1, node2, size;
		cin >> node1 >> node2 >> size;
		node1 -= IDS_FIRST; node2 -= IDS_FIRST;
		voisins[node1].push_back({node2, size});
		graph_parents[node2].push_back({node1, size});
	}
}


