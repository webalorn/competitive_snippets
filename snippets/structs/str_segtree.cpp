template<class T=int> struct SegTree {
	int haut, baseSize, realSize;
	vector<T> tree;
	SegTree(int size=0, T defVal=T(), T leafVal=T()){setSize(size, defVal, leafVal);}

	void setSize(int t, T defVal=T(), T leafVal=T()) {
		haut = 0, baseSize = 1;
		realSize = t;
		while (baseSize < t) {
			haut += 1;
			baseSize *= 2;
		}
		tree.resize(baseSize*2, defVal);
		fill(tree.begin()+baseSize, tree.end(), leafVal);
	}

	T& operator[](int i) { return tree[i]; }
	T getTab(int i) { return tree[i+baseSize]; }
	void setTab(int i, T val) { tree[i+baseSize] = val; }
	void setTab(vector<T> vals) { for (int i = 0; i < (int)vals.size(); i++) { tree[i+baseSize] = vals[i]; } }

	const inline int borneLeft(const int n) {
		int k = (31-__builtin_clz(n));
		return (1 << (haut-k))*(n-(1<<k));
	}
	const inline int borneRight(const int n) {
		int k = (31-__builtin_clz(n));
		return (1 << (haut-k))*(n-(1<<k)+1);
	}
};

$0