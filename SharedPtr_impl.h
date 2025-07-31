#pragma once

template<class T>
SharedPtr<T>::SharedPtr(T* ptr)
	: _ptr(ptr), _block(nullptr)
{
	cout << "SharedPtr 기본 생성자 호출\n";
	addRef();
}
template<class T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& sp)
	:_ptr(sp._ptr), _block(sp._block)
{
	cout << "SharedPtr 복사 생성자 호출\n";
	addRef();
}
template<class T>
SharedPtr<T>::~SharedPtr()
{
	release();
}
template<class T>
unsigned int SharedPtr<T>::getCount()
{
	return _block->_count;
}
template<class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& sp)
{
	_ptr = sp._ptr;
	_block = sp._block;
	addRef();

	return *this;
}
template<class T>
void SharedPtr<T>::reset()
{

}
template<class T>
void SharedPtr<T>::swap(SharedPtr& sp)
{

}
template<class T>
void SharedPtr<T>::addRef()
{
	if (_block == nullptr)
	{
		_block = new RefCountBlock;
	}
	else
	{
		_block->_count++;
	}
}
template<class T>
void SharedPtr<T>::release()
{
	_block->_count--;
	cout << "현재 참조횟수: " << _block->_count << '\n';
	if (_block->_count <= 0)
	{
		delete _ptr;
		_ptr = nullptr;
		delete _block;
		_block = nullptr;
	}
}