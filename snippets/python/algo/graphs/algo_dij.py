import heapq
hpush, hpop = heapq.heappush, heapq.heappop
INF = 10**9

# n, m, deb, fin = map(int, input().split())
vois = [[] for _ in range(n+1)]
tmin = [INF] * (n+1)
prev = [-1] * (n+1)

# for i in range(m):
# 	a, b, l = map(int, input().split())
# 	vois[a].append((b, l))
# 	vois[b].append((a, l))

sits = [(0, deb)]
tmin[deb] = 0
while sits:
	t, pos = hpop(sits)
	if tmin[pos] == t:
		for (v, l) in vois[pos]:
			if t+l < tmin[v]:
				tmin[v] = t+l
				prev[v] = pos
				hpush(sits, (t+l, v))