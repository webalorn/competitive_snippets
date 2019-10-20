class Heap(): # Smaller on top
	def __init__(self, l=[]):
		self.l = copy(l)
		if self.l: heapq.heapify(self.l)
	def push(self, el): return heapq.heappush(self.l, el)
	def top(self): return self.l[0]
	def pop(self): return heapq.heappop(self.l)
	def size(self): return len(self.l)
	def empty(): return self.l == []

$0