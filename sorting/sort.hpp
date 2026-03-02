#ifndef _SORT_HPP
#define _SORT_HPP

#include "List.hpp"

#include <utility>

template<typename T> 
inline void quick_sort(List<T>& list, int first, int last)
{
	// base case to stop sorting
	if(first >= last){
		return;
	}
	
	// find pivot
	int pivotIndex = partition(list, first, last);
	
	// recurively sort subarrays smaller and larger than pivot
	quick_sort(list, first, pivotIndex - 1);
	quick_sort(list, pivotIndex + 1, last);
}

/** Partition a sub-list by moving items relative to the pivot.
 * Always choose the first item as the pivot.
 * Sub-list is specified with inclusive indices first and last.
 * Assume no duplicates.
 * @param first index of the first item in the sub-list to be partitioned (inclusive)
 * @param last index of the last item in the sub-list to be partitioned (inclusive)
 * @return index of the pivot item after partitioning */
template <typename T>
inline int partition(List<T>& list, int first, int last) {
	T pivot = list.getEntry(first);

	int left = first+1;
	int right = last;

	bool done = false;
	while(!done){
		while(left <= right && list.getEntry(left) < pivot){
			left++;
		}
		while(left <= right && list.getEntry(right) > pivot){
			right--;
		}
		if(left < right){
			T temp = list.getEntry(left);
			list.setEntry(left, list.getEntry(right));
			list.setEntry(right, temp);
			
			left++;
			right--;
		} else {
			done = true;
		}
	}

	list.setEntry(first, list.getEntry(right));
	list.setEntry(right, pivot);
	return right;
}

#endif
