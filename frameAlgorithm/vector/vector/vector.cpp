#include "stdafx.h"
#include "vector.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
	VECTOR<std::string> vec = { "Ja", "maka", "lubic","jesc" };

	//erase element from vector
	vec.erase(vec.find("Ja"));
	//try to swap elements
	vec.swap(vec.begin()+1, vec.end());
	//try clear method
	//vec.clear();

	//here is mistake because it didn't work
	std::cout << vec[1] << std::endl;

	//wykonuje się jeżeli nic nie zwraaca
	std::cin.get();
    return 0;
}

