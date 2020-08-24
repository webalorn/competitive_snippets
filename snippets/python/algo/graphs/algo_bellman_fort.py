n, m, deb, t_total = map(int, input().split())
vois = [[] for _ in range(n+1)]
tmin = [INF] * (n+1)

for i in range(m):
	a, b, l = map(int, input().split())
	vois[a].append((b, -l))
	# vois[b].append((a, -l))

def bellman_ford(sources, vois, times=None, steps=None):
	if steps is None:
		steps = len(vois)
	if times is None:
		times = [INF] * len(vois)
		for k in sources:
			times[k] = 0

	for s in range(steps):
		times2 = times
		# times2 = copy(times)
		for i, vlist in enumerate(vois):
			for j, l in vlist:
				times2[j] = min(times2[j], times[i] + l)
		# times[:] = times2
	return times