//conway wang 9/30/15
//header file for the name class

#ifndef NAME_H
#define NAME_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Name
{
public:
    void input();
    void display();
    Name();
    Name(string, char , string);
    Name(string, string);
    void setName(string, char , string);
    string getFname();
    char getMinit();
    string getLname();

private:
    string Fname, Lname;
    char Minit;
};

#endif
