//conway wang 9/30/15
//function definitions for Name class

#include "Name.h"

Name::Name()//default constructor
{
    Fname="Scott";
    Lname="Fitzgerald";
    Minit='F';
}

Name::Name(string f, char m, string l)//overloaded constructor with name parameters
{

    Fname = f;
    Minit = m;
    Lname = l;
}

Name::Name(string f, string l)//overloaded constructor with name parameters if no middle init
{
    Fname= f;
    Minit=' ';
    Lname=l;
}

void Name::display()
{
    cout << Fname << " " << Minit << " " << Lname << endl;
}

void Name::setName(string f, char m, string l)
{
    Fname = f;
    Minit = m;
    Lname = l;
}

void Name::input()
{
    char check;
    cout << "What is your first name?" << endl;
    cin >> Fname;
    cout << "What is your middle initial? (if N/A enter #)" << endl;
    cin >> check;

    if(check == '#')
        Minit = ' ';
    else
        Minit = check;

    cout<< "What is your last name?" << endl;
    cin>>Lname;
}

string Name::getFname()
{
    return Fname;
}

char Name::getMinit()
{
    return Minit;
}

string Name::getLname()
{
    return Lname;
}
