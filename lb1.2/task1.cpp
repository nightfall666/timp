#include <iostream>
#include <time.h>

using namespace std;

int ArraySum(int* ArrayOne, int n) {
	srand(time(0));
	int sum = 0;
	for (int i = 0; i < n; i++) {
		ArrayOne[i] = (rand() % 100) - 50;
		cout << ArrayOne[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (ArrayOne[i] % 9 == 0 && ArrayOne[i] < 0) {
			sum += ArrayOne[i];
		}
	}
	return sum;
}

int main() {
	const int n = 10;
	int* ArrayOne = new int[n];
	cout << ArraySum(ArrayOne, n);
}
