template<class T> struct Reindexer {
	vector<T> vals;
	void add(T v){vals.push_back(v);}
	void add(vector<T> vs){for (auto v : vs){vals.push_back(v);}}
	void sort() {
		std::sort(vals.begin(), vals.end());
		vector<T> vals2;
		for (auto& el : vals) {
			if (vals2.empty() || vals2.back() != el) {
				vals2.push_back(el);
			}
		}
		vals = vals2;
	}
	int get(T v) {
		int a = 0, b = vals.size();
		while (a < b-1) {
			int m = (a+b)/2;
			if (vals[m] == v) {
				return m;
			} else if (vals[m] < v) {
				a = m+1;
			} else {
				b = m;
			}
		}
		return a;
	}
	int size() {
		return vals.size();
	}
};