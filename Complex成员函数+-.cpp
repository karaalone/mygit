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
    Complex operator +(Complex b);
    Complex operator -(Complex c);
    Complex operator +(double b);
    Complex operator -(double c);
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
Complex Complex::operator+(Complex b) {
    Complex a;
    a.real = b.real + real;
    a.imag = b.imag + imag;
    return Complex(a.real, a.imag);
}
Complex Complex::operator-(Complex c) {
    Complex a;
    a.real = real - c.real;
    a.imag = imag - c.imag;
    return Complex(a.real, a.imag);
}
Complex Complex::operator+(double b) {
    Complex a;
    a.real = b + real;
    a.imag = imag;
    return Complex(a.real, a.imag);
}
Complex Complex::operator-(double c) {
    Complex a;
    a.real = real - c;
    a.imag = imag;
    return Complex(a.real, a.imag);
}
void Complex::print() {
    cout << real << "+" << imag << "i" << endl;
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
    return  0;
}
