//@title Array to represent a grid of char and usefull functions
//@defines grid, readGrid, getCellId, idToCell, isPosValid
//@
/* Requires st_pos */

const bool IS_GRID_SQUARE = true;
const int MAX_COTE = 200;

int nbLigs, nbCols;
char grid[MAX_COTE][MAX_COTE];

void readGrid() {
	scanf("%d", &nbLigs);
	if (IS_GRID_SQUARE) {
		nbCols = nbLigs;
	} else {
		scanf("%d", &nbCols);
	}

	for (int lig = 0; lig < nbLigs; lig++) {
		for (int col = 0; col < nbCols; col++) {
			scanf(" %c", &grid[lig][col]);
		}
	}
}
int getCellId(Pos pos) {
	int cell = pos.lig*nbCols + pos.col;
	return cell;
}
Pos idToCell(int id) {
	return {id/nbCols, id%nbCols};
}
int isPosValid(Pos pos) {
	if (pos.lig < 0 || pos.lig >= nbLigs || pos.col < 0 || pos.col >= nbCols) {
		return false;
	}
	if (grid[pos.lig][pos.col] == '#') {
		return false;
	}
	return true;
}

