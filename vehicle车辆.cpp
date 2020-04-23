#include  "iostream"
using  namespace  std;

class vehicle
{
private:
    int maxspeed;
    int weight;
public:
    vehicle();
    vehicle(int m, int w);
    ~vehicle();
    void run();
    void stop();
};
vehicle::vehicle() {
    maxspeed = 0;
    weight = 0;
}
vehicle::vehicle(int m, int w) {
    maxspeed = m;
    weight = w;
    cout << "vehicle constructor called. maxspeed:" << maxspeed << "; weight" << weight << endl;
}
void vehicle::run() {
    cout << "vehicle run" << endl;
}
void vehicle::stop() {
    cout << "vehicle stop" << endl;
}
vehicle::~vehicle() {
    cout << "vehicle destructor called. maxspeed:" << maxspeed << "; weight" << weight << endl;
}
class bicycle :virtual public vehicle
{
private:
    int height;
public:
    bicycle();
    bicycle(int h);
    ~bicycle();

};
bicycle::bicycle() {
    height = 0;
}
bicycle::bicycle(int h) {
    height = h;
    cout << "bicycle constructor called. height:" << height << endl;
}
bicycle::~bicycle() {
    cout << "bicycle destructor called. height:" << height << endl;
}
class  motorcar :virtual public vehicle
{
private:
    int  seatnum;
public:
    motorcar();
    motorcar(int s);
    ~motorcar();
};
motorcar::motorcar() {
    seatnum = 0;
}
motorcar::motorcar(int s) {
    seatnum = s;
    cout << "motorcar constructor called. setnum:" << seatnum << endl;
}
motorcar::~motorcar() {
    cout << "motorcar destructor called. setnum:" << seatnum << endl;
}

class motorcycle :public bicycle, public motorcar
{
public:
    motorcycle();
    motorcycle(int h, int s, int m, int w);
    ~motorcycle();
};
motorcycle::motorcycle(int h, int s, int m, int w) :vehicle(m, w), bicycle(h), motorcar(s) {
    cout << "motorcycle constructor called" << endl;
}
motorcycle::~motorcycle() {
    cout << "motorcycle destructor called" << endl;
}
int  main(int  argc, char* argv[])
{
    motorcycle  m(1, 2, 3, 4);//1表示height，2表示setnum，3表示maxspeed，4表示weight
    m.run();
    m.stop();
    return  0;
}