#include <iostream>
#include <fstream>

using namespace std;

int length(char* array) {
	int len = 0;
	while (array[len] != '\0') {
		len++;
	}
	return len;
}

char* to_lower(char* array) {
	int len = length(array);
	for (int i = 0; i < len; i++) {
		if (array[i] != ' ') {
			if (array[i] >= 'A' && array[i] <= 'Z') {
				array[i] += 'a' - 'A';
			}
		}
	}
	return array;
}

bool check(char* array) {
	to_lower(array);
	int len = length(array);
	for (int i = 0; i < len / 2; i++) {
		if (array[i] != array[len - i - 1]) {
			if (array[i] != ' ') {
				return false;
			}
		}
	}
	return true;
}


int main() {
	ifstream in("in.txt");
	ofstream out("out.txt");
	const int n = 255;
	char array[n];
	while (in.getline(array, n)) {
		in >> array;
		if (check(array)) {
			out << "yes";
		}
		if (!check(array)) {
			out << "no";
		}
	}
}
