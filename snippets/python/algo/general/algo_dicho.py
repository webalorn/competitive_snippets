a, b = 0, ${1:100} # Include / exclude
while a+1 < b: # We search the first n such as fct(n) is true
	m = (a+b-1)//2
	if ${2:fct(m)}:
		b=m+1
	else:
		a=m+1