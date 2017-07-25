#pragma once
#ifndef STACK_H
#define STACK_H

template<typename T>
class stack {
	//for object in stack
	struct obj {
		obj*next;
		obj *before;
		T value;
	};

public:
	stack() {
		elements = 0;
		last = first = nullptr;
	}

	stack(std::initializer_list<T> & ini) {
		for (auto it = ini.begin(); it != ini.end(); it++)
			(*this).push(*it);
	}

	~stack() {
		clear();
	}
	//clear all element in stack
	void clear() {
		while (!empty()) {
			pop();
		}
	}
	//return size of element
	int size() {
		return elements;
	}
	//return true if stack is empty pr is not return false
	bool empty() {
		if ((this->size()) == 0)
			return true;
		else return false;
	}

	//add at the end element on stack
	void push(T el) {
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
		checkIsEmpty();
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
	T top() {
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
	obj * search(T val) {
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
	void changeOrder() {
		checkIsEmpty();
		obj * left = first, *right = last, help; int i = 1, j = size();
		while (left != right && i < j) {
			swap(left, right);
			i++; j--;
			left = left->next;
			right = right->before;
		}
	}
	
	void swap(obj * left,obj * right) {
		auto help = *left;
		auto leftCopyRight = [](obj * A, obj * B) {A->value = B->value; A->next = B->next; A->before = B->before; };
		leftCopyRight(left, right);
		leftCopyRight(left, &help);
	}

protected:
	int elements;
	obj*first, *last;

	//check for function is empty
	void checkIsEmpty() {
		if (empty())
			throw "error -- stack is empty";
	}
};

#endif // !STACK_H