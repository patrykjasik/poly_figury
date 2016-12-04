#include<iostream>

using namespace std;

class figure {
public:
	virtual	void print() {
		cout << "Wyswietlam figure\n";
	}
};

class triangle: public figure {
public:
	void print() {
		cout << "Wyswietlam trojkat\n";
	}
};

class rectangle: public figure {
public:
//	virtual
	void print() {
		cout << "Wyswietlam prostokat\n";
	}
};

class square : public rectangle {
public:
	void print() {
		cout << "Wyswietlam kwadrat\n";
	}
};

void painter(figure);
void super_painter(figure&);


int main() {
	figure my_figure;
	triangle my_triangle;
	rectangle my_rectangle;
	square my_square;

	my_figure.print();
	my_triangle.print();
	my_rectangle.print();
	my_square.print();

	cout << "==================\n";

	figure *po_figure;
//	rectangle *test;

	po_figure = &my_figure;
	po_figure->print();

	po_figure = &my_triangle;
	po_figure->print();

	po_figure = &my_rectangle;
	po_figure->print();

	po_figure = &my_square;
	po_figure->print();

//	test = &my_square;
//	test->print();

	cout << "==================\n";
	painter(my_figure);
	painter(my_triangle);
	painter(my_rectangle);
	painter(my_square);

	cout << "==================\n";
	super_painter(my_figure);
	super_painter(my_triangle);
	super_painter(my_rectangle);
	super_painter(my_square);

	system("pause");
	return 0;
}

void painter(figure fi) {
	fi.print();
}

void super_painter(figure &fi) {
	fi.print();
}