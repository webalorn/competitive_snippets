moves = [(0, 1), (-1, 0), (0, -1), (1, 0)]
moves_char = ['E', 'N', 'O', 'S']
moves_diag = [(-1, 1), (-1, -1), (1, -1), (1, 1)]
moves_all = moves + moves_diag

def is_pos_valid(x, y, max_x, max_y=None):
	if max_y is None: max_y = max_x
	# return 0 < x <= max_x and 0 < y <= max_y # <Uncomment if intervals are [1;n], not [0;n-1]>
	return 0 <= x < max_x and 0 <= y < max_y

def add_vect(a, b): return [x+y for x, y in zip(a, b)]
def sub_vect(a, b): return [x-y for x, y in zip(a, b)]
def minus_vect(a): return [-x for x in a]

def dist_l2(a, b): return sum([(x-y)**2 for x, y in zip(a, b)])**0.5
def dist_squared(a, b): return sum([(x-y)**2 for x, y in zip(a, b)])
def norm_l2(a): return sum([x**2 for x in a])**0.5
def norm_l2_squared(a): return sum([x**2 for x in a])

def vect_mul(vect, c): return [x*c for x in vect] # Product of vector by a scalar
def scalar_prod(v1, v2): return [x*y for x, y in zip(v1, v2)] # Scalar product of two vectors
def vect_det(v1, v2): return v1[0] * v2[1] - v2[0] * v1[1] # = oriented area, for two 2d vectors

# Basic geometric functions
def dist_line_oriented(point, line_pt1, line_pt2): # oriented distance
	return vect_det(sub_vect(line_pt2, line_pt1), sub_vect(point, line_pt1))/norm_l2(sub_vect(line_pt2, line_pt1))
def proj_on_line_dist_oriented(point, line_pt1, line_pt2): # oriented distance
	return scalar_prod(sub_vect(line_pt2-line_pt1),sub_vect(point,line_pt1))/norm_l2(sub_vect(line_pt2, line_pt1))
def angle_between(v1, v2): return atan2(vect_det(v1, v2), scalar_prod(v1, v2))
def angle_between_3(center, v1, v2): return angle_between(sub_vect(v1, center), sub_vect(v2, center))
def rad2deg(x): return 180 * x / pi;
def deg2rad(x): return pi * x / 180;