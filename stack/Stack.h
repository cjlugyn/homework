#pragma once

#include"../vector/Vector.h"

template<typename T> class Stack : public Vector<T> {
public:
	void push(T const& e) {
		insert( size(), e);
	}// ��ջ
	T pop() {
		return remove(size() - 1);
	}//��ջ
	T& top{
		return (*this)[size() - 1];
	}
};