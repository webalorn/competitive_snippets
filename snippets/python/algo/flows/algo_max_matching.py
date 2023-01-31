def max_matching(edges):
	# Edges: a list of (vertex_left, vertex_right) edges
	n_left = max([e[0] for e in edges] or [-1])+1
	n_right = max([e[1] for e in edges] or [-1])+1
	is_left_linked = [False] * n_left
	right_linked_to = [-1] * n_right
	last_seen = [[-1] * n for n in [n_left, n_right]]
	voisins = [[[] for _ in range(n)] for n in [n_left, n_right]]
	for e1, e2 in edges:
		voisins[0][e1].append(e2)
		voisins[1][e2].append(e1)

	for start in range(n_left):
		if not is_left_linked[start]:
			stack = [(0, start, 0)]
			found_path = False
			while stack and not found_path:
				side, node, i_vois = stack.pop()
				if i_vois == 0:
					last_seen[side][node] = start
				
				if side == 0:
					if i_vois < len(voisins[side][node]):
						next_node = voisins[side][node][i_vois]
						stack.append((side, node, i_vois+1))
						if last_seen[1 - side][next_node] < start:
							stack.append((1 - side, next_node, 0))
				else:
					if right_linked_to[node] == -1:
						found_path = True
						stack.append((side, node, i_vois))
					elif i_vois == 0 and last_seen[1 - side][right_linked_to[node]] < start:
						stack.append((side, node, 1))
						stack.append((1 - side, right_linked_to[node], 0))
			if found_path:
				for (_, left_node, _), (_, right_node, _) in zip(stack[::2], stack[1::2]):
					right_linked_to[right_node] = left_node
				is_left_linked[left_node] = True

	# return right_linked_to # <Uncomment to return this insted of a list of edges>
	couples = []
	for right, left in enumerate(right_linked_to):
		if left != -1:
			couples.append((left, right))
	return couples

