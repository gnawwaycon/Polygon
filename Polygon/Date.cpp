//conway wang 9/30/15
//function definitions for Date class

#include "Date.h"

Date::Date(){
	day=1;
	month=1;
	year=1900;
}



Date::Date(int m, int d, int y)
{
    day=d;
    month=m;
    year=y;
}

void Date::display()
{
    cout << month << "/" << day << "/" << year << endl;
}

bool Date::setDate(int m, int d, int y)
{
    day=d;
    year=y;
    if(m<1||m>12)//wont set m to value passed to mutator if it isn't valid
    {
        return true;
    }
    month=m;
    if(m==3)//february
        return (!(d>=1||d<=29));//if lies within range of month returns false if it doesnt returns true
    else if(m%2==1)
        return (!(d>=1||d<=31));
    else
        return (!(d>=1||d<=30));

}

void Date::input(string a)
{
    int m,d,y;
    cout<< a << endl;
    cin>> m >> d >> y;
    while(setDate(m,d,y))
    {
        cout<<"Invalid input re-enter date" << endl;
        cin>> m >> d >> y;
    }
}

int Date::getMonth()
{
	return( month );
}

int Date::getDay()
{
	return( day );
}

int Date::getYear()
{
	return( year );
}
