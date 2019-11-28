def cart_to_tab_add(tree, l):
	if tree:
		cart_to_tab_add(tree.left, l)
		l.append(tree.val)
		cart_to_tab_add(tree.right, l)

def cart_to_tab(tree):
	l = []
	cart_to_tab_add(tree, l)
	return l

def cart_haut(tree):
	return 1+max(cart_haut(tree.right), cart_haut(tree.left)) if tree else 0

def cart_to_str(tree):
	if tree == None:
		return []
	a, b = cart_to_str(tree.left), cart_to_str(tree.right)
	s = "{}[{}]".format(tree.val, tree.rand)

	n = max([len(l) for l in a]) if a else 0
	m = max([len(l) for l in b]) if b else 0
	while len(a) < len(b): a.append(" "*n)
	while len(a) > len(b): b.append(" "*m)
	return [" "*n + s + " "*m] + [x + " "*len(s) + y for x, y in zip(a, b)]

def cart_print(tree):
	print("\n".join(cart_to_str(tree)))

$0