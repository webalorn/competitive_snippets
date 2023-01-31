//@title Union-Find algorithm
//@defines Union Find
//@
struct Uf {
	vector<int> parent;
	vector<int> compoSize;
	Uf(int nbNodes) {parent.resize(nbNodes, -1);compoSize.resize(nbNodes, 1);}

	int Find(int a) { return parent[a] == -1 ? a : (parent[a] = Find(parent[a])); }
	int Union(int a, int b) {
		a = Find(a), b = Find(b);
		if (a != b) {
			if (compoSize[a] < compoSize[b]) {
				swap(a, b);
			}
			parent[b] = a;
			compoSize[a] += compoSize[b];
			return compoSize[a];
		}
		return 0;
	}
};

