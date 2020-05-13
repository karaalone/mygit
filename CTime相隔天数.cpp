#include <iostream>
using namespace std;

class CTime
{
	private:
		int year, month, day, hour, minute, second;
	public:
		CTime(int y, int m, int d, int h=0, int min=0, int s=0);
		CTime(CTime& p);
		~CTime();
		int dayDiff(CTime t);
		void showTime();
        int isvalid();
        int leapYear(int y);
};
CTime::CTime(int y, int m, int d, int h, int min, int s)
{
    year = y;
    month = m;
    day = d;
    hour = h;
    minute = min;
    second = s;
    int a = 0;
    if ((leapYear(year) == 1 && month == 2 && day > 29) || (leapYear(year) == 2 && month == 2 && day > 28)
        || (month == 1 && day > 31) || (month == 3 && day > 31) || (month == 4 && day > 30) || (month == 5 && day > 31)
        || (month == 6 && day > 30) || (month == 7 && day > 31) || (month == 8 && day > 31) || (month == 9 && day > 30)
        || (month == 10 && day > 31) || (month == 11 && day > 30) || (month ==12 && day > 31)){
        a = 1;
        if (hour > 23 || minute > 59 || second > 59) {
            a = 4;
        }
    }
    else if (hour > 23 || minute > 59 || second > 59) {
        a = 2;
    }
    else a = 3;
    switch (a)
    {
    case 1: {
        cout << "date error!" << endl;
        year = month = day = hour = minute = second = 0;
    }; break;
    case 2: {
        cout << "time error!" << endl;
        year = month = day = hour = minute = second = 0;
    }; break;
    case 4: {
        cout << "date and time error!" << endl;
        year = month = day = hour = minute = second = 0;
    }; break;
    }
    cout << "构造函数被调用" << endl;
}
CTime::CTime(CTime& p)
{
    year = p.year;
    month = p.month;
    day = p.day;
    hour = p.hour;
    minute = p.minute;
    second = p.second;
    cout << "拷贝构造函数被调用" << endl;
}
int CTime::leapYear(int y)
{
    if (y % 4 == 0 && y % 100 != 0){
        return 1;
    }
    else if (y % 400 == 0){
        return 1;
    }
    else return 2;
}
int CTime::isvalid()
{
    if (year == 0) {
        return 0;
    }
    else return 1;
}
int CTime::dayDiff(CTime t)
{
    int y, y1=t.year, y2=year, m=0, m1=t.month, m2=month, d1=t.day, d2=day, k=0, n;
    if (t.year > year) {
        y1 = year;
        y2 = t.year;
        m1 = month;
        m2 = t.month;
        d1 = day;
        d2 = t.day;
    }
    else if (t.year == year) {
        if (t.month > month) {
            m1 = month;
            m2 = t.month;
            d1 = day;
            d2 = t.day;
        }
    }
    y = y2 - y1;
    k += y * 365;
    for (n = y1; n < y2; n++) {
        if (y > 0 && leapYear(n) == 1) {
            k++;
        }
    }
    if (m1 > m2) {
        for (m = m1; m <= (m2 + 12); m++) {
            if (leapYear(y2) == 1 && (m == 2 || m == 14)) {
                k++;
            }
        }
    }
    else {
        for (m = m1; m <= m2; m++) {
            if (leapYear(y2) == 1 && m == 2) {
                k++;
            }
        }
    }
    k += d2;
    while (m1 < m2)
    {
        if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7
            || m1 == 8 || m1 == 10 || m1 == 12) {
            k += 31;
            m1++;
        }
        else if (m1 == 2) {
            k += 28;
            m1++;
        }
        else {
            k += 30;
            m1++;
        }
    }
    k -= d1;
    return k;
}
void CTime::showTime()
{
    cout << year << '/' << month << '/' << day << " " << hour << ':' << minute << ':' << second << endl;
}
CTime::~CTime()
{
    cout << "析构函数被调用" << endl;
}
int  main()
{
    int  year, month, day, hour, minute, second;
    cin >> year >> month >> day >> hour >> minute >> second;
    CTime  t1(year, month, day, hour, minute, second);
    t1.showTime();
    CTime  t2(2000, 1, 1);  //利用默认形参将时间初始化为00:00:00
    if (t1.isvalid())          //如果日期和时间合法，则计算天数
    {
        int  days = 0;
        days = t1.dayDiff(t2);
        cout << "这两天之间相隔了" << days << "天" << endl;
        days = t2.dayDiff(t1);
        cout << "这两天之间相隔了" << days << "天" << endl;
    }
}