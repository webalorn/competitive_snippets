class Deque:
	def __init__(self, data=None): self._left, self._right = [], list(data) if data is not None else []
	def __len__(self): return len(self._left) + len(self._right)
	def __repr__(self): return str(self._left[::-1] + self._right)
	def __getitem__(self, i):
		ll, lr = len(self._left), len(self._right)
		if i < 0: i = ll+lr+i
		if i < ll: return self._left[ll-i-1]
		return self._right[i-ll]
	def __fill_right(self):
		x = len(self._left)//2
		self._right, self._left = self._left[x::-1], self._left[x:]
	def __fill_left(self):
		x = len(self._right)//2
		self._left, self.right = self._right[x-1::-1], self._right[x:]

	def left(self): return self._left[-1] if self._left else self._right[0]
	def right(self): return self._right[-1] if self._right else self._left[0]
	def pushleft(self, v): self._left.append(v)
	def pushright(self, v): self._right.append(v)
	def popleft(self):
		if not self._left: self.__fill_left()
		return self._left.pop()
	def popright(self):
		if not self._right: self.__fill_right()
		return self._right.pop()

$0