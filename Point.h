/* --------------- P o i n t . h ---------------
 
 Kevin Fuerst
 16.322 Data Structures
 10/5/15
 
 
 Prupose:
 Provides the interface to the modeule Point.cpp
 */
#include <iostream>
#include "stdio.h"

#ifndef POINT_H
#define POINT_H

using namespace std;

class Point
{
public:
    // Constructors
    Point() : defined(false) { }
    
    Point(double xVal, double yVal) : x(xVal), y(yVal), defined(true) { }
    // Accessors
    double X() const; // Returns x
    double Y() const; // Returns y
    bool Defined() { return defined; } // Returns defined
    // Mutator
    void Set(double xVal, double yVal); // Sets (x,y)
    // I/O Functions
    void Show(ostream &os=cout);
    void Get(istream &is=cin);
private:
    bool defined; // true if point has been defined
    double x; // x coordinate
    double y; // y coordinate
    
};
// Input-Output Operators
istream & operator>>(istream &is, Point &p);
ostream & operator<<(ostream &os, Point &p);

#endif