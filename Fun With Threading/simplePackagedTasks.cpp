// -----------------------------------------------------------------------------
// https://lptcp.blogspot.com/
// 
/*
	Fun with Multithreading

	Following along with the Udemy Course: Learn Multithreading in C++

*/
// https://github.com/l-paz91/
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <iostream>
#include <conio.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <future>
#include <exception>

using namespace std;

// -----------------------------------------------------------------------------

double calculatePI(int pTerms)
{
	double sum = 0.0;

	if (pTerms < 1)
	{
		throw runtime_error("terms cannot be less than 1");
	}

	for (int i = 0; i < pTerms; ++i)
	{
		int sign = pow(-1, i);
		double term = 1.0 / (i * 2 + 1);
		sum += sign * term;
	}

	return sum * 4;
}

// -----------------------------------------------------------------------------

int main()
{
	packaged_task<double(int)> task1(calculatePI);
	future<double> future1 = task1.get_future();

	thread t1(move(task1), 0);

	try
	{
		double result = future1.get();
		cout << setprecision(15) << result << endl;
	}
	catch (const std::exception& e)
	{
		cout << "Error!" << e.what() << endl;
	}

	t1.join();



	cout << "Press any key to continue..." << endl;
	_getch();
	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
