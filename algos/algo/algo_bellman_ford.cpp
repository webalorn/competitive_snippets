#define BF_COMP min

vector<int> bf_times_save;
vector<int> bf_times;

void __apply_bf() {
	for (int turn = 0; turn < nbNodes; turn++) {
		for (int iNode = 0; iNode < nbNodes; iNode++) {
			if (bf_times[iNode] != INF) {
				for (auto& arc : voisins[iNode]) {
					bf_times[arc.dest] = BF_COMP(bf_times[arc.dest], bf_times[iNode] + arc.size);
				}
			}
		}
	}
}

bool bellman_ford(vector<int> sources) {
	bf_times.resize(nbNodes, sources.empty() ? 0 : INF);
	for (auto& el : sources) {
		bf_times[el] = 0;
	}
	__apply_bf();
	bf_times_save = bf_times;
	__apply_bf();

	if (bf_times_save != bf_times) {
		return true;
	}
	return false;
}


