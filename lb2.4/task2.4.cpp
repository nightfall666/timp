#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Mystring : public string
{
public:
    using string::string;
    bool istitle();
    void capitalize();
    void zfill(int width);
};

bool Mystring::istitle()
{
    int len = this->size();
    for (int i = 0; i < len; i++) {
        if ((*this)[0] >= 'A' && (*this)[0] <= 'Z') {
            return false;
        }
    }
    return true;
};

void Mystring::capitalize()
{
    int len = this->size();
    for (int i = 0; i < len; i++) {
        if ((*this)[0] >= 'a' && (*this)[0] <= 'z') {
            (*this)[0] += 'A' - 'a';
        }
        if ((*this)[i] >= 'A' && (*this)[i] <= 'Z') {
            (*this)[i] += 'a' - 'A';
        }
    }
    cout << (*this);
}

void Mystring::zfill(int width)
{
    int len = this->size();
    for (int i = 0; i < width - len; i++) {
        if (width > len) {
            (*this).insert(i, "0");

        }
    }
    cout << *this;
}




int main() {
    Mystring m1("qwERty");
    cout << m1.istitle() << endl;
    m1.capitalize();
    cout << endl;
    m1.zfill(14);
}