#include  <iostream>
#include  <string>
using  namespace  std;

class  CStudent
{
    public:
        static int count;
        CStudent();
        CStudent(const char n[4],int a);
        ~CStudent();
        static int getcount();
        void printname();
    private:
        int age;
        const char *name;
};
CStudent::CStudent() {
    age = 0;
    name = NULL;
    count++;
    if (name == NULL) {
        cout << "noname is contructing" << endl;
    }
    else cout << name << " is constructing" << endl;

}
CStudent::CStudent(const char n[4], int a) {
    count++;
    name = n;
    age = a;
    if (name == NULL) {
        cout << "noname is contructing" << endl;
    }
    else cout << name << " is contructing" << endl;
}
int CStudent::getcount() {
    return count;
}
void CStudent::printname() {
    if (name == NULL) {
        cout << "name:noname" << endl;
    }
    else cout << "name:" << name << endl;
}
CStudent::~CStudent() {
    count--;
    if (name == NULL) {
        cout << "noname is destructing" << endl;
    }
    else cout << name << " is destructing" << endl;
}
int CStudent::count = 0;

int  main()
{
    cout << "现在有学生" << CStudent::getcount() << endl;
    {
        CStudent  stuB[5];
        stuB[4].printname();
        cout << "现在有学生" << CStudent::getcount() << endl;
    }
    cout << "现在有学生" << CStudent::getcount() << endl;
    {
        CStudent  stuA[2] = { CStudent("Tom",  3),  CStudent("Jerry",  2) };
        for (int i = 0; i < 2; i++)
        {
            stuA[i].printname();
        }
        cout << "现在有学生" << CStudent::getcount() << endl;
    }
    cout << "现在有学生" << CStudent::getcount() << endl;

    return 0;
}
