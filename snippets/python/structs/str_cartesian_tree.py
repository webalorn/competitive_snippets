CartNode = namedtuple('CartNode', ['val', 'rand', 'left', 'right', 'data'])
MAX_RAND = 10**9

def cart_split(tree, v):
	""" Returns a, b : a values < s, b values >= s """
	if tree is None:
		return None, None
	elif tree.val < v:
		a, b = cart_split(tree.right, v)
		return CartNode(tree.val, tree.rand, tree.left, a, tree.data), b
	else:
		a, b = cart_split(tree.left, v)
		return a, CartNode(tree.val, tree.rand, b, tree.right, tree.data)

def cart_merge(a, b):
	if a is None or b is None:
		return a or b
	if a is not None and b is not None and a.val > b.val:
		return cart_merge(b, a)
	if a.rand >= b.rand:
		return CartNode(a.val, a.rand, a.left, cart_merge(a.right, b), a.data)
	else:
		return CartNode(b.val, b.rand, cart_merge(a, b.left), b.right, b.data)

def cart_insert(tree, v, data=None):
	a, c = cart_split(tree, v)
	b = CartNode(v, randint(1, MAX_RAND), None, None, data)
	return cart_merge(cart_merge(a, b), c)

def cart_remove(tree, v):
	a, b = cart_split(tree, v)
	b, c = cart_split(b, v+1)
	return cart_merge(a, c)

def cart_get(tree, v):
	if tree:
		if tree.val == v: return tree
		if tree.val < v: return cart_get(tree.left, v)
		return cart_get(tree.right, v)

def cart_in(tree, v):
	return bool(cart_get(tree, v))

def cart_new_tree(values):
	t = None
	for v in values:
		t = cart_insert(t, v)
	return t

$0