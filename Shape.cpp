#include  <iostream>
using  namespace  std;
const  int pi = 3.14159;

class Shape
{
private:
    int m_ID;
public:
    Shape();
    Shape(int i);
    ~Shape();
    int getID();
    void setID(int i);
    int getArea();
};
Shape::Shape() {
    m_ID = 0;
}
Shape::Shape(int i) {
    m_ID = i;
    cout << "Shape constructor called:" << m_ID << endl;
}
int Shape::getID() {
    return m_ID;
}
void Shape::setID(int i) {
    m_ID = i;
}
int Shape::getArea() {
    return 0;
}
Shape::~Shape() {
    cout << "Shape destructor called:" << m_ID << endl;
}
class Circle:virtual public Shape
{
private:
    int r;
public:
    Circle();
    Circle(int id);
    Circle(int radius, int i);
    ~Circle();
    int getRadius();
    void setRadius(int radius);
    int getArea();
};
Circle::Circle() {
    r = 0;
}
Circle::Circle(int id) {
    r = 0;
    setID(id);
    cout << "Circle constructor called:" << getID() << endl;
}
Circle::Circle(int radius, int i) :Shape(i), r(radius) {
    cout << "Circle constructor called:" << getID() << endl;
}
int Circle::getRadius() {
    return r;
}
void Circle::setRadius(int radius) {
    r = radius;
}
int Circle::getArea() {
    return (int)pi * r * r;
}
Circle::~Circle() {
    cout << "Circle destructor called:" << getID() << endl;
}
class Rectangle:virtual public Shape
{
private:
    int h;
    int w;
public:
    Rectangle(int height, int width, int ID);
    ~Rectangle();
    int getHeight();
    void setHeight(int height);
    int getWidth();
    void setWidth(int width);
    int getArea();
};
Rectangle::Rectangle(int height, int width, int ID) :Shape(ID), h(height), w(width) {
    cout << "Rectangle constructor called:" << getID() << endl;
}
int Rectangle::getHeight() {
    return h;
}
void Rectangle::setHeight(int height) {
    h = height;
}
int Rectangle::getWidth() {
    return w;
}
void Rectangle::setWidth(int width) {
    w = width;
}
int Rectangle::getArea() {
    return h * w;
}
Rectangle::~Rectangle() {
    cout << "Rectangle destructor called:" << getID() << endl;
}
int  main()
{
    Shape  s(1);//1表示ID
    Circle  c(4, 2);//4表示半径，2表示ID
    Rectangle  r(4, 5, 3);//4和5表示长和宽，3表示ID
    cout << "Shape的面积" << s.getArea() << endl;
    cout << "Circle的面积" << c.getArea() << endl;
    cout << "Rectangle的面积" << r.getArea() << endl;
}