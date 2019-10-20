MAX_NODES = 10**4
G_FIRST_ID = 0

G_PONDERE = False
G_ORIENTED = False

Arc = namedtuple('Arc', ['dest', 'weight'] if G_PONDERE else ['dest'])

voisins = [[] for _ in range(MAX_NODES)]
G_parents = [[] for _ in range(MAX_NODES)] if G_ORIENTED else []

nb_nodes, nb_edges = 0, 0