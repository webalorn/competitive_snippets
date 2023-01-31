class MaxSegTree:
	def __init__(self, size, val_init=-LLINF):
		self.size = size
		self.real_size = 1
		while self.real_size < size:
			self.real_size *= 2

		self.val = [-LLINF for _ in range(self.real_size*2)]
		for i in range(self.real_size+self.size):
			self.val[i] = val_init

	def get_leaf(self, leaf_id):
		return self.val[self.real_size + leaf_id]

	def set_leaf(self, leaf_id, new_value):
		node_id = self.real_size + leaf_id
		self.val[node_id] = new_value
		while node_id > 1:
			node_id //= 2
			self.val[node_id] = max(self.val[node_id*2], self.val[node_id*2+1])

	def max_interval(self, cur_node_id, target_left, target_right, sub_left=None, sub_right=None):
		sub_left, sub_right = sub_left or 0, sub_right or self.real_size

		if target_right <= sub_left or target_left >= sub_right: # No intersection
			return -LLINF
		elif target_left <= sub_left and sub_right <= target_right: # Inside of target
			return self.val[cur_node_id]
		else:
			mid = (sub_left + sub_right) // 2
			v1 = self.sum_interval(cur_node_id * 2, target_left, target_right, sub_left, mid)
			v2 = self.sum_interval(cur_node_id * 2 + 1, target_left, target_right, mid, sub_right)
			return max(v1, v2)