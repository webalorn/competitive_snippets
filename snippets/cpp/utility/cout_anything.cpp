template<class T> ostream& operator<<(ostream& os, const vector<T>& v);
template<class T> ostream& operator<<(ostream& os, const deque<T>& v);
template<class T, size_t s> ostream& operator<<(ostream& os, const array<T, s>& v);
template<class T> ostream& operator<<(ostream& os, const set<T>& v);
template<class A, class B> ostream& operator<<(ostream& os, const map<A, B>& v);
template<class T> ostream& operator<<(ostream& os, const unordered_set<T>& v);
template<class A, class B> ostream& operator<<(ostream& os, const unordered_map<A, B>& v);
template<class A, class B> ostream& operator<<(ostream& os, const pair<A, B>& el);

template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "[ "; for (auto& el : v) { os << el << ", "; } os << "]"; return os; }
template<class T> ostream& operator<<(ostream& os, const deque<T>& v) { os << "[ "; for (auto& el : v) { os << el << ", "; } os << "]"; return os; }
template<class T, size_t s> ostream& operator<<(ostream& os, const array<T, s>& v) { os << "[ "; for (auto& el : v) { os << el << ", "; } os << "]"; return os; }
template<class T> ostream& operator<<(ostream& os, const set<T>& v) { os << "( "; for (auto& el : v) { os << el << ", "; } os << ")"; return os; }
template<class A, class B> ostream& operator<<(ostream& os, const map<A, B>& v) { os << "{ "; for (auto& el : v) { os << el.first << ": " << el.second << ", "; } os << "}"; return os; }
template<class T> ostream& operator<<(ostream& os, const unordered_set<T>& v) { os << "( "; for (auto& el : v) { os << el << ", "; } os << ")"; return os; }
template<class A, class B> ostream& operator<<(ostream& os, const unordered_map<A, B>& v) { os << "{ "; for (auto& el : v) { os << el.first << ": " << el.second << ", "; } os << "}"; return os; }
template<class A, class B> ostream& operator<<(ostream& os, const pair<A, B>& el) { os << "(" << el.first << ", " << el.second << ")"; return os; }

$0