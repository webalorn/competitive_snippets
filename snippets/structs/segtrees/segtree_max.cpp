//@include structs/str_segtree.cpp


template<class T=int> struct MaxSegTree : public SegTree<T> {
	const static T infty = INF;
	MaxSegTree(int size=0, T defVal=-infty, T leafVal=-infty):SegTree<T>(size, defVal, leafVal){}

	void initAll() {
		for (int i = this->baseSize-1; i > 0; i--) {
			this->tree[i] = max(this->tree[i*2], this->tree[i*2+1]);
		}
	}

	void setPointVal(int targetPos, int value, 
		int curNode = 1, int subLeft = 0, int subRight = 0) {
		if (curNode == 1) { subLeft = 0, subRight = this->baseSize;}

		if (curNode >= this->baseSize || false) { // If the request must stop here
			// Do your stuff here
			this->tree[curNode] = value;
		} else {
			int m = (subLeft + subRight) / 2;
			if (targetPos < m) {
				setPointVal(targetPos, value, curNode*2, subLeft, m);
			} else {
				setPointVal(targetPos, value, curNode*2+1, m, subRight);
			}
			this->tree[curNode] = max(this->tree[curNode*2], this->tree[curNode*2+1]);
		}
	}

	T getMax(int targetLeft, int targetRight,
			int curNode=1, int subLeft=0, int subRight=0) {
		if (curNode == 1) { subLeft = 0, subRight = this->baseSize;}

		if (targetRight <= subLeft || targetLeft >= subRight) {
			return -infty;
		} else if (!(targetLeft <= subLeft && subRight <= targetRight)) { 
			int m = (subLeft + subRight) / 2;
			T r1 = getMax(targetLeft, targetRight, curNode*2, subLeft, m);
			T r2 = getMax(targetLeft, targetRight, curNode*2+1, m, subRight);
			// Do stuff with results here

			return max(r1, r2);
		}
		// Success ! Do your stuff here
		return this->tree[curNode];
	}
};