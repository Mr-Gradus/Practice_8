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

class Ex {
//private:
	//double x;
public:
	double x;
	Ex(double) {}
	Ex() {}
	~Ex() {}
};

class Bar {
private:
	double y = 0;
public:
	Bar(double) {}
	Bar() {}
	~Bar() {}
	
	void setBar(const double &a)
	{
		if ((y + a) > 100)
			throw Ex(a * y);
		else (y = a);
	}
};

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

	Bar bar;
	int n;
	while (cin >> n && n != 0)
	{
		try
		{
			bar.setBar(n);
		}

		catch (Ex& c)
		{

			cerr << "Error: " << c.x << endl;
		}
	}
	return 0;

}