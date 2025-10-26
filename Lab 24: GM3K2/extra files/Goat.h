//
//  Goat.h
//  Lab 24: GM3K2
//
//  Created by Guo An Wang on 10/26/25.
//
// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
    string name;
    int age;
    string color;
public:
    Goat()                        { name = ""; age = 0; color = ""; }
    // write three more constructors
    Goat(string n) { name = n; age = 0; color = "";} //constructor with one parameter
    Goat(string n, int a)  {name = n; age = a; color = "";} //constructor with twoparameters
    Goat(string n, int a, string c) {name = n; age = a; color = c;} //constructor with three parameters
    // setters and getters
    void set_name(string n)         { name = n; };
    string get_name() const         { return name; };
    void set_age(int a)             { age = a; };
    int get_age() const             { return age; }
    void set_color(string c)        { color = c; }
    string get_color() const        { return color; }

    // write overloaded < operator for the std::list
    bool operator<(const Goat &other) const
    {
        //check if names are equal
        if (name < other.name) return true;
        if (name > other.name) return false;
        
        //checks if ags are equal
        if (age < other.age) return true;
        if (age > other.age) return false;
        
        //last case is checking color
        if (color < other.color) return true;
        if (color > other.color) return true;
        //if nothing returns then two objects are equal
        return false;
    }
};

#endif

