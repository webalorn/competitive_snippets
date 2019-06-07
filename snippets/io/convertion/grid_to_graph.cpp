for (int lig = 0; lig < haut; lig++) {
	for (int col = 0; col < larg; col++) {
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

