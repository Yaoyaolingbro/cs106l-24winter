// 重载运算符示例
#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    // 重载加法运算符
    Complex operator+(const Complex& other) const{
        return Complex(real + other.real, imag + other.imag);
    }

    // 打印复数
    void print() {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    Complex c1(2.0, 3.0);
    Complex c2(1.0, 4.0);

    Complex result = c1 + c2; // 使用重载的加法运算符

    result.print(); // 输出结果
    return 0;
}
