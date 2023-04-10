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
	x ^= y; // ��������� ������������ ����������� ���. ���������� 1 ����� �������� ���� ��������������. ���� �������� ��������� ��������� - ���������� 0.
	cout << "x = " << bitset<sizeof(x) * 1>(x) << t << "y = " << bitset<sizeof(y) * 1>(y) << endl;
	cout << "x = " << x << "\t" << t <<  "y = " << y << endl;
	y ^= x;
	cout << "y = " << bitset<sizeof(y) * 1>(y) << t << "x = " << bitset<sizeof(x) * 1>(x) << endl;
	cout << "y = " << y << "\t" << t <<"x = " << x << endl;
	x ^= y;
	cout <<  "x = " << bitset<sizeof(x) * 1>(x) << t << bitset<sizeof(y) * 1>(y) << endl;
	cout <<  "x = " << x << "\t" << t << "y = " << y << endl << endl;

	x <<= 1;// �������� ���� �� 1 ��� ����� (���� 101 ����� 1010) = ��������� � ����� ������ 0. ����� ������ �������� ��� ��������� �� 2
	cout << "x << 1 = " << bitset<sizeof(x) * 1>(x) <<  endl;
	cout << x << endl;
	x >>= 1; // �������� ���� �� 1 ��� ������, ������ ��������� ��� (���� 1011 ����� 101).  ���� � ����� ��� 0 = ����� �� 2.
	cout << "x >> 1 = " << bitset<sizeof(x) * 1>(x) <<  endl;
	cout << x << endl << endl;
	int z = x & y; // ��������� � - ���� ��� ���� ����� 1 = ������������ 1
	cout << "x & y = " <<bitset<sizeof(x) * 1>(x) << t << bitset<sizeof(y) * 1>(y) << endl;
	cout << "z = " << bitset<sizeof(z) * 1>(z) <<  t << z << endl;
	z = x | y; // ��������� ��� - ���������� ���� ���� 1 ��� ������ 1  = ������������ 1
	cout << "x | y = " <<bitset<sizeof(x) * 1>(x) << t << bitset<sizeof(y) * 1>(y) << endl;
	cout << "z = " << bitset<sizeof(z) * 1>(z) << t << z << endl;

}
