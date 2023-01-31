// Minimum convex hull. Requires geo_base

vector<Vect> halfMinimumCvx(vector<Vect>& points, bool alreadySorted=false) {
	vector<Vect> hull;
	if (!alreadySorted) {
		sort(points.begin(), points.end()); // Sort by x
	}
	for (Vect& pt : points) {
		while (hull.size() >= 2) {
			const Vect& a = hull[hull.size()-2], b = hull.back();
			if (det(b-a, pt-a) < 0) { // '<=' may bause bugs
				break;
			}
			hull.pop_back();
		}
		hull.emplace_back(pt);
	}
	return hull;
}

vector<Vect> minConvexHull(vector<Vect> points) {
	sort(points.begin(), points.end());
	vector<Vect> points1, points2;
	points1.emplace_back(points[0]);
	points2.emplace_back(Vect{points[0].x, -points[0].y});

	for (auto& pt : points) {
		vint side = det(points.back()-points[0], pt-points[0]);
		if (side > 0) points1.emplace_back(pt);
		else if (side < 0) points2.emplace_back(Vect{pt.x, -pt.y});
	}
	points1.emplace_back(points.back());
	points2.emplace_back(Vect{points.back().x, -points.back().y});

	vector<Vect> hull1 = halfMinimumCvx(points1, true);
	vector<Vect> hull2 = halfMinimumCvx(points2, true);

	for (int i = (int)hull2.size()-2; i > 0; i--) {
		hull1.emplace_back(Vect{hull2[i].x, -hull2[i].y});
	}
	return hull1;
}

vfloat hullPerimeter(const vector<Vect>& hull) {
	if (hull.empty()) { return 0; }
	vfloat per = (hull.back()-hull[0]).norm();
	for (int i = 0; i < (int)hull.size()-1; i++) {
		per += (hull[i+1]-hull[i]).norm();
	}
	return per;
}