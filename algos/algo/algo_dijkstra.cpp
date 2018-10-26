int dij_t_min[MAX_NODES];

struct Dij_sit {
	int pos, time;
};
bool operator < (const Dij_sit& a, const Dij_sit& b) {
	return a.time == b.time ? a.pos > b.pos : a.time > b.time;
}

void dijkstra(vector<int> sources) {
	priority_queue<Dij_sit> sits;
	fill(dij_t_min, dij_t_min+nbNodes, -1);

	for (int p : sources) {
		sits.push({p, 0});
		dij_t_min[p] = 0;
	}
	while (!sits.empty()) {
		Dij_sit s = sits.top();
		sits.pop();
		if (s.time == dij_t_min[s.pos]) {
			// Parcoure noeud s.pos a s.time
			for (auto& arc : voisins[s.pos]) {
				if (dij_t_min[arc.dest] == -1 || dij_t_min[arc.dest] > arc.size + s.time) {
					dij_t_min[arc.dest] = arc.size + s.time;
					sits.push({arc.dest, dij_t_min[arc.dest]});
				}
			}
		}
	}
}


