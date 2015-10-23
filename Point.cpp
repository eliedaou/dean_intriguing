/* --------------- P o i n t . c p p ---------------
 
 Kevin Fuerst
 16.322 Data Structures
 10/5/15
 
 
 Purpose:
 Module with Overloaded Operators, Functions, Accessors, and Mutators for point.h
 */

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

#include "Point.h"


/* --------------- Overloaded >> Operator ---------------
 
 Purpose:
 Oveload the Input (>>) Operator to accept objtects unsing the type Point
 
 INPUT PARAMETERS:
 &p -- object of type Point passed from the function call
 
 RETURN VALUE:
 input stream 'is'
 */

istream & operator>>(istream &is, Point &p)
{
    p.Get(is);
    //ignoring new line caused so loop can continue.
    return is;
}

/* --------------- Overloaded << Operator ---------------
 
 Purpose:
 Oveload the Output (<<) Operator to accept objtects unsing the type Point
 
 INPUT PARAMETERS:
 &p -- object of type Point passed from the function call
 
 RETURN VALUE:
 output stream 'os'
 */

ostream & operator<<(ostream &os, Point &p)
{
    p.Show(); // call Show() funciton using the Point p
    return os;
}

/* --------------- G E T () ---------------
 
 Purpose:
 Get coordinates from the keyboard and set the defined value true
 
 INPUT PARAMETERS:
 input stream &is
 
 */

void Point::Get(istream &is)
{
    if (cin.peek() != EOF)// checking if next input is a newline
    {
        is >> x >> y;//geting x and y // calling apon the get function p. is needed because this function is                out side of class
        Set(x, y);
    }
}

/* --------------- S E T () ---------------
 
 Purpose:
 Muator function to set x and y values
 
 INPUT PARAMETERS:
 point coordinates xVal and yVal
 
 */
void Point::Set(double xVal, double yVal)
{
    x=xVal;
    y=yVal;
    Point p(x,y);
}

/* --------------- S H O W () ---------------
 
 Purpose:
 Function
 
 INPUT PARAMETERS:
 point coordinates xVal and yVal
 
 */
void Point::Show(ostream &os)
{
    cout<<"("<<x<<","<<y<<")"; // output x and y coordinates along with formatting characters
}


/* --------------- X () ---------------
 
 Purpose:
 Accessor function to return x value
 
 OUTPUT PARAMETERS:
 x value
 */
double Point::X() const
{
    return x;
}

/* --------------- Y () ---------------
 
 Purpose:
 Accessor function to return 7 value
 
 OUTPUT PARAMETERS:
 y value
 */

double Point::Y() const
{
    return y;
}
