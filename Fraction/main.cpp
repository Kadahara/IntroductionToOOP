#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;	//целое число
	int numerator;	//числитель
	int denominator;//знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//				Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	/*explicit*/ Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}

		Fraction(double decimal)
		{
			decimal += 1e-10;
			integer = decimal;	//Сохраняем целую часть десятичной дроби
			decimal -= integer;	//Убираем целую часть из десятичной дроби
			denominator = 1e+9;	//Записываем максиммально возможный знаменатель
			numerator = decimal * denominator;//Всю дробную часть десятичной дроби загружаем в числитель
			reduce();
			cout << "1ArgConstructor:\t" << this << endl;
		}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operator:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}


	//				Methods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		//https://legacy.cplusplus.com/doc/tutorial/operators/#:~:text=Bitwise%20operators%20(%20%26%2C%20%7C%2C%20%5E%2C%20~%2C%20%3C%3C%2C%20%3E%3E%20)
		//https://legacy.cplusplus.com/doc/tutorial/operators/#:~:text=Compound%20assignment%20(%2B%3D%2C%20%2D%3D%2C%20*%3D%2C%20/%3D%2C%20%25%3D%2C%20%3E%3E%3D%2C%20%3C%3C%3D%2C%20%26%3D%2C%20%5E%3D%2C%20%7C%3D)
		//RAID-5
		inverted.numerator ^= inverted.denominator;
		inverted.denominator ^= inverted.numerator;
		inverted.numerator ^= inverted.denominator;
		return inverted;
	}
	Fraction& reduce()
	{
		to_proper();
		int more, less, rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			more = denominator;
			less = numerator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
	Fraction operator+=(const Fraction& other)
	{
		return *this = *this + other;     //a += b   a = a + b
	}	
	Fraction operator*=(const Fraction& other)
	{
		return *this = *this * other;     //a += b   a = a + b
	}
	Fraction operator-=(const Fraction& other)
	{
		return *this = *this - other;     //a += b   a = a + b
	}
	Fraction operator/=(const Fraction& other)
	{
		return *this = *this / other;     //a += b   a = a + b
	}
	//				Invcrement/Decrement
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int) //Po
	{
		Fraction old = *this;
		integer++;
		return old;
	}

//			Type-cast operators;
	explicit operator int()
	{
		return integer;
	
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction product;
	product.set_numerator(left.get_numerator()*right.get_numerator());
	product.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction product
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	product.to_proper();
	return product;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper(). reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_denominator(),
		right.get_numerator()*left.get_denominator()
	).to_proper();*/
	return left * right.inverted();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction product;
	product.set_denominator(left.get_denominator() * right.get_denominator());
	product.set_numerator((left.get_denominator() * right.get_numerator()) + (right.get_denominator() * left.get_numerator()));
	product.to_proper() .reduce();
	return product;

	//return Fraction
	//(
	//	left.get_denominator() * right.get_denominator(), left.get_denominator() * right.get_numerator(), 
	//	right.get_denominator() * left.get_denominator(), right.get_denominator() * left.get_numerator(),
	//	left.numerator() + right.get_numerator()
	//).to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction product;
	product.set_denominator(left.get_denominator() * right.get_denominator());
	product.set_numerator((right.get_denominator() * left.get_numerator()) - (left.get_denominator() * right.get_numerator()));
	product.to_proper().reduce();
	return product;
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
//bool operator!=(Fraction left, Fraction right)
//{
//	left.to_improper();
//	right.to_improper();
//	return left.get_numerator() * right.get_denominator() != right.get_numerator() * left.get_denominator();
//}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
//}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return (left > right);
	//return left < right || left == right;
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return (left < right);
	//return left > right || left == right;
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)cout << 0;
	return os;

}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	const int SIZE = 256;
	char buffer[SIZE] = {};
	//is >> buffer;
	is.getline(buffer, SIZE);
	const char delimiters[] = "( /)";
	int number[3] = {}; // cдесь будут храниться числа, введенные с клавиатуры
	int n = 0; // счетчик чисел
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		//pch хранит адрес начало токина
		//в функцию strtok() только первый раз передается делима строка, при всех последующих
		//вызовах на место делимой строки нужно передавать NULL.
		//Это показывает функции strtok() что она работает с ранее переданой строкой.
		//если делимую строку передать еще раз, то strtok() начнет обрабатывать ее с начало.
		number[n++] = atoi(pch);
		//atoi() - ASCII - string To Integer (эта функция преобразует строку в значение типа int)
 	}
	obj = Fraction();
	switch (n)
	{
	case 1:obj.set_integer(number[0]); break;
	case 2:
		obj.set_numerator(number[0]);
		obj.set_denominator(number[1]);
		break;
	case 3:
		obj.set_integer(number[0]);
		obj.set_numerator(number[1]);
		obj.set_denominator(number[2]);
	}
	return is;
}
//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define CONVERSIONS_FROM_OTHER_TYPES_TO_CLASS
//#define ISTREAM_OPERATOR_CHECK
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER


void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 3;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	A = E;
	A.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print();

	A.print();
	B.print();

	Fraction E = A + B;
	E.print();

	A.print();
	B.print();

	Fraction F = A - B;
	F.print();

	A.print();
	B.print();

	A += B;
	A.print();
	A -= B;
	A.print();

	for (Fraction i(3, 4); i.get_integer() < 10; i++)
	{
		i.print();
	}
#endif // ARITHMETICAL_OPERATORS_CHECK
#ifdef CONVERSIONS_FROM_OTHER_TYPES_TO_CLASS
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	(A == B) ? cout << "Дроби равны" << endl : cout << "Дроби не равны" << endl;
	cout << A << "\t" << B << endl;
	(A > B) ? cout << "Первая дробь больше" << endl : cout << "Вторая дробь больше" << endl;
	cout << A << "\t" << B << endl;
	(A <= B) ? cout << "Первая дробь больше или равна второй" << endl : cout << "Первая дробь меньше и не равна второй" << endl;
	cout << A << "\t" << B << endl;
#endif // CONVERSIONS_FROM_OTHER_TYPES_TO_CLASS
#ifdef ISTREAM_OPERATOR_CHECK
	Fraction A(123, 32, 45);
	cout << "Введите простую дробь: "; cin >> A;
	A.to_proper();
	cout << A << endl;

	int x = -312;
	cout << x << endl;
	int y = ~x + 1;
	cout << y << endl;
#endif // ISTREAM_OPERATOR_CHECK
#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	int a = 2;     //No conversion
	double b = 3;  //conversion from less to more
	int c = b;     //conversion from more to less without data loss
	int d = 2.5;   //Conversion from more to less with data loss

	Fraction A = (Fraction)5;		//Conversion from other to class
	cout << A << endl;
	Fraction B;			//Default constructor
	B = Fraction(8);				//Conversion from other to Class produced by assignment operator
	cout << B << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS
#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	Fraction A(2, 3, 4);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;
	double b = (double)A;
	cout << b << endl;


#endif // CONVERSION_FROM_CLASS_TO_OTHER
	Fraction A = 22.86;
	cout << A << endl;

}