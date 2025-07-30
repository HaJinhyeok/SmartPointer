#include "SharedPtr.hpp"

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
	return 0;
}