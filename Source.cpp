#include <iostream>
#include <locale>

using namespace std;
/*
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
*/
//#################### TASK_3 ####################

class OffTheField {
private:
	int old_x_coord;
	int old_y_coord;
	int new_x_coord;
	int new_y_coord;
public:
	OffTheField(int o_x, int o_y, int n_x, int n_y) : old_x_coord(o_x), old_y_coord(o_y), new_x_coord(n_x), new_y_coord(n_y)
	{
		if (n_x > 10 || n_x < 1)
		{
			cout << "ОШИБКА Введенные координаты X выходят за границу поля." << endl;
			cout << "[" << o_x << ":" << o_y << "] --> [" << n_x << ":" << n_y << "]" << endl;
		}
		if (n_y > 10 || n_y < 1)
		{
			cout << "ОШИБКА Введенные координаты Y выходят за границу поля." << endl;
			cout << "[" << o_x << ":" << o_y << "] --> [" << n_x << ":" << n_y << "]" << endl;
		}
	}
	~OffTheField() {}
};

class IllegalCommand {
private:
	int old_x_coord;
	int old_y_coord;
	int new_x_coord;
	int new_y_coord;
public:
	IllegalCommand(int o_x, int o_y, int n_x, int n_y) :
		old_x_coord(o_x), old_y_coord(o_y), new_x_coord(n_x), new_y_coord(n_y)
	{
		if (abs(o_x - n_x) > 1)
		{
			cout << "!!!ОШИБКА!!! координата X! Шаг дальше одной клетки." << endl;
			cout << "[" << o_x << ":" << o_y << "] --> [" << \
				(n_x) << ":" << n_y << "]" << endl;
		}

		if (abs(o_y - n_y) > 1)
		{
			cout << "!!!ОШИБКА!!! координата Y! Шаг дальше одной клетки." << endl;
			cout << "[" << o_x << ":" << o_y << "] --> [" << n_x << ":" \
				<< n_y << "]" << endl;
		}

		if (o_x == n_x && o_y == n_y)
		{
			cout << "!!!ОШИБКА!!! координаты X и Y! Введены текущие координаты!" << endl;
			cout << "[" << o_x << ":" << o_y << "] --> [" << n_x << ":" << n_y << "]" << endl;
		}
	}
	~IllegalCommand(){}

};

class Robot {
private:
	int x_coord;
	int y_coord;
public:
	Robot(int x_c = 5, int y_c = 5) : x_coord(x_c), y_coord(y_c)
	{
		cout << "Стартовые координаты: [" << x_coord << ":" << y_coord << "]" << endl;
	}

	~Robot() {}

	void Step(int x, int y)
	{
		if (abs(x_coord - x) > 1 || abs(y_coord - y) > 1 || (x_coord == x && y_coord == y))
			throw IllegalCommand(x_coord, y_coord, x, y);
		if (x > 10 || x < 1 || y > 10 || y < 1)
			throw OffTheField(x_coord, y_coord, x, y);
	
	cout << "Перемещение " << "[" << x_coord << ":" << y_coord << "] --> [" << x << ":" << y << "]" << endl;
	
	x_coord = x;
	y_coord = y;
	
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "#################### TASK_1 ####################" << endl << endl;
	/*
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
	*/
	cout << endl << "#################### TASK_3 ####################" << endl << endl;

	int x, y;
		
	cout << "===Для выхода введите координаты[0:0]===" << endl << endl;

	Robot robot;

	while (true)
	{
		cout << "Введите координату X: ";
		cin >> x;
		cout << "Введите координату Y: ";
		cin >> y;

		if (x == 0 && y == 0)
			break;

		try
		{
			robot.Step(x, y);
		}
		catch (const IllegalCommand& err)
		{
			cerr << &err << endl;
		}
		catch (const OffTheField& err)
		{
			cerr << &err << endl;
		}
	}

	return 0;

}