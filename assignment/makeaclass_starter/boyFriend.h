#include <iostream>
#include <string>

using namespace std;

class boyFriend {
    private:
        string name;
        int age;
        double height;
        bool state;
    public:
        boyFriend(string name, int age, double height, bool isSingle);
        string getName();
        bool isSingle();
};