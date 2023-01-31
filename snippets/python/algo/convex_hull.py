def half_convex_hull(points, already_sorted=False):
	if not already_sorted:
		points.sort()
	hull = []
	for pt in points:
		while len(hull) >= 2:
			a, b = hull[-2], hull[-1]
			det = ((b[0]-a[0]) * (pt[1] - a[1]) - (pt[0] - a[0]) * (b[1]-a[1]))
			if det < 0:
				break
			hull.pop()
		hull.append(pt)
	return hull

def convex_hull(points):
	points.sort()
	points1, points2 = [points[0]], [(points[0][0], -points[0][1])]

	for pt in points:
		side = (points[-1][0]-points[0][0]) * (pt[1]-points[0][1]) - (pt[0]-points[0][0]) * (points[-1][1]-points[0][1])
		if side > 0:
			points1.append(pt)
		elif side < 0:
			points2.append((pt[0], -pt[1]))
	points1.append(points[-1])
	points2.append((points[-1][0], -points[-1][1]))

	hull1 = half_convex_hull(points1, True)
	hull2 = half_convex_hull(points2, True)

	for pt in hull2[-2:0:-1]:
		hull1.append((pt[0], -pt[1]))
	return hull1

def hull_perimeter(hull):
	if not hull: return 0
	norm = 0
	for i in range(len(hull)):
		norm += ((hull[i][0]-hull[i-1][0])**2+(hull[i][1]-hull[i-1][1])**2)**0.5
	return norm

