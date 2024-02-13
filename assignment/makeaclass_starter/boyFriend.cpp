// Blank cpp file
/*
 * Assigment 3: Make a class!
 * Requirements:
 * Must have a custom constructor ❌
 * Must have a default constructor ❌
    - i.e. constructor overloading
 * Must have private members (functions and/or variables) ❌
 * Must have public members (functions) ❌
 * Must have at least one getter function ❌
 * Must have at least one setter function ❌
 */
#include "boyFriend.h"
#include <iostream>
#include <string>

// default constructor

boyFriend::boyFriend(string name, int age, double height, bool state) {
   this->name = name;
   this->age = age;
   this->height = height;
   this->state = state;
}
