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
	promise<double> promise1;

	auto do_calc = [&](int terms) {
		try
		{
			auto result = calculatePI(terms);
			promise1.set_value(result);
		}
		catch (const std::exception& e)
		{
			promise1.set_exception(current_exception());
		}
	};

	thread t1(do_calc, 5);
	t1.join();

	future<double> future1 = promise1.get_future();

	try
	{
		cout << setprecision(15) << future1.get() << endl;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

	cout << "Press any key to continue..." << endl;
	_getch();
	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
