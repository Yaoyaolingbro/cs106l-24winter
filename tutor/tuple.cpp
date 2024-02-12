#include <iostream>
#include <tuple>
#include <string>

std::tuple<int, double,std::string> getInfo (){
    int first = 10;
    double second = 10.5;
    std::string sentence = "hello world";
    return {first, second, sentence};
}

int main() {
    // 创建一个包含三个元素的tuple，分别是int、double和string类型
    std::tuple<int, double, std::string> myTuple{10, 3.14, "Hello"};

    // 访问tuple中的元素
    std::cout << "First element: " << std::get<0>(myTuple) << std::endl;
    std::cout << "Second element: " << std::get<1>(myTuple) << std::endl;
    std::cout << "Third element: " << std::get<2>(myTuple) << std::endl;

    // 修改tuple中的元素
    std::get<0>(myTuple) = 20;
    std::get<2>(myTuple) = "World";

    // 使用结构化绑定（C++17）来解包tuple
    auto [first, second, third] = getInfo();
    std::cout << "Unpacked tuple: " << first << ", " << second << ", " << third << std::endl;

    return 0;
}
