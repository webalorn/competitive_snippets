import sys, heapq, itertools
from functools import reduce
from copy import deepcopy as copy
from collections import deque, namedtuple
from math import *
from random import randint, shuffle

def main():
	INF, LLINF = 10**9, 4*(10**18)
	MOD = 10**9+7
	ID_FCT = lambda x:x

	def modul(n, mod=MOD): return (n%mod + mod)%mod
	def err_print(*args, end="\n", sep=" "): sys.stderr.write(" ".join([str(a) for a in args]))
	def print(*args, end="\n", sep=" "): sys.stdout.write(sep.join([str(a) for a in args]) + end)
	def ls_map(string, fct=int): return list(map(fct, string.split()))
	def input(): return sys.stdin.readline().rstrip('\n')
	def in_int(n=1): return int(sys.stdin.readline()) if n==1 else [int(sys.stdin.readline()) for _ in range(n)]
	def in_map(f=int): return map(f, sys.stdin.readline().split())
	def in_grid(n, f=ID_FCT): return [in_map(f) for _ in range(n)]
	def in_grid_char(n, f=ID_FCT): return [[f(c) for c in sys.stdin.readline()] for _ in range(n)]

	# -------------------------------------------------------------------

	$1

	# -------------------------------------------------------------------

	$0

main()