// function template
#include <iostream>
#include<typeinfo>
using namespace std;

template <class T> class Point {
	T x, y;
public:
	Point():x(0),y(0){}
	Point(T a, T b):x(a),y(b){}
	T getX() { return x; }
	T getY() { return y; }

	bool operator > (Point &a) {
		if (x > a.getX() && y > a.getY()) {
			cout << "prawda\n";
			return 1;
		}
		else {
			cout << "falsz\n";
			return 0;
		}
	}

	Point operator + (Point &a) {
		Point result(x + a.getX(), y + a.getY());
		return result;
	}
};


template <class ala_ma_kota>
ala_ma_kota GetMax(ala_ma_kota a, ala_ma_kota b) {
	ala_ma_kota result;
	result = (a>b) ? a : b;
//	cout << result << endl;
		return result;
}

int main() {
	int i = 5, j = 6, k;
	long l = 10, m = 5, n;
	char z = 'a', c = 'g', o;

	Point<int> p1(3, 6), p2(4, 7), p, q;

//	p1.operator>(p2)

///	GetMax(j, i);
	
	k = GetMax<int>(i, j);
	n = GetMax<float>(l, m);
	o = GetMax<char>(z, c);

	p = GetMax<Point<int>>(p2, p1);

	cout << k << endl;
	cout << n << endl;
	cout << o << endl;

	cout << typeid(GetMax(4.4f, 4.6f)).name() << endl;
	
	cout << p.getX() << "," << p.getY() << endl;

	p = p1 + p2;
	cout << p.getX() << "," << p.getY() << endl;

	system("pause");
	return 0;
}
