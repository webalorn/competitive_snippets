def argmin(l): return l.index(min(l))
def argmax(l): return l.index(max(l))

def dict_min(d): return min(d.values())
def dict_max(d): return max(d.values())
def dict_argmin(d):m = dict_min(d);return [el for el, v in d.items() if v==m][0]
def dict_argmax(d):m = dict_max(d);return [el for el, v in d.items() if v==m][0]

def uchain(*args):return list(chain(*args))
def l2str(l,sep=''):return sep.join(map(str, l))

class Reindexer:
	def __init__(self, l=None): self._l, self._inv = set(l) if l else set(), None
	def add(self, x): self._l.add(x)
	def build(self):
		self._l = list(sorted(self._l))
		self._inv = {x: i for i, x in enumerate(self._l)}
	def __getitem__(self, x): return self._inv[x]
	def get(self, x): return self._inv[x]
	def map(self, xs): return [self._inv[x] for x in xs]
	def get_inv(self, i): return self._l[i]