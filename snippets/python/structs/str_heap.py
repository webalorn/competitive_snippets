class Heap(): # Smaller on top
	def __init__(self, l=None):
		self.l = copy(l or [])
		if self.l: heapq.heapify(self.l)
	def push(self, el): return heapq.heappush(self.l, el)
	def top(self): return self.l[0]
	def pop(self): return heapq.heappop(self.l)
	def size(self): return len(self.l)
	def is_empty(self): return self.l == []
	def clear(self): self.l = []

$0