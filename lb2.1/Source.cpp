#include <iostream>

using namespace std;

void lunatics(int i) {
    cout << i << " ��������� ���� �� ����" << endl;
    cout << i << " ��������� ���������� �� ���" << endl;
    cout << "���� �� ��������� ���� � ���� �� ���" << endl;
    i--;
    if (i != 0) {
        cout << i << " ��������� �������� �� ����" << endl;
        lunatics(i);
    }
    if (i == 0) {
        cout << "� ������ ��������� �� ����� �� ����" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    int i;
    cin >> i;
    lunatics(i);
}
