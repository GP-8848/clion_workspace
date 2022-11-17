//
// Created by V5 on 2022/11/17.
//
#include <iostream>

using namespace std;

class A {
public:
    A(int a) : _a(a) {}

    operator bool() {
        cout << "operator bool" << endl;
        return _a;
    }

    bool operator==(const bool &other) {
        cout << "bool operator==(const bool &rhs)" << endl;
        return (bool) _a == other;
    }

    bool operator==(const A &other) {
        cout << " bool operator==(const A&other)" << endl;
        return this->_a == other._a;
    }

private:
    int _a;
};

int main() {
    /**
     * operator bool () 提供一个本类型到bool的隐式转换，不允许使用参数。
     * bool operator ==()有以下两种：
     * bool operator ==( const bool& other)          --------与bool类型的比较
     * bool operator ==( const T& other),T代表类型。  --------与本类的比较
     */

    A a(0);
    A b(10);
    A c(10);
    /**
     * 在判断 if(a) 和 if(a == b) 时，先把a、b分别转换为bool类型再进行判断。
     */
    if (a)
        cout << "a" << endl;
    if(a == b)
        cout<<"asdasddsa"<<endl;
    cout << "finish" << endl;

    if (a == true)
        cout << "a == true" << endl;
    if (b == c)
        cout << "b == c" << endl;
    getchar();
    cout << "finish" << endl;
    return 0;
}