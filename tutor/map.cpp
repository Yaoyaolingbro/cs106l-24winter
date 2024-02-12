// uniform initialization of map

#include <iostream>
#include <map>

using namespace std;

int main () {
    map<string, int> ages {
        {"Alice", 25},
        {"Bob", 30},
    };

    cout << "Alice's age:" << ages["Alice"] << endl;
    cout << "Bob's age:" << ages.at("Bob") << endl;
}