for (int lig = 0; lig < haut; lig++) {
	for (int col = 0; col < larg; col++) {
		int id = getCellId({lig, col})*2+2;
		if (grid[lig][col] == 'c') {
			cap[0][id] = INF;
		}
		if (grid[lig][col] == 'p') {
			cap[id+1][1] = INF;
		}
		cap[id][id+1] = INF;
		if (grid[lig][col] == '?') {
			cap[id][id+1] = 1;
		}
		if (isPosValid({lig, col})) {
			for (auto& mv : moves) {
				Pos next = Pos{lig, col} + mv;
				if (isPosValid(next)) {
					int id2 = getCellId(next)*2+2;
					cap[id+1][id2] = INF;
				}
			}
		}
	}
}

