#include <iostream>
#include <locale>

using namespace std;

//#################### TASK_1 ####################

template<typename T>
T div(T x, T y)
{
	if (y == 0)
		throw "DivisionByZero";

	return x / y;
}




//#################### TASK_2 ####################




int main()
{
	cout << "#################### TASK_1 ####################" << endl << endl;

	try {
		double a = 10;
		double b = 0;
		double z = div(a, b);

		cout << z << endl;
	}
	catch (const char* ex) {
		cerr << ex << endl;
	}


	cout << endl << "#################### TASK_2 ####################" << endl << endl;



	return 0;

}