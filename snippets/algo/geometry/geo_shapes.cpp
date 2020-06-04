// Geometric shapes functions. Requires geo_base + geo_segs

vector<Seg> borderToSegs(const vector<Vect>& border) {
	vector<Seg> v;
	if (border.size() >= 2) {
		v.emplace_back(Seg{border.back(), border[0]});
	}
	for (int i = 0; i < (int)border.size()-1; i++) {
		v.emplace_back(Seg{border[i], border[i+1]});
	}
	return v;
}

vector<bool> arePointsInArea(const vector<Vect>& border, const vector<Vect>& points) {
	auto segs = borderToSegs(border);
	vector<bool> ans;
	ans.reserve(border.size());
	for (auto& pt : points) {
		Seg s = {pt, Vect{pt.x+1, INF}};
		bool inArea = false;
		for (auto& seg : segs) {
			if (seg.isOnSeg(pt)) {
				inArea = true;
				break;
			} else if (isThereIntersection(seg, s)) {
				inArea = !inArea;
			}
		}
		ans.push_back(inArea);
	}
	return ans;
}

bool isPointInArea(const vector<Vect>& border, Vect point) { return arePointsInArea(border, {point})[0]; }

$0