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
	// �⺻ ������
	SharedPtr(T* ptr = nullptr);
	// ���� ������
	SharedPtr(const SharedPtr<T>& sp);
	// �Ҹ���
	~SharedPtr();
	// ����Ƚ�� ��ȯ
	unsigned int getCount();
	// ������ ��ȯ
	T* getPtr() { return _ptr; }

	T* operator->() { return _ptr; }
	T& operator*() { return *_ptr; }
	SharedPtr<T>& operator=(const SharedPtr<T>& sp);

	void reset();
	void swap(SharedPtr&);


private:
	// ������ ���� ��
	void addRef();
	// ������ ���� ��
	void release();

private:
	T* _ptr;
	RefCountBlock* _block;
};

