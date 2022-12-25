#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int ArrayMin(int** ArrayTwo, int n) {
	srand(time(0));
	int min;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; ++j) {
			ArrayTwo[i][j] = rand() % 50;
			cout << setw(3) << ArrayTwo[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	min = ArrayTwo[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				if (ArrayTwo[i][j] < min) {
					min = ArrayTwo[i][j];
				}
			}
		}
	}
	return min;
}

int main() {
	const int n = 5;
	int** ArrayTwo = new int* [n];
	for (int i = 0; i < n; ++i) {
		ArrayTwo[i] = new int[n];
	}
	cout << ArrayMin((int**)ArrayTwo, n);
	delete[] ArrayTwo[n];
}
