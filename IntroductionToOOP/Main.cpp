#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "n---------------------------------------------------\n"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//			Constructors
	/*Point()
	{
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this -> x = x;
		y = 0;
		cout << "1ArgConstructor:\t " << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor;\t " << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t " << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//			Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}


	//			Methods

	double distanse(const Point& other)
	{
		//this - это точка
		//other - другая точка (указанная точка)
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};
double distance(Point& A, Point& B);

//#define STRUCT_POINT
///#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_OPERATOR
void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT 
	int a; //Обьявление переменной 'a' типа 'int'
	Point A;  //Обьявление переменной 'A' типа 'Point'
	          //Обьявление обьекта 'A'  типа 'Point'
	          //Создание экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif
#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();
	Point B;
	B.set_x(7);
	B.set_y(8);
	//cout << B.get_x() << "\t" << B.get_y() << endl;
	B.print();
	cout << delimiter << endl;
	cout << "Расстояние от точки А до точки В: " << A.distanse(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки А до точки В: " << B.distanse(A) << endl;
	cout << delimiter << endl;

	cout << "Расстояние между точками A и B: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A;	//Default constructor
	A.print();

	Point B = 5;
	B.print();

	Point C(3, 5);
	C.print();

	Point D = C;  //Copy constructor
	D.print();

	Point E;	//Assignment operator
	E = D;
	E.print();

#endif // DEBUG
#ifdef ASSIGNMENT_OPERATOR
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_OPERATOR

}

double distance(Point& A, Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}