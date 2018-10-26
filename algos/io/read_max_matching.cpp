void readMaxMatching() { // Default: biparty graph
	scanf("%d%d%d", &nbVerticesSet1, &nbVerticesSet2, &nbEdges);
	nbVertices = nbVerticesSet1 + nbVerticesSet2;

	for (int iEdge = 0; iEdge < nbEdges; iEdge++) {
		int iVertex1, iVertex2;
		scanf("%d%d", &iVertex1, &iVertex2);
		iVertex2 += nbVerticesSet1; // Re-index

		voisins[iVertex1].push_back(iVertex2);
		voisins[iVertex2].push_back(iVertex1);
	}
}

