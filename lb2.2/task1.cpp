#include <iostream>

using namespace std;

class Triangle
{
private:
	int a, b, c;
public:
	Triangle() : a(0), b(0), c(0) {}
	Triangle(int a, int b, int c) : a(a), b(b), c(c) {}
	void SetABC(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	void ShowInfo(string info) {
		cout << "Информация о треугольника: " << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "c = " << c << endl;
	}
	void Perim() {
		int p = a + b + c;
		cout << "Периметр: " << p << endl;
	}
	void Ploshad() {
		double p = (a + b + c) / 2.0;
		double s = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << "Площадь: " << s << endl;
	}
	bool exists() {
		return (((a + b) > c) && ((a + c) > b) && ((b + c) > a));
	}

	Triangle operator ++() {
		return Triangle(++a, ++b, ++c);
	}

	Triangle operator --() {
		return Triangle(--a, --b, --c);
	}

	Triangle operator *(int n) const {
		return Triangle(a * n, b * n, c * n);
	}
};

int main() {
	setlocale(LC_ALL, "RUS");
	Triangle deltaA;
	deltaA.SetABC(3, 4, 5);
	deltaA.ShowInfo("A");
	deltaA.Ploshad();
	deltaA.Perim();
	--deltaA;
	deltaA.ShowInfo("A");
	cout << "------------------" << endl;
	Triangle deltaB(4, 5, 3);
	deltaB.ShowInfo("B");
	deltaB.Ploshad();
	deltaB.Perim();
	--deltaB;
	deltaB.ShowInfo("B");





}