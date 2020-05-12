#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imag;
public:
    Complex();
    Complex(double r, double i);
    friend Complex operator +(Complex a, Complex b);
    friend Complex operator -(Complex c, Complex d);
    friend Complex operator +(Complex a, double b);
    friend Complex operator -(Complex c, double d);
    friend Complex operator +(double a, Complex b);
    friend Complex operator -(double c, Complex d);
    void print();
};
Complex::Complex() {
    real = 0;
    imag = 0;
}
Complex::Complex(double r, double i) {
    real = r;
    imag = i;
}
Complex operator +(Complex a,Complex b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}
Complex operator -(Complex c, Complex d) {
    return Complex(c.real - d.real, c.imag - d.imag);
}
Complex operator +(Complex a, double b) {
    return Complex(a.real + b, a.imag);
}
Complex operator -(Complex c, double d) {
    return Complex(c.real - d, c.imag);
}
Complex operator +(double a, Complex b) {
    return Complex(a + b.real, b.imag);
}
Complex operator -(double c, Complex d) {
    return Complex(c - d.real, -d.imag);
}
void Complex::print() {
    cout << "(" << real << ")+(" << imag << "i)" << endl;
}

int  main()
{
    Complex  a(3, 4), b(1, -1), c;
    c = a + b;
    cout << "a+b=";
    c.print();
    cout << endl;
    c = a - b;
    cout << "a-b=";
    c.print();
    cout << endl;
    c = a + 100;
    cout << "a+100=";
    c.print();
    cout << endl;
    c = a - 2.5;
    cout << "a-2.5=";
    c.print();
    cout << endl;
    c = 100 + a;
    cout << "100+a=";
    c.print();
    cout << endl;
    c = 2.5 - a;
    cout << "2.5-a=";
    c.print();
    cout << endl;
    return  0;
}