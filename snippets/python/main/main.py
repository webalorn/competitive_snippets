import sys, heapq, itertools
from copy import copy, deepcopy
from collections import deque, namedtuple
from itertools import *
from math import *
from random import * # randint, shuffle, ...
from functools import reduce, lru_cache
# from fractions import *
sys.setrecursionlimit(10**9)

def main():
	INF, LLINF = 10**9, 4*(10**18)
	MOD, MOD_EDU = 10**9+7, 998244353
	ID_FCT = lambda x:x
	# print = sys.stdout.write
	# input = sys.stdin.readline
	input = lambda : sys.stdin.readline().rstrip()
	cache = lru_cache(maxsize=None)

	def modul(n, mod=MOD): return (n%mod + mod)%mod
	def err_print(*args, end="\n", sep=" "): sys.stderr.write(" ".join(chain([str(a) for a in args], [end])))
	def list_map(string, fct=int): return list(map(fct, string.split()))
	def read_matrix(n, f=ID_FCT): return [list(map(f, sys.stdin.readline().strip().split())) for _ in range(n)]
	def read_char_matrix(n): return [sys.stdin.readline().strip() for _ in range(n)]


	# -------------------------------------------------------------------

	$0

	# -------------------------------------------------------------------

	

main()