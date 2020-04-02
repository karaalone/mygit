#include <iostream>
using namespace std;

class CPoint
{
    friend class CRectangle;
    public:
        CPoint();
        CPoint(int a, int b);
        CPoint(CPoint& m);
    private:
        int x, y;
};
CPoint::CPoint() {
    x = y = 0;
    cout << "CPoint contstructor with default value(0,0) is called." << endl;
}
CPoint::CPoint(int a, int b) {
    x = a;
    y = b;
    cout << "CPoint contstructor with default value(0,0) is called." << endl;
}
CPoint::CPoint(CPoint&t) {
    x = t.x;
    y = t.y;
    cout << "CPoint copy contstructor is called." << endl;
}
class CRectangle
{
    friend class CPoint;
    public:
        CRectangle();
        CRectangle(CPoint m, CPoint n);
        CRectangle(int a, int b, int c, int d);
        CRectangle(CRectangle& k);
        int GetArea();
    private:
        CPoint p1, p2;
};
CRectangle::CRectangle() {
    p1.x = p1.y = p2.x = p2.y = 0;
    cout << "CRectangle default contstructor is called." << endl;
}
CRectangle::CRectangle(CPoint m, CPoint n) :p1(m),p2(n){
    cout << "CRectangle contstructor with (CPoint,CPoint) is called." << endl;
}
CRectangle::CRectangle(int a, int b, int c, int d) {
    p1.x = a;
    p2.y = b;
    p2.x = c;
    p1.y = d;
    cout << "CRectangle contstructor with (int,int,int,int) is called." << endl;
}
CRectangle::CRectangle(CRectangle& k):p1(k.p1),p2(k.p2) {
    cout << "CRectangle copy contstructor is called." << endl;
}
int CRectangle::GetArea() {
    if ((p1.y - p2.y) * (p2.x - p1.x) < 0) {
        return -(p1.y - p2.y) * (p2.x - p1.x);
    }
    else return (p1.y - p2.y) * (p2.x - p1.x);
}
int main()
{
    int a = 1, b = 1, c = 6, d = 11;
    cout << "# Define p1 ######" << endl;
    CPoint p1;
    cout << "# Define p2 ######" << endl;
    CPoint p2(10, 20);
    cout << "# Define rect1 ######" << endl;
    CRectangle rect1;
    cout << "# Define rect2 ######" << endl;
    CRectangle rect2(p1, p2);
    cout << "# Define rect3 ######" << endl;
    CRectangle rect3(a, b, c, d);
    cout << "# Define rect4 ######" << endl;
    CRectangle rect4(rect2);
    cout << "# Calculate area ######" << endl;
    cout << "rect1面积为" << rect1.GetArea() << endl;
    cout << "rect2面积为" << rect2.GetArea() << endl;
    cout << "rect3面积为" << rect3.GetArea() << endl;
    cout << "rect4面积为" << rect4.GetArea() << endl;
    system("pause");
    return 0;
}