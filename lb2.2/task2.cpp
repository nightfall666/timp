#include <iostream>

using namespace std;

class Figure
{
public:
	virtual void Show() = 0;
	virtual double Ploshad() = 0;
	virtual double Perim() = 0;
};
class Restangle : public Figure
{
protected:
	int x;
	int y;
public:
	Restangle() : x(0), y(0) {};
	Restangle(int x, int y) : x(x), y(y) {};
	void Show() {
		cout << ": со сторонами " << x << ", " << y << endl;
	}
	double Ploshad() {
		int S = x * y;
		return S;
	}
	double Perim() {
		int P = 2 * (x + y);
		return P;
	}
	int GetX() { return x; }
	int GetY() { return y; }
};
class Circle : public Figure
{
protected:
	int radius;
public:
	Circle() : radius(0) {};
	Circle(int radius) : radius(radius) {};
	void Show() {
		cout << ": с радиусом " << radius << endl;
	}
	double Ploshad() {
		double Pi = 3.14;
		double S = Pi * (radius ^ 2);
		return S;
	}
	double Perim() {
		double Pi = 3.14;
		double P = 2 * Pi * radius;
		return P;
	}
	int GetR() { return radius; }
};
class Triangle : public Figure
{
protected:
	double a;
	double b;
	double c;
public:
	Triangle() : a(0), b(0), c(0) {};
	Triangle(double a, double b, double c) : a(a), b(b), c(c) {};
	void Show() {
		cout << ": со сторонами " << a << ", " << b << ", " << c << endl;
	}
	double Perim() {
		double P = a + b + c;
		return P;
	}
	double Ploshad() {
		double P2 = (a + b + c) / 2;
		double P = sqrt(P2 * (P2 - a) * (P2 - b) * (P2 - c));
		return P;
	}
	double GetA() { return a; }
	double GetB() { return b; }
	double GetC() { return c; }
};

int main() {
	setlocale(LC_ALL, "RUS");
	Figure* array[2];
	array[0] = new Restangle(3, 5);
	array[1] = new Circle(6);
	array[2] = new Triangle(3, 4, 5);
	for (int i = 0; i <= 2; i++) {

		array[i]->Show();
		cout << "Периметр: " << array[i]->Perim() << endl;
		cout << "Площадь: " << array[i]->Ploshad() << endl;
	}
	for (int i = 0; i <= 2; i++) {
		delete array[i];
	}
}