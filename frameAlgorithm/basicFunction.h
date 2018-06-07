#pragma once
#ifndef BASICFUNCTION_H
#define BASICFUNCTION_H
#include <iostream>
#include <string>

//write a tab in all type with difrent option
template<typename T>
void write(T *tab, size_t n, bool xd = false) {
	for (size_t i = 0; i < n; i++) {
		std::cout << tab[i];
		if (xd) std::cout << std::endl;
		else std::cout << " ";
	}

	if (!xd)
		std::cout << std::endl;
}

//copy string from x with x to y without y
std::string copyx(int x, int y, std::string a) {
	std::string coping = "";
	for (int i = x; i < y; i++)
		coping += a[i];
	return coping;
}

//swap object
template<typename T>
void swap(T & x1, T& x2) {
	T x = x1;
	x1 = x2;
	x2 = x;
}

//find maximum sum in the array
template<typename T>
T divide(T arr[], int low, int high, bool maximalSum = true) {
	//determine if we have only one element in array
	if (low == high)
		return arr[low];

	int i;
	T sum = 0, leftSum = arr[0], rightSum=arr[0], overlapSum=arr[0];
	int first = low;
	int mid = (high / 2);
	int last = high;

	//we calculate the sum of the left and right part of the array----------
	for (i = first; i < mid; i++) {
		sum = sum + arr[i];
		if (maximalSum) {
			if (leftSum < sum) {
				leftSum = sum;
			}
		}
		else {
			if (leftSum > sum) {
				leftSum = sum;
			}
		}
	}
	for (i = (mid + 1); i < last; i++) {
		sum = sum + arr[i];
		if (maximalSum) {
			if (rightSum < sum) {
				rightSum = sum;
			}
		}
		else {
			if (rightSum > sum) {
				rightSum = sum;
			}
		}
	}
	//------------------------------------------------------------------------
	//calculate the sum of all elements in the array
	overlapSum = conquer(arr, first, mid, last,maximalSum);
	if (maximalSum) {
		//set the maximum weight of the arrays--------------------------------
		if ((leftSum > rightSum) && (leftSum > overlapSum))
			return leftSum;
		else if ((rightSum > leftSum) && (rightSum > overlapSum))
			return rightSum;

	}
	else {
		//set the minimum weight of the arrays--------------------------------
		if ((leftSum < rightSum) && (leftSum < overlapSum))
			return leftSum;
		else if ((rightSum < leftSum) && (rightSum < overlapSum))
			return rightSum;
	}

	return overlapSum;
	//--------------------------------------------------------------------
}


#endif // !BASICFUNCTION_H