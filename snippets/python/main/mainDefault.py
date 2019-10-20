import sys, heapq
from functools import reduce
from copy import deepcopy as copy
from collections import deque, namedtuple
from math import *
from random import randint, shuffle

def main():
	INF, LLINF = 10**9, 4*(10**18)
	MOD = 10**9+7
	ID_FCT = lambda x:x
	input, print = sys.stdin.readline, sys.stdout.write

	def modul(n, mod=MOD): return (n%mod + mod)%mod
	def err_print(*args, end="\n", sep=" "): sys.stderr.write(" ".join([str(a) for a in args]))
	def ls_map(string, fct=int): return list(map(fct, string.split()))

	# -------------------------------------------------------------------

	$1

	# -------------------------------------------------------------------

	$0

main()