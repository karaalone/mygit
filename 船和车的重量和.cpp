#include  <iostream>
using  namespace  std;

class Car;
class Boat
{
    public:
        friend int totalweight(Boat& b, Car& c);
        Boat(int b);   
    private:
        int weight;
};
Boat::Boat(int b) {
    weight = b;
}
class Car
{
    public:
        Car(int c);
        friend int totalweight(Boat& b, Car& c);
    private:
        int weight;
};
Car::Car(int c) {
    weight = c;
}
int  totalweight(Boat& b, Car& c)
{
    return  b.weight + c.weight;
}
int  main()
{
    Boat  b(100);
    Car  c(200);
    cout << totalweight(b, c) << endl;
    return  0;
}