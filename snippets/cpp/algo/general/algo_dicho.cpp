//@title Dichotomy algorithm
//@doc This snippet is not a function and must be inserted directly into the code
//@
int deb = 0, fin = ${1:10*1000};
while (deb+1 < fin) {
	int center = (deb + fin)/2;
	if (${2:some_function(center)} > ${3:target}) { // on garde partie supérieure
		fin = center;
	} else { // partie inférieure
		deb = center;
	}
}
$0
