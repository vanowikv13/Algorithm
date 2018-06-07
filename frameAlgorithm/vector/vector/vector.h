#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>

template<typename value_type>
class VECTOR {

protected:
	struct object {
		object * left, *right;
		value_type value;
		object(value_type val) : value(val) {
			left = right = nullptr;
		}
	};

public:
	///constructors
	VECTOR() {
		first = last = nullptr;
		elements = 0;
	}

	VECTOR(const std::initializer_list<value_type> &data) {
		elements = 0;
		for (int i : data) {
			//push_back(data[i]);
		}
	}

	///method
	//push at the end element
	void push_back(value_type push) {
		object * test = new object(push);

		if (empty())
			first = test;
		else {
			test->left = last;
			last->right = test;
		}
		last = test;
		elements++;
	}

	void pop_back() {
		if (!empty() && elements > 1) {
			elements--;
			auto lastLeft = last->left;
			delete last;
			last = lastLeft;
			last->right = nullptr;
			
		}
		else if(elements == 1) {
			elements--;
			delete first;
			first = last = nullptr;
		}
	}

	//return number of elements
	int size() {
		return elements;
	}

	//check if VECTOR is empty
	bool empty() {
		return elements > 0 ? false : true;
	}

protected: 
	object * first, * last;
	size_t elements;
};

#endif //! VECTOR_H