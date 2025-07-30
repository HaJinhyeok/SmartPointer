#include <iostream>

using namespace std;

class A
{
public:
	A(int n) :num(n)
	{
		cout << "Constructor called...\n";
	}
	~A()
	{
		cout << "Destructor called...\n";
	}
	int GetNum()
	{
		return num;
	}
private:
	int num;
};

int main()
{
	int* myNum = new int(5);
	int* myNum2 = myNum;
	A* test = new A(10);

	shared_ptr<int> testShared = make_shared<int>(5);

	cout << "Hello" << test->GetNum() << "\n";
	cout << "myNum: " << *myNum << '\n';
	delete test;
	delete myNum;
	myNum = nullptr;
	cout << "Bye" << test->GetNum() << "\n";
	if (myNum)
		cout << "myNum: " << *myNum << '\n';
	if (myNum2)
		cout << "myNum2: " << *myNum2 << '\n';

	return 0;
}