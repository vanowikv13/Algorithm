#include "stdafx.h" //for VS
#include "vector.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{

	VECTOR<int> vec;
	for (int i = 0; i < 3; i++)
		vec.push_back(i);

	//erase element from vector
	//vec.erase(vec.find("Ja"));
	//try to swap elements
	//try clear method
	//vec.clear();

	std::vector<int> vect = { 1,2,3,4 };
	vect.begin();

	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << std::endl;
	}
	//wykonuje się jeżeli nic nie zwraaca
	std::cin.get();
    return 0;
}

