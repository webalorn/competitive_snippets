//@include structs/str_segtree.cpp


template<class T> struct SumSegTree : public SegTree<T> {
	SumSegTree(int size=0, T defVal=0, T leafVal=0):SegTree<T>(size, defVal, leafVal){}

	void initAll() {
		auto& tree = *this;
		for (int i = this->baseSize-1; i > 0; i--) {
			tree[i] = tree[i*2] + tree[i*2+1];
		}
	}

	void setPoint(int targetPos, int value,
		int curNode = 1, int subLeft = 0, int subRight = 0) {
		auto& tree = *this;
		if (curNode == 1) { subLeft = 0, subRight = this->baseSize;}

		if (curNode >= this->baseSize) {
			tree[curNode] = value;
		} else {
			int m = (subLeft + subRight) / 2;
			if (targetPos < m) {
				setPoint(targetPos, value, curNode*2, subLeft, m);
			} else {
				setPoint(targetPos, value, curNode*2+1, m, subRight);
			}
			tree[curNode] = tree[curNode*2] + tree[curNode*2+1];
		}
	}

	T sumInter(int targetLeft, int targetRight,
			int curNode=1, int subLeft=0, int subRight=0) {
		auto& tree = *this;
		if (curNode == 1) { subLeft = 0, subRight = this->baseSize;}

		if (targetRight <= subLeft || targetLeft >= subRight) {
			return 0;
		} else if (!(targetLeft <= subLeft && subRight <= targetRight)) {
			int m = (subLeft + subRight) / 2;
			T a = sumInter(targetLeft, targetRight, curNode*2, subLeft, m);
			T b = sumInter(targetLeft, targetRight, curNode*2+1, m, subRight);

			return a+ b;
		}
		return tree[curNode];
	}
};