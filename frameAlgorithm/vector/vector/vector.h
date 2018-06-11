#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>

template<typename value_type>
class VECTOR {

protected:
	class object {

	protected:
		//pointer to element on the left and right
		object * left, *right;
		friend VECTOR;

	public:
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
	inline int size() noexcept {
		return elements;
	}

	//check if VECTOR is empty
	inline bool empty() noexcept {
		return elements > 0 ? false : true;
	}

	//return value of the first element
	inline value_type& front() {
		return first->value;
	}

	//return value of the last element
	inline value_type& back() {
		return last->value;
	}

	//return pointer to first element
	inline decltype(auto) front_pointer() {
		return first;
	}

	//return pointer to last element
	inline decltype(auto) back_pointer() {
		return last;
	}

	inline decltype(auto) end() {
		//pointer to the last element
		return first;
	}

	//delete all data from VECTOR
	inline void clear() {
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
		pointer = front_pointer();
		for (int i = 0; pointer != end() && i <= index; i++) {
			if (i == index)
				return pointer->value;
			pointer = pointer->right;
		}
		return UP->value;
	}

	//swap two object by pointer to that object
	inline void swap(object * obj1, object * obj2) {
		*(obj1) = obj2;
	}

	//return pointer to first element in VECTOR that contains x
	decltype(auto) find(value_type x) {
		if (!empty()) {
			for (auto it = front_pointer(); it != end();) {
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
	object * pointer;
};

#endif //! VECTOR_H