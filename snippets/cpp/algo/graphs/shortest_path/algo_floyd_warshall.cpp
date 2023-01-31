//#define GRAPH_ORIENTED

const int MAX_NODES = 500;
const int IDS_FIRST = 1;

int nbNodes, nbArcs;
int fw_dists[MAX_NODES][MAX_NODES];

void floyd_warshall_init() {
	for (int iNode = 0; iNode < nbNodes; iNode++) {
		fill(fw_dists[iNode], fw_dists[iNode]+nbNodes, 1000*1000*1000);
		fw_dists[iNode][iNode] = 0;
	}
}

void floyd_warshall() {
	for (int pivot = 0; pivot < nbNodes; pivot++) {
		for (int dest = 0; dest < nbNodes; dest++) {
			for (int source = 0; source < nbNodes; source++) {
				fw_dists[source][dest] = min(fw_dists[source][dest], fw_dists[source][pivot] + fw_dists[pivot][dest]);
			}
		}
	}
}

void read_graph_floyd_warshall() {
	scanf("%d%d", &nbNodes, &nbArcs);
	floyd_warshall_init();
	for (int iArc = 0; iArc < nbArcs; iArc++) {
		int node1, node2, size;
		scanf("%d%d%d", &node1, &node2, &size);
		node1 -= IDS_FIRST; node2 -= IDS_FIRST;
		fw_dists[node1][node2] = size;
		#ifndef GRAPH_ORIENTED
		fw_dists[node2][node1] = size;
		#endif
	}
}


