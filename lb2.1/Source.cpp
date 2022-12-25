#include <iostream>

using namespace std;

void lunatics(int i) {
    cout << i << " лунатиков жили на луне" << endl;
    cout << i << " лунатиков ворочались во сне" << endl;
    cout << "Один из лунатиков упал с луны во сне" << endl;
    i--;
    if (i != 0) {
        cout << i << " лунатиков осталось на луне" << endl;
        lunatics(i);
    }
    if (i == 0) {
        cout << "И больше лунатиков не стало на луне" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    int i;
    cin >> i;
    lunatics(i);
}
