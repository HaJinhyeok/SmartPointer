#pragma once
#include "SharedPtr.h"

template<class T>
class WeakPtr
{
public:
	//WeakPtr(T* ptr = nullptr);
	WeakPtr(const SharedPtr<T>& sp);
	~WeakPtr();
	unsigned int getCount();
	T* getPtr() { return _ptr; }

	T* operator->() { return _ptr; }
	T& operator*() { return *_ptr; }
	WeakPtr<T>& operator=(const WeakPtr<T>&);

private:
	T* _ptr;
};

#include "WeakPtr_impl.h"