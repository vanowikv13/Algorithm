#pragma once
#ifndef BASICFUNCTION_H
#define BASICFUNCTION_H
#include <iostream>
#include <string>

template<typename T>
void write(T *tab, size_t n, bool xd = false) {
	for (size_t i = 0; i < n; i++) {
		std::cout << tab[i];
		if (xd) std::cout << std::endl;
		else std::cout << " ";
	}
	if (!xd)std::cout << std::endl;
}

std::string copyx(int x, int y, std::string a) { //kopiuje stringa od x(z x) do y(bez y)
	std::string newa = "";
	for (int i = x; i < y; i++)
		newa += a[i];
	return newa;
}


#endif // !BASICFUNCTION_H