#include <iostream>
#include <iomanip>
using namespace std;

typedef int elementType;
typedef struct node
{
    elementType data;
    node* next;
} LList, * PList;
template<typename T>
class linkedList
{
public:
    linkedList();//构造函数
    virtual ~linkedList();//析构函数，注意要链表中所有节点的资源
    void insert(T value);//警告：必须初始化才能使用！
    bool initiate();//初始化单链表，使用new操作创建头结点。如果创建失败，则返回false，否则返回true
    bool isEmpty();//判断单链表是否为空
    //删除单链表中第pos个元素结点，并将删除的节点的值存在value中。
    //注意：如果链表为空、删除位置大于链表长度、以及删除位置为0的情况，需要终止删除并输出相应信息
    bool remove(T pos, T& value);
    void print();//顺序打印单链表，如果是单链表为空，则输出 Empty
    int Length();//返回单链表长度。如果是单链表为空，则返回-1
private:
    LList* head;
    int len;
};
template<typename T>
linkedList<T>::linkedList() {
    head = new LList;
    head->data = 0;
    head->next = NULL;
    len = 0;
}
template<typename T>
linkedList<T>::~linkedList() {
    delete head;
}
template<typename T>
void linkedList<T>::insert(T value) {
    PList p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    PList pnew = new LList;
    pnew->data = value;
    pnew->next = p->next;
    p->next = pnew;
}
template<typename T>
bool linkedList<T>::initiate() {
    head = new LList;
    head->data = 0;
    head->next = NULL;
    if (head != NULL)
        return true;
    else
        return false;
}
template<typename T>
bool linkedList<T>::isEmpty() {
    if (head == NULL) {
        return true;
    }
    else return false;
}
template<typename T>
bool linkedList<T>::remove(T pos, T& value) {
    if (pos > len)
    {
        cout << "pos > len, failed" << endl;
        return false;
    }
    else if (pos == 0 || head->next == NULL)
    {
        cout << "pos <= 0, failed" << endl;
        return false;
    }
    LList* p = head->next;
    LList* q = head;
    while (p != NULL) {
        if (p->data == pos) {
            q->next = p->next;
            value = p->data;
            free(p);
            return true;
        }
        else {
            q = p;
            p = p->next;
        }
    }
    return false;
}
template<typename T>
int linkedList<T>::Length() {
    if (isEmpty()) return -1;
    LList* p = head->next;
    len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}
template<typename T>
void linkedList<T>::print()
{
    if (isEmpty())
    {
        cout << "Empty" << endl;
        return;
    }
    LList* tmp = head->next;
    while (tmp)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}



int main(int argc, char* argv[])
{
    linkedList<int> L1;
    int n;
    int val;
    //初始化链表
    if (!L1.initiate())
        return 0;

    cin >> n;//输入链表中数据个数
    for (int i = 0; i < n; i++) //输入n个数，并插入链表
    {
        cin >> val;
        L1.insert(val);
    }
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度
    cout << "data：";
    L1.print();//打印链表

    cin >> n;//输入需要删除的数据的位置
    if (L1.remove(n, val))
    {
        //删除位置n的数据，并将删除的数据值放在val中
        cout << "Delete the data at position(" << n << "):" << val << endl;
        cout << "New Length：" << L1.Length() << endl;//输出链表长度
        cout << "data：";
        L1.print();//打印链表
    }

    return 0;
}