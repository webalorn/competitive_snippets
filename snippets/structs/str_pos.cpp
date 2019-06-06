#define NB_MOVES 4

struct Pos {
	int lig, col;
};
Pos operator + (const Pos& a, const Pos& b) { return {a.lig + b.lig, a.col + b.col}; }
Pos operator - (const Pos& a, const Pos& b) { return {a.lig - b.lig, a.col - b.col}; }
bool operator == (const Pos& a, const Pos& b) { return a.lig == b.lig && a.col == b.col; }

#if NB_MOVES == 4
array<Pos, 4> moves = {{{0, 1}, {-1, 0}, {0, -1}, {1, 0}}};
//array<char, 4> movesDir = {{'E', 'N', 'W', 'S'}};
array<char, 4> movesDir = {{'E', 'N', 'O', 'S'}};
#elif NB_MOVES == 8
array<Pos, 8> moves = {{{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}}};
#else
array<Pos, 4> moves = {{{-1, 1}, {-1, -1}, {1, -1}, {1, 1}}};
#endif

int getMoveId(Pos mv) { for (int i = 0; i < NB_MOVES; i++) { if (moves[i] == mv) { return i; } }return -1; }

