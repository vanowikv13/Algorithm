#pragma once
#ifndef STACK_H
#define STACK_H

template<typename T>
class stack final {
protected:
	//for object in stack
	struct obj {
		obj*next;
		obj *before;
		T value;
	};

public:
	inline stack() {
		elements = 0;
		last = first = nullptr;
	}

	inline stack(std::initializer_list<T> & ini) {
		for (auto it = ini.begin(); it != ini.end(); it++)
			(*this).push(*it);
	}

	~stack() {
		clear();
	}
	//clear all element in stack
	inline void clear() {
		while (!empty()) {
			pop();
		}
	}
	//return size of element
	inline int size() const {
		return elements;
	}
	//return true if stack is empty pr is not return false
	inline bool empty() const {
		if ((this->size()) == 0)
			return true;
		else return false;
	}

	//add at the end element on stack
	void push(T el) const {
		auto ob = new obj;
		ob->value = el;
		ob->next = nullptr;
		if (empty()) {
			first = ob;
			ob->before = nullptr;
		}
		else {
			ob->before = last;
			last->next = ob;
		}
		elements++;
		last = ob;
	}
	//delete the last element from stack
	void pop() {
		tryC();
		if (size() == 1) {
			delete first;
			elements--;
		}
		else {
			obj * w = last;
			last = w->before;
			last->next = nullptr;
			delete w;
			elements--;
		}
	}
	//return the value from the last element in the stack
	inline T top() const {
		checkIsEmpty();
		return last->value;
	}
	//return pointer to the smalest object with value
	obj & min() {

		checkIsEmpty();
		obj * min = first, *it = first->next;
		while (it != nullptr) {
			if (it->value < min->value)
				min = it;
			it = it->next;
		}
		return *min;
	}
	//if don't find the obj return nullptr	
	obj * search(const T val) {
		checkIsEmpty();
		obj * help = first;
		do {
			if (help->value == val)
				return help;
			help = help->next;
		} while (help != last);
		return nullptr;
	}
	//cheng elment in stack by order
	void changeOrder() const {
		checkIsEmpty();
		obj * left = first, *right = last, help; int i = 1, j = size();
		while (left != right && i < j) {
			swap(left, right);
			i++; j--;
			left = left->next;
			right = right->before;
		}
	}
	
	inline void swap(obj * left,obj * right) const {
		auto help = *left;
		auto leftCopyRight = [this](obj * A, obj * B) {A->value = B->value; A->next = B->next; A->before = B->before; };
		leftCopyRight(left, right);
		leftCopyRight(left, &help);
	}

protected:
	int elements;
	obj*first, *last;

	//check for function is empty
	inline const char * checkIsEmpty() const {
		if (empty())
			throw "error -- stack is empty";
	}
	///don't work 
	inline void tryC() const {
		try {
			checkIsEmpty();
		}
		catch (std::string str) {
			EXIT_FAILURE;
		}
	}
};


#endif // !STACK_H