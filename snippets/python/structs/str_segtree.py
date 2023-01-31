class SegTree:
	def __init__(self, size):
		self.size = size
		self.real_size = 1
		while self.real_size < size:
			self.real_size *= 2

		# <TODO: set default values instead of 0>
		self.val = [0 for _ in range(self.real_size*2)] # Values of leaves and intervals
		self.val_propagate = [0 for _ in range(self.real_size*2)] # Lazy propagation

	def get_leaf(self, leaf_id):
		return self.val[self.real_size + leaf_id]

	def propagate(self, node_id):
		if node_id < self.real_size:
			pass # <TODO: Write update propagation here>

	def update_val_interval(self, cur_node_id, val_update, target_left, target_right, sub_left=None, sub_right=None):
		sub_left, sub_right = sub_left or 0, sub_right or self.real_size
		self.propagate(cur_node_id)

		if target_right <= sub_left or target_left >= sub_right: # No intersection
			return
		elif target_left <= sub_left and sub_right <= target_right: # Inside of target
			self.val_propagate[cur_node_id] += val_update # <TODO: Write lazy update here>
		else:
			mid = (sub_left + sub_right) // 2
			self.update_val_interval(cur_node_id * 2, val_update, target_left, target_right, sub_left, mid)
			self.update_val_interval(cur_node_id * 2 + 1, val_update, target_left, target_right, mid, sub_right)

	def request_interval(self, cur_node_id, target_left, target_right, sub_left=None, sub_right=None):
		sub_left, sub_right = sub_left or 0, sub_right or self.real_size
		self.propagate(cur_node_id)

		if target_right <= sub_left or target_left >= sub_right: # No intersection
			return 0 # <TODO: Return no value>
		elif target_left <= sub_left and sub_right <= target_right: # Inside of target
			return self.val[cur_node_id] # <TODO: Return current value>
		else:
			mid = (sub_left + sub_right) // 2
			v1 = self.request_interval(cur_node_id * 2, target_left, target_right, sub_left, mid)
			v2 = self.request_interval(cur_node_id * 2 + 1, target_left, target_right, mid, sub_right)
				return v1 + v2 # <TODO: Return aggregation of values>