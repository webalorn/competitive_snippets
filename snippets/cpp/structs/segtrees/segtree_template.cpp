//@include structs/str_segtree.cpp


template<class T=int> struct ${1:TemplateSegTree} : public SegTree<T> {
	$1(int size=0, T defVal=T(), T leafVal=T()):SegTree<T>(size, defVal, leafVal){}

	void initAll() {
		auto& tree = *this;
		for (int i = this->baseSize-1; i > 0; i--) {
			// ...
		}
	}

	void ${2:pointRequest}(int targetPos, int value) {
		auto& tree = *this;
		int node = targetPos + this->baseSize;
		// Set leaf

		while (node > 1) {
			node /= 2;
			// Propagate to parents

		}
	}

	void ${3:intervalRequest}(int targetLeft, int targetRight,
			int curNode=1, int subLeft=0, int subRight=0) {
		auto& tree = *this;
		if (curNode == 1) { subLeft = 0, subRight = this->baseSize;}

		if (targetRight <= subLeft || targetLeft >= subRight) {
			return ;
		} else if (!(targetLeft <= subLeft && subRight <= targetRight)) { 
			int m = (subLeft + subRight) / 2;
			${3}(targetLeft, targetRight, curNode*2, subLeft, m);
			${3}(targetLeft, targetRight, curNode*2+1, m, subRight);
			// Do stuff with results here

			return;
		}
		// Success ! Do your stuff here

		return;
	}
};