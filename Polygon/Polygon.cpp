/*
Conway Wang 10/28/15
lab midterm cisc 2000
Function definitions for the Polygon class
*/

#include "Polygon.h"

int Polygon::numPolygons;
double Polygon::pTrack;
double Polygon::aTrack;

Polygon::Polygon():MIN(DEFAULT_MIN), MAX(DEFAULT_MAX)//default constructor
{
    length=0, width=0, area=0, perimeter=0;
}

Polygon::Polygon(int a, int b):MIN(a),MAX(b)//constructor for when min and max values are passed
{
    length=0, width=0, area=0, perimeter=0;
	numPolygons++;
}

Polygon::Polygon(int a, int b, int c,int d):MIN(c),MAX(d)//constructor for when length and width and min and max values are passed
{
    length=a, width=b;
    calculateA(a,b);//variable area is set in the calculate method
    calculateP(a,b);//variable perimeter is set in the calculate method
}

//destructor
Polygon::~Polygon()
{
    numPolygons--;//1 less polygon
    pTrack-=perimeter;//perimeter is subtracted from total perimeter
    aTrack-=area;//area is subtracted from total area
}

void Polygon::input()//takes in user input to fill data members
{
    int l,w;

    do//asks for length of polygon until input is in range
    {
        cout << "What is the length of the polygon?\n";
        cin >> l;
    }while(!setLength(l));

    do//asks for width of polygon until input is in range
    {
        cout << "What is the width of the polygon?\n";
        cin >> w;
    }while(!setWidth(w));
    numPolygons++;
    area = calculateA(l,w);//calculates area
    perimeter = calculateP(l,w);//calculates perimeter
}

bool Polygon::setLength(int l)//checks if the length is within min and max and stops loop and sets the length if it is
{
    bool a=false;
    if(l>=MIN && l<=MAX)
    {
        length=l;
        a=true;
    }
    return (a);
}

bool Polygon::setWidth(int w)//checks if the width is within min and max and stops loop and sets the width if it is
{
    bool a=false;
    if(w>=MIN && w<=MAX)
    {
        width=w;
        a=true;
    }
    return a;
}

void Polygon::draw() const
{
    for(int x=0; x<width; x++)//what to print for each row
    {
        for(int y=0; y<length; y++)
        {
                if(x==0||x==(width-1))//if first row all x's
                {
                    cout<< 'x';
                }

                else if(y==0||y==(length-1))//if column first or last, x
                {
                        cout << 'x';
                }

                else
                {
                        cout << ' ';//otherwise blank
                }
    }
    cout<< endl;
}
}

void Polygon::displayInfo() const//displays private data members of the function
{
    cout << "length: " << length << endl;
    cout << "width: " << width << endl;
    cout << "area: " << area << endl;
    cout << "perimeter: " << perimeter << endl;
}

void Polygon::displayData() const
{
    cout << "number of polygons: " << numPolygons << endl;
    cout << "average area: " <<  aTrack/numPolygons << endl;//total area divided by number of polygons gives average area
    cout << "average perimeter " << pTrack/numPolygons << endl;//total perimeter divided by number of polygons gives average perimeter
}

int Polygon::calculateA(int length,int width)
{
	area = length*width;
	aTrack += area;//adds on area to static variable keeping track of the sum of all areas
    return area;
}

int Polygon::calculateP(int length,int width)
{
	perimeter=2*length*2*width;
	pTrack+=perimeter;//adds on perimeter to static variable keeping track of the sum of all perimeters
    return perimeter;
}

int Polygon::getNumPolygons()
{
    return numPolygons;
}

int Polygon::getMAX_POLYGONS()
{
    return MAX_POLYGONS;
}

int Polygon::getPerimeter() const
{
    return perimeter;
}

int Polygon::getArea() const
{
    return area;
}
