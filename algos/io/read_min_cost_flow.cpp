void readMinCostFlow() {
	scanf("%d%d%d%d", &nbVertices, &nbEdges, &source, &puit);
	fill(cap[0], cap[0] + MAX_VERTICES*MAX_VERTICES, 0);
	fill(cost[0], cost[0] + MAX_VERTICES*MAX_VERTICES, 0);
	
	for (int iEdge = 0; iEdge < nbEdges; iEdge++) {
		int vertex1, vertex2, capVertex, costVertex;
		scanf("%d%d%d%d", &vertex1, &vertex2, &capVertex, &costVertex);

		cost[vertex1][vertex2] = costVertex;
		cap[vertex1][vertex2] = capVertex;

		/* If not oriented, add the reverse edges
		cost[vertex2][vertex1] = costVertex;
		cap[vertex2][vertex1] = capVertex; //*/
	}
}

