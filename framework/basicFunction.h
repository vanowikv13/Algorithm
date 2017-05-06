#pragma once
#ifndef BASICFUNCTION_H
#define BASICFUNCTION_H
#include <iostream>


template<typename T>
void write(T *tab, size_t n, bool xd = false) {
	for (size_t i = 0; i < n; i++) {
		std::cout << tab[i];
		if (xd) std::cout << std::endl;
		else std::cout << " ";
	}
	if (!xd)std::cout << std::endl;
}


#endif // !BASICFUNCTION_H