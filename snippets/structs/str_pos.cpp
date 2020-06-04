//@title Functions for manipulating 2D integer positions
//@defines Pos, NB_MOVES, moves, movesDir, getMoveId, isPosValid
//@
#define NB_MOVES 4

struct Pos {
	int lig, col;
};
Pos operator + (const Pos& a, const Pos& b) { return {a.lig + b.lig, a.col + b.col}; }
Pos operator - (const Pos& a, const Pos& b) { return {a.lig - b.lig, a.col - b.col}; }
bool operator == (const Pos& a, const Pos& b) { return a.lig == b.lig && a.col == b.col; }
bool operator < (const Pos& a, const Pos& b) { return a.lig == b.lig ? a.col < b.col : a.lig < b.lig; }

array<Pos, 4> movesAdj = {{{0, 1}, {-1, 0}, {0, -1}, {1, 0}}};
array<char, 4> movesDirAdj = {{'E', 'N', 'W', 'S'}};
array<Pos, 4> movesDiag = {{{-1, 1}, {-1, -1}, {1, -1}, {1, 1}}};
array<Pos, 8> movesAdjDiags = {{{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}}};


#if NB_MOVES == 4
auto moves = movesAdj; auto movesDir = movesAdj;
#elif NB_MOVES == 8
auto moves = movesDiag;
#else
auto moves = movesAdjDiags;
#endif

int getMoveId(Pos mv) { for (int i = 0; i < NB_MOVES; i++) { if (moves[i] == mv) { return i; } }return -1; }
int isPosValid(Pos pos, int afterMaxLig, int afterMaxCol, int minLig=0, int minCol = 0) {
	return pos.lig >= minLig && pos.lig < afterMaxLig && pos.col >= minCol && pos.col < afterMaxCol;
}

$0