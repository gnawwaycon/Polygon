/*
 *Conway Wang 9/20/15
 *lab 3-midterm revision cisc 2000
 *Header file for the Polygon class
 */

#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Polygon{
public:
    Polygon();//default constructor
    Polygon(int,int);//constructor with width and legth
    Polygon(int,int,int,int);//constructor with width length max and min
	~Polygon();//destructor adjusts class level statistics
    bool setLength(int), setWidth(int);
    void input();
    int getArea() const;
    int  getPerimeter() const;
    void displayInfo() const;
    void draw() const;
    void displayData() const;
    int calculateA(int,int), calculateP(int,int);
    static int getNumPolygons();
    static int getMAX_POLYGONS();

private:

    static const int DEFAULT_MIN=10, DEFAULT_MAX=100, MAX_POLYGONS=25;//static const declared in the class
    static int numPolygons;
	static double pTrack,aTrack;
    const int MIN, MAX;
    int length, width, area, perimeter;
};

#endif
