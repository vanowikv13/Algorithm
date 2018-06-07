#pragma once
#ifndef SORTING_H
#define SORITNG_H


template<typename T>
void insetionSort(T *tab, size_t n) {
	//Loop through all the elements
	for (int j = 1; j < n; j++) {
		T key = tab[j]; //start value
		int i = j - 1; //secend index
		while (i >= 0 && tab[i] > key) {
			tab[i + 1] = tab[i];
			i = i - 1;
		}
		tab[i + 1] = key;

	}
}
//function need mergeSort
template<typename T>
void merge(T *tab, int p, int n, int mid) {
	int i = p, j = mid + 1, q = p;
	T * t = new T[n];
	for (int i = p; i <= n; i++) t[i] = tab[i];
	i = p;
	while (i <= mid && j <= n) {
		if (t[i] < t[j])
			tab[q++] = t[i++];
		else
			tab[q++] = t[j++];
	}
	while (i <= mid) tab[q++] = t[i++];
}

template<typename T>
void mergeSort(T * tab, int p, int n) {
	int mid;
	if (p < n) {
		mid = (p + n) / 2;
		mergeSort(tab, p, mid);
		mergeSort(tab, mid + 1, n);
		merge(tab, p, n, mid);
	}
}

template<typename T>
void bubbleSort(T *tab, size_t n) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (tab[j] < tab[j - 1]) {
				swap(tab[j], tab[j - 1]);
			}
		}
	}
}

#endif // !SORTING_H