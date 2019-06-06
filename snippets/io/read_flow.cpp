void readFlow() {
	cin >> nbNodes >> nbArcs;
	for (int iArc = 0; iArc < nbArcs; iArc++) {
		int deb, fin, capArc;
		cin >> dev >> fin >> capArc;
		cap[deb][fin] += capArc;
		if (!IS_FLOW_ORIENTED) {
			cap[deb][fin] += capArc;
		}
	}
}

