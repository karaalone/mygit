#include <iostream>
#include  <vector>
using namespace std;

class Book
{
public:
    Book();
    virtual ~Book();
    Book(const Book& other);
    int GetID();
    string GetName();
    string GetIntrodection();
    string GetAuthor();
    string GetDate();
    int GetPage();
    void SetID(int id);
    void SetName(string name);
    void SetIntroduction(string introduction);
    void SetAuthor(string author);
    void SetDate(string date);
    void SetPage(int page);
private:
    unsigned int m_ID;//���
    string m_Name;//����
    string m_Introduction;//���
    string m_Author;//����
    string m_Date;//����
    unsigned int m_Page;//ҳ��
};
Book::Book() {
    m_ID = 0;
    m_Page = 0;
}
Book::Book(const Book& other) {
    m_ID = other.m_ID;
    m_Name = other.m_Name;
    m_Introduction = other.m_Introduction;
    m_Author = other.m_Author;
    m_Date = other.m_Date;
    m_Page = other.m_Page;
}
Book::~Book() {

}
int Book::GetID() {
    return m_ID;
}
string Book::GetName() {
    return m_Name;
}
string Book::GetIntrodection() {
    return m_Introduction;
}
string Book::GetAuthor() {
    return m_Author;
}
string Book::GetDate() {
    return m_Date;
}
int Book::GetPage() {
    return m_Page;
}
void Book::SetID(int id) {
    m_ID = id;
}
void Book::SetName(string name) {
    m_Name = name;
}
void Book::SetIntroduction(string introduction) {
    m_Introduction = introduction;
}
void Book::SetAuthor(string author) {
    m_Author = author;
}
void Book::SetDate(string date) {
    m_Date = date;
}
void Book::SetPage(int page) {
    m_Page = page;
}
class Store
{
public:
    unsigned int GetCount();
    Store();
    Store(int n);
    virtual ~Store();
    Store(const Store& other);
    void in(Book& b);
    void out(string name);
    Book findbyID(int ID);
    Book findbyName(string name);
    void printList();
private:
    vector<Book>m_Books;
};
unsigned int Store::GetCount() {
    return m_Books.size();
}
Store::Store() {
    cout << "Store default constructor called!" << endl;
}
Store::Store(int n) {
    vector<Book>m_pBook(n);
    cout << "Store constructor with(int n) called!" << endl;
}
Store::~Store() {
    cout << "Store destructor called!" << endl;
}
Store::Store(const Store& other) {
    cout << "Store copy constructor called!" << endl;
}
void Store::in(Book& b) {
    m_Books.push_back(b);
}
void Store::out(string name) {
    for (unsigned int i = 0; i < GetCount(); i++) {
        if (m_Books[i].GetName() == name) {
            m_Books.erase(m_Books.begin() + i);
        }
    }
}
Book Store::findbyID(int ID) {
    for (unsigned int i = 0; i < GetCount(); i++) {
        if (m_Books[i].GetID() == ID) {
            return m_Books[i];
        }
    }
    Book mm = Book();
    return mm;
}
Book Store::findbyName(string name) {
    for (unsigned int i = 0; i < GetCount(); i++) {
        if (m_Books[i].GetName() == name) {
            return m_Books[i];
        }
    }
    Book mm = Book();
    return mm;
}
void Store::printList() {
    cout << "There are totally " << GetCount() << " Books:" << endl;
    for (unsigned int i = 0; i < GetCount(); i++) {
        cout << "ID=" << m_Books[i].GetID() << ";  Name:" << m_Books[i].GetName()
            << ";  Author:" << m_Books[i].GetAuthor() << ";  Date:" << m_Books[i].GetDate() << ";" << endl;
    }

}

int  main()
{
    Store  s;
    Book  b1, b2, b3;
    b1.SetID(1);
    b1.SetName("C++  ���Գ������(��4��)");
    b1.SetAuthor("֣��");
    b1.SetIntroduction("����C++����������֪ʶ");
    b1.SetDate("201007");
    b1.SetPage(529);
    b2.SetID(2);
    b2.SetName("��ɢ��ѧ");
    b2.SetAuthor("��Т��");
    b2.SetIntroduction("���������߼���ν���߼��������ۡ�����ϵͳ��ͼ��");
    b2.SetDate("198209");
    b2.SetPage(305);
    b3.SetID(3);
    b3.SetName("c�������");
    b3.SetAuthor("̷��ǿ");
    b3.SetIntroduction("����C��������еĻ���֪ʶ��������ʽ���﷨��");
    b3.SetDate("201006");
    b3.SetPage(355);

    cout << "��һ�������" << endl;
    s.in(b1);
    cout << "�ڶ��������" << endl;
    s.in(b2);
    cout << "�����������" << endl;
    s.in(b3);
    cout << "���п���鼮������" << s.GetCount() << endl;
    cout << "���Ҳ�����ͼ�飺��ɢ��ѧ" << endl;
    Book  tmpbook = s.findbyName("��ɢ��ѧ");
    if (tmpbook.GetID() != 0)
    {
        s.out("��ɢ��ѧ");
        cout << "��ɢ��ѧ  �ѳɹ�����" << endl;
    }
    else
        cout << "û���ҵ�nameΪ��ɢ��ѧ����" << endl;
    cout << "���п���鼮������" << s.GetCount() << endl;

    cout << "����ͼ��  ID��3" << endl;
    tmpbook = s.findbyID(3);
    if (tmpbook.GetID() != 0)
        cout << "�ҵ�IDΪ" << 3 << "���飬������" << tmpbook.GetName() << endl;
    else
        cout << "û���ҵ�IDΪ" << 3 << "����" << endl;

    cout << "����ͼ��  name����ɢ��ѧ" << endl;
    tmpbook = s.findbyName("��ɢ��ѧ");
    if (tmpbook.GetID() != 0)
        cout << "�ҵ�nameΪ��ɢ��ѧ���飬ID��" << tmpbook.GetID() << endl;
    else
        cout << "û���ҵ�nameΪ��ɢ��ѧ����" << endl;

    cout << "������п��ͼ�����Ϣ" << endl;
    s.printList();
    cout << "�������н���" << endl;
    return  0;
}