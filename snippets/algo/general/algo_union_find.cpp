//@title Union-Find algorithm
//@defines Union Find
//@
const int UF_MAX_NODES = 100*1000;
int uf_parent[UF_MAX_NODES];
int uf_size[UF_MAX_NODES];

struct UF_INIT {
	UF_INIT() {
		fill(uf_parent, uf_parent+UF_MAX_NODES, -1);
		fill(uf_size, uf_size+UF_MAX_NODES, 1);
	}
} test;

int Find(int a) {
	return uf_parent[a] == -1 ? a : (uf_parent[a] = Find(uf_parent[a]));
}
int Union(int a, int b) {
	a = Find(a), b = Find(b);
	if (a != b) {
		if (uf_size[a] < uf_size[b]) {
			swap(a, b);
		}
		uf_parent[b] = a;
		uf_size[a] += uf_size[b];
		return uf_size[a];
	}
	return 0;
}

