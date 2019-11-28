//@title Array to represent a grid of char and usefull functions
//@defines grid, readGrid, getCellId, idToCell, isPosValid
//@
/* Requires st_pos */

const bool IS_GRID_SQUARE = true;
const int MAX_COTE = 200;

int haut, larg;
char grid[MAX_COTE][MAX_COTE];

void readGrid() {
	scanf("%d", &haut);
	if (IS_GRID_SQUARE) {
		larg = haut;
	} else {
		scanf("%d", &larg);
	}

	for (int lig = 0; lig < haut; lig++) {
		for (int col = 0; col < larg; col++) {
			scanf(" %c", &grid[lig][col]);
		}
	}
}
int getCellId(Pos pos) {
	int cell = pos.lig*larg + pos.col;
	return cell;
}
Pos idToCell(int id) {
	return {id/larg, id%larg};
}
int isPosValid(Pos pos) {
	if (pos.lig < 0 || pos.lig >= haut || pos.col < 0 || pos.col >= larg) {
		return false;
	}
	if (grid[pos.lig][pos.col] == '#') {
		return false;
	}
	return true;
}

