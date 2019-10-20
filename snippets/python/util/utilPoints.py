moves = [(0, 1), (-1, 0), (0, -1), (1, 0)]
moves_char = ['E', 'N', 'O', 'S']
moves_diag = [(-1, 1), (-1, -1), (1, -1), (1, 1)];
def add_vect(a, b): return [x+y for x, y in zip(a, b)]
def sub_vect(a, b): return [x-y for x, y in zip(a, b)]
def opp_vect(a): return [-x for x in a]
def sqr_dist(a, b): return sum([(x-y)**2 for x, y in zip(a, b)])

