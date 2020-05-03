vector<string> split(string str, char delim=' ') {
	std::size_t current, previous = 0;
	vector<string> cont;
	current = str.find(delim);
	while (current != std::string::npos) {
		cont.push_back(str.substr(previous, current - previous));
		previous = current + 1;
		current = str.find(delim, previous);
	}
	cont.push_back(str.substr(previous, current - previous));
	return cont;
}

std::string& ltrim(std::string& s) {
	auto it = std::find_if(s.begin(), s.end(),[](char c) {return !std::isspace<char>(c, std::locale::classic());});
	s.erase(s.begin(), it); return s;}
std::string& rtrim(std::string& s) {
	auto it = std::find_if(s.rbegin(), s.rend(),[](char c) {return !std::isspace<char>(c, std::locale::classic());});
	s.erase(it.base(), s.end());return s;}
std::string& trim(std::string s) { return ltrim(rtrim(s)); }