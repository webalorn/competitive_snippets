const int MAX_ELEMENTS = 10*1000;

int linkedTo[MAX_ELEMENTS];
vector<int> voisins[MAX_ELEMENTS];
int maxMatchSeen[MAX_ELEMENTS];
int maxMatchCur = 1;
int nbVertices, nbEdges;
int nbVerticesSet1, nbVerticesSet2;

bool findMatching(int vertex, bool fromParent) {
	if (maxMatchSeen[vertex] == maxMatchCur) {
		return false;
	}
	maxMatchSeen[vertex] = maxMatchCur;
	if (linkedTo[vertex] == -1 && not fromParent) {
		return true;
	} else if (fromParent) {
		for (auto& vois : voisins[vertex]) {
			if (findMatching(vois, false)) {
				linkedTo[vertex] = vois;
				linkedTo[vois] = vertex;
				return true;
			}
		}
		return false;
	}
	return findMatching(linkedTo[vertex], true);
}

int getMaxMatching() {
	fill(maxMatchSeen, maxMatchSeen+MAX_ELEMENTS, -1);
	fill(linkedTo, linkedTo+MAX_ELEMENTS, -1);
	int maxMatch = 0;
	for (int iVertex = 0; iVertex < nbVertices; iVertex++) {
		if (linkedTo[iVertex] == -1 && findMatching(iVertex, true)) {
			maxMatch++;
		}
		maxMatchCur++;
	}
	return maxMatch;
}

