#include "stdafx.h"
#include "vector.h"
#include <iostream>
#include <string>

int main()
{
	VECTOR<std::string> vec;
	vec.push_back("Napis");
	vec.push_back("Napis2");
	vec.push_back("Napis3");

	if (vec.empty())
		std::cout << "pusty" << std::endl;
	else
		std::cout << "Cos tam jest " << std::endl;

	std::cin.get();
    return 0;
}

