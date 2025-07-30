#pragma once
#include <iostream>

using namespace std;

class RefCountBlock
{
public:
	unsigned int _count = 1;
};

template <class T>
class SharedPtr
{
public:
	// 기본 생성자
	SharedPtr(T* ptr = nullptr);
	// 복사 생성자
	SharedPtr(const SharedPtr<T>& sp);
	// 소멸자
	~SharedPtr();
	// 참조횟수 반환
	unsigned int getCount();
	// 포인터 반환
	T* getPtr() { return _ptr; }

	T* operator->() { return _ptr; }
	T& operator*() { return *_ptr; }
	SharedPtr<T>& operator=(const SharedPtr<T>& sp);

	void reset();
	void swap(SharedPtr&);


private:
	// 참조자 증가 시
	void addRef();
	// 참조자 감소 시
	void release();

private:
	T* _ptr;
	RefCountBlock* _block;
};

