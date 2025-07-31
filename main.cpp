//#include "SharedPtr.hpp"
//#include "SharedPtr.h"
#include "WeakPtr.h"

class Test
{
public:
	Test(string name) :_name(name) {};
	SharedPtr<Test> target;
private:
	string _name;
};

int main()
{
	SharedPtr<int> ptr1(new int(11));
	SharedPtr<int> ptr2(ptr1);

	cout << "ptr1: " << *ptr1.getPtr() << ", count1: " << ptr1.getCount() << '\n';
	cout << "ptr2: " << *ptr2.getPtr() << ", count2: " << ptr2.getCount() << '\n';

	{
		SharedPtr<int> ptr3 = ptr2;
		cout << "ptr3: " << *ptr3.getPtr() << ", count3: " << ptr3.getCount() << '\n';
	}

	// 순환 참조
	{
		SharedPtr<Test> test1(new Test("test1"));
		SharedPtr<Test> test2(new Test("test2"));
		test1->target = test2;
		test2->target = test1;
		cout << "test1: " << test1.getCount() << '\n';
		cout << "test2: " << test2.getCount() << '\n';
	}
	// WeakPtr로 순환 참조 해결
	{

	}
	return 0;
}