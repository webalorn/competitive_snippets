vector<string> split(string str, char delim=' ') {
	size_t current, previous = 0;
	vector<string> cont;
	current = str.find(delim);
	while (current != string::npos) {
		cont.push_back(str.substr(previous, current - previous));
		previous = current + 1;
		current = str.find(delim, previous);
	}
	cont.push_back(str.substr(previous, current - previous));
	return cont;
}

string& ltrim(string& s) {
	auto it = find_if(s.begin(), s.end(),[](char c) {return !isspace<char>(c, locale::classic());});
	s.erase(s.begin(), it); return s;}
string& rtrim(string& s) {
	auto it = find_if(s.rbegin(), s.rend(),[](char c) {return !isspace<char>(c, locale::classic());});
	s.erase(it.base(), s.end());return s;}
string& trim(string s) { return ltrim(rtrim(s)); }