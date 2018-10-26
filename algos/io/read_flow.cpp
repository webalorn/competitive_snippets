void readFlow() {
	scanf("%d%d", &nbNodes, &nbArcs);
	for (int iArc = 0; iArc < nbArcs; iArc++) {
		int deb, fin, capArc;
		scanf("%d%d%d", &deb, &fin, &capArc);
		cap[deb][fin] += capArc;
		if (!IS_FLOW_ORIENTED) {
			cap[deb][fin] += capArc;
		}
	}
}

