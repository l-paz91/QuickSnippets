#include <iostream>
#include <conio.h>
#include <thread>
#include <mutex>

using namespace std;

void f(mutex& pMutex)
{
	unique_lock<mutex> lock{ pMutex };	// aquire the lock

	cout << "f: ";
	for (int i = 1; i < 10; ++i)
	{
		cout << i*100/5 << '\t';
	}
	cout << "\n";

	// lock released implicitly via destructor
}

struct F
{
	void operator()(mutex& pMutex)
	{
		unique_lock<mutex> lock{ pMutex };	// aquire the lock

		cout << "F: ";
		for (int i = 1; i < 10; ++i)
		{
			cout << i*100/5 << '\t';
		}
		cout << "\n";

		// lock released implicitly via destructor
	}
};

void simpleThreadExample()
{
	mutex m;

	thread t1{ f, ref(m) };
	thread t2{ F(), ref(m) };

	t1.join();	// wait for t1
	t2.join();	// wait for t2
}

int main()
{
	simpleThreadExample();

	_getch();
	return 0;
}
