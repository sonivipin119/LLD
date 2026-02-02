// Operator overloading means giving an existing operator (+, -, *, etc.) a new meaning for user-defined data types (objects).
#include <iostream>
using namespace std;
class Complex {
public:
    int real, imag;

    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    Complex operator + (Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }
};

int main() {

  Complex a(2, 3), b(4, 5);
  Complex c = a + b;   // looks natural
  cout << "Result: " << c.real << " + " << c.imag << "i" << endl;
  return 0;
}
