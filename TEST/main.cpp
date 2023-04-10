#include<iostream>
#include<bitset>
#define t "\t"
using namespace std;

void main()
{
	setlocale(LC_ALL, "");

	int x = 3;
	int y = 5;
	cout << "x = " << bitset<sizeof(x) * 1>(x) << t << "y = " << bitset<sizeof(y) * 1>(y) << endl;
	cout << "x = " << x << "\t" << t <<"y = " << y << endl;
	x ^= y; // побитовое присваивание исключающее ИЛИ. Возвращает 1 когда значение бито противоположны. Если значение операндов одинаковы - возвращает 0.
	cout << "x = " << bitset<sizeof(x) * 1>(x) << t << "y = " << bitset<sizeof(y) * 1>(y) << endl;
	cout << "x = " << x << "\t" << t <<  "y = " << y << endl;
	y ^= x;
	cout << "y = " << bitset<sizeof(y) * 1>(y) << t << "x = " << bitset<sizeof(x) * 1>(x) << endl;
	cout << "y = " << y << "\t" << t <<"x = " << x << endl;
	x ^= y;
	cout <<  "x = " << bitset<sizeof(x) * 1>(x) << t << bitset<sizeof(y) * 1>(y) << endl;
	cout <<  "x = " << x << "\t" << t << "y = " << y << endl << endl;

	x <<= 1;// сдвигает биты на 1 бит влево (было 101 стало 1010) = добовляет в конец всегда 0. ПОЧТИ ВСЕГДА РАБОТАЕТ КАК УМНОЖЕНИЕ НА 2
	cout << "x << 1 = " << bitset<sizeof(x) * 1>(x) <<  endl;
	cout << x << endl;
	x >>= 1; // сдвигает биты на 1 бит вправо, уберая последний бит (было 1011 стало 101).  Если в конце был 0 = делит на 2.
	cout << "x >> 1 = " << bitset<sizeof(x) * 1>(x) <<  endl;
	cout << x << endl << endl;
	int z = x & y; // побитовое И - если оба бита равны 1 = возвращается 1
	cout << "x & y = " <<bitset<sizeof(x) * 1>(x) << t << bitset<sizeof(y) * 1>(y) << endl;
	cout << "z = " << bitset<sizeof(z) * 1>(z) <<  t << z << endl;
	z = x | y; // побитовое ИЛИ - фактически если хоть 1 бит равень 1  = возвращается 1
	cout << "x | y = " <<bitset<sizeof(x) * 1>(x) << t << bitset<sizeof(y) * 1>(y) << endl;
	cout << "z = " << bitset<sizeof(z) * 1>(z) << t << z << endl;

}
