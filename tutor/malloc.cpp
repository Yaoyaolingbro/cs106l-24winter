#include <iostream>

using namespace std;

int main (void) {
    string s="hello";
    string *ps=&s;
    // cout << (*ps).length() << endl;
    // cout << ps->length() << endl;

    int *p = new int;
    *p = 5;
    cout << "p = " << p <<  " *p = " << *p << endl;
    // 内存泄漏
    p = new int;
    *p = 6;
    cout << "p = " << p <<  " *p = " << *p << endl;
    delete p;
}