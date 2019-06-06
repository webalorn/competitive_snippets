#ifdef on_local
struct ContestExerciseImpl { void main(); };
void localPrint(string s) {cerr << s << "\n";}
int main() { ContestExerciseImpl().main(); }
#else
#include "exercise.hpp"
ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
#endif

void ContestExerciseImpl::main() { // You can use localPrint(string)
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	
	$0
}
