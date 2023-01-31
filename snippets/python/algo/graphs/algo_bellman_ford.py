def bellman_ford(edges, sources, times=None, steps=None):
	# edges : [(vertex_from, vertex_to, length)]
	if times is None:
		times = {k:0 for k in sources}
		for e_from, e_to, _ in edges:
			times[e_from] = times.get(e_from, LLINF)
			times[e_to] = times.get(e_to, LLINF)
	else:
		times = copy(times)
	if steps is None:
		steps = len(times)

	for _ in range(steps):
		times_prev = times
		# times_prev = copy(times) # <Uncomment if you want a "strict" BF step>
		for e_from, e_to, length in edges:
			times[e_to] = min(times[e_to], times_prev[e_from] + length)
	return times