//conway wang 9/30/15
//header file for the date class

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Date
{
public:
    void input(string a);
    void display();
    Date();
    Date(int, int, int);
    bool setDate(int, int, int);
    int getMonth();
	int getDay();
	int getYear();

private:
    int day, month, year;
};


#endif
