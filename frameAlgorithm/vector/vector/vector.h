#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>

template<typename value_type>
class VECTOR {

protected:
	struct object {
		//pointer to element on the left and right
		object * left, *right;
		//value in object
		value_type value;

		//contructor
		object(value_type val) : value(val) {
			left = right = nullptr;
		}

		//copy element
		void operator=(object * obj) {
			value_type td = obj->value;
			obj->value = value;
			value = td;
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
		for (auto &i : data) {
			push_back(i);
		}
	}

	///method
	//push at the end
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

	//delete last element
	void pop_back() {
		if (elements > 1) {
			elements--;
			auto lastLeft = last->left;
			delete last;
			last = lastLeft;
			last->right = nullptr;
			
		}
		else if(elements == 1) {
			elements--;
			delete last;
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

	//return value of the first element
	value_type& front() {
		return first->value;
	}

	//return value of the last element
	value_type& back() {
		return last->value;
	}

	//return pointer to first element
	decltype(auto) begin() {
		return first;
	}

	//return pointer to last element
	decltype(auto) end() {
		return last;
	}

	//delete all data from VECTOR
	void clear() {
		while (!empty())
			pop_back();
	}

	//erase element on by giving pointer to that element
	void erase(object* type) {
		if (size() > 1) {
			if (type == first) {
				auto td = first->right;
				first = td;
				td->left = nullptr;
			}
			else if (type == last) {
				auto td = type->left;
				last = td;
				td->right = nullptr;
			}
			else {
				auto tdLeft = type->left;
				auto tdRight = type->right;
				tdLeft->right = tdRight;
				tdRight->left = tdLeft;
			}
			delete type;
			elements--;
		}
		else if (size() == 1) {
			pop_back();
			elements--;
		}
	}

	value_type& operator[](const int index) {
		interator = begin();
		for (int i = 0; interator != end() && i <= index; i++) {
			if (i == index)
				return interator->value;
			interator = interator->right;
		}
		return UP->value;
	}

	//swap two object by pointer to that object
	void swap(object * obj1, object * obj2) {
		*(obj1) = obj2;
	}

	//return pointer to first element in VECTOR that contains x
	decltype(auto) find(value_type x) {
		if (!empty()) {
			for (auto it = begin(); it != end();) {
				if (it->value == x)
					return it;
				it = it->right;
			}
		}
		return UP;
	}

protected: 
	object * first, * last;
	size_t elements;
	//not exisit object and not used
	object * UP;
	object * interator;
};

#endif //! VECTOR_H