for (int lig = 0; lig < nbLigs; lig++) {
	for (int col = 0; col < nbCols; col++) {
		int id = getCellId({lig, col});
		if (isPosValid({lig, col})) {
			for (auto& mv : moves) {
				Pos next = Pos{lig, col} + mv;
				if (isPosValid(next)) {
					int id2 = getCellId(next);
					voisins[id].push_back({id2});
				}
			}
		}
	}
}

