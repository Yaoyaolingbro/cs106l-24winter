// example for pair in STL

#include <iostream>
#include <string>
#include <queue>

// make_pair is a function that creates a pair object
std::pair <bool, int> cost (bool a, int cost) {
    if (cost < 0) {
        return std::make_pair(false, 0);
    }
    return std::make_pair(true, cost);
}

void shift(std::vector<std::pair<int, int>> nums) {
    for (auto [num1, num2]: nums) {
        num1++;
        num2++;
    }

    for (auto& [num1, num2]: nums) {
        num1++;
        num2++;
    }
}

int main () {
    std::pair <std::string, int> foo;
    std::pair <std::string, int> bar;

    foo = std::make_pair("apple", 10);
    bar = std::make_pair("orange", 20);

    std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
    
    // use auto could be more convenient
    auto result = cost(true, -10);
    std::cout << "pair first: " << result.first << " pair next: " << result.second << std::endl;

    // vector of pair and test the function with reference and copy
    std::vector<std::pair<int, int>> nums = {
        {1,2},
        {2,3}
    };
    shift(nums);
    for (auto [num1, num2]: nums) {
        std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;
    }


    return 0;
}