// WIP

template<class T> struct CartTree { // Not persistant
	T val;
	int weight; // min weight on top
	CartTree* left;
	CartTree* right;
	int _size;
	bool reverse;
	
	CartTree(T value) : val(value), left(nullptr), right(nullptr), _size(1), reverse(false) { weight = rand(); }
	pair<CartTree*, CartTree*> split(T splitVal, bool includeVal=false) {
		// tree1 < splitVal <= tree2 if includeVal=false, tree1 <= splitVal < tree2 otherwise
		this->propagNode();
		if (val < splitVal || (includeVal && !(splitVal < val))) {
			CartTree* right2 = nullptr;
			if (right != nullptr) {
				auto p = right->split(splitVal, includeVal);
				right = p.first;
				right2 = p.second;
			}
			this->updateNode();
			return {this, right2};
		}
		CartTree* left1 = nullptr;
		if (left != nullptr) {
			auto p = left->split(splitVal, includeVal);
			left1 = p.first;
			left = p.second;
		}
		this->updateNode();
		return {left1, this};
	}
	~CartTree() { delete left; delete right; }
	inline int size() const {return this->_size;}

	static CartTree* merge(CartTree* a, CartTree* b) {
		if (a == nullptr) { return b; } if (b == nullptr) { return a; }
		if (a->weight < b->weight) {
			a->propagNode();
			a->right = CartTree::merge(a->right, b);
			a->updateNode();
			return a;
		}
		b->propagNode();
		b->left = CartTree::merge(a, b->left);
		b->updateNode();
		return b;
	}
	CartTree* mergeLeft(CartTree* a) {return CartTree::merge(a, this); }
	CartTree* mergeRight(CartTree* b) {return CartTree::merge(this, b); }

	void propagNode() {
		if (reverse) {
			reverse=false;
			if (left!=nullptr) { left->reverse = !left->reverse; }
			if (right!=nullptr) { right->reverse = !right->reverse; }
		}
	}
	void updateNode() {
		// Overwrides must start with CartTree::updateNode();
		this->_size = 1 + (left==nullptr?0:left->_size) + (right==nullptr?0:right->_size);
		this->propagNode();
	}

	inline static int empty(CartTree* a) {return a!=nullptr;}
	inline static int size(CartTree* a) {return a==nullptr?0:a->size();}

	CartTree* insert(CartTree* node) {
		auto p = this->split(node->val);
		return node->mergeLeft(p.first)->mergeRight(p.second);
	}
	CartTree* insert(T value) { return this->insert(new CartTree(value)); }
	static CartTree* insert(CartTree* tree, T value) {return tree==nullptr?new CartTree(value):tree->insert(value);}
	CartTree* remove(T value) { // Remove all nodes with this value
		auto p1 = this->split(value);
		auto p2 = p1.second->split(value);
		delete p2.first;
		return p1.first->mergeRight(p2.second);
	}

	T& getNthValue(int n) {
		int leftSize = CartTree::size(left);
		if (leftSize > n) {
			return left->getNthValue(n);
		} else if (leftSize == n) {
			return val;
		}
		if (right == nullptr) {
			cerr << "Error CartTree getNthValue\n";
		}
		return right->getNthValue(n-leftSize-1);
	}
};// Usage : CartTree<int>* t = nullptr; and then build
// using Tree = CartTree<int>; // Tree* t = nullptr;
template<class T> ostream& operator<<(ostream& os, const CartTree<T>* t) {
	if (t != nullptr) {
		os << "[" << t->left << "] - ";
		os << "(" << t->val << " ; size=" << t->_size << ")";
		os << " - [" << t->right << "]";
	} return os;
}