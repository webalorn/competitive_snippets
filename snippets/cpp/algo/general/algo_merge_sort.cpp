//@title Merge Sort algorithme
//@defines mergerSort
//@doc Can be adapted for any purpose (for exemple, any algorithm based on divide-to-conquer)
//@
template<class T> T mergeSort(T elements) {
	if (elements.size() >= 2) {
		T left, right;
		for (int iElement = 0; iElement < (int)elements.size()/2; iElement++) {
			left.push_back(elements[iElement]);
		}
		for (int iElement = (int)elements.size()/2; iElement < (int)elements.size(); iElement++) {
			right.push_back(elements[iElement]);
		}
		left = mergeSort(left);
		right = mergeSort(right);

		int i1 = 0, i2 = 0;
		while (i1 < (int)left.size()) {
			if (i2 >= (int)right.size() || left[i1] < right[i2]) {
				elements[i1+i2] = left[i1];
				i1++;
			} else {
				elements[i1+i2] = right[i2];
				i2++;
			}
		}
		while (i2< (int)right.size()) {
			elements[i1+i2] = right[i2];
			i2++;
		}
	}
	return elements;
}

