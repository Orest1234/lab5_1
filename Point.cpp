#include "Point.h"
#include <cmath>
#include <sstream>

using namespace std;

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(double first, double second) throw(PointExeption)
{
    if (first > 100 || second > 100)
        throw PointExeption("Wrong value(Point)");
    x = first;
    y = second;
}

Point::Point(const Point& t) {
    x = t.x;
    y = t.y;
}

Point::~Point()
{}

void Point::SetX(double value) {
    x = value;
}

void Point::SetY(double value) {
    y = value;
}

Point& Point::operator = (const Point& t) {
    x = t.x;
    y = t.y;

    return *this;
}

Point::operator string () const {
    stringstream ss;
    ss << " x = " << x << endl;
    ss << " y = " << y << endl;
    return ss.str();
}

Point operator + (Point& t1, Point& t2) {
    return Point(t1.x + t2.x, t1.y + t2.y);
}

Point operator - (Point& t1, Point& t2) {
    return Point(t1.x - t2.x, t1.y - t2.y);
}

ostream& operator << (ostream& out, const Point t) {
    out << string(t);
    return out;
}

istream& operator >> (istream& in, Point& t) {
    cout << "x = "; in >> t.x;
    cout << "y = "; in >> t.y;

    if (abs(t.x) > 100 || abs(t.y) > 100)
        throw out_of_range("Wrong values");

    return in;
}

Point& Point::operator ++ () throw (MyExeption)
{
    x++;

    if (abs(x) > 100)
        throw new MyExeption("Out of range(MyExeption)");

    return *this;
}

Point& Point::operator -- () throw (MyExeption)
{
    x--;

    if (abs(x) > 100)
        throw new MyExeption("Out of range(MyExeption)");

    return *this;
}

Point Point::operator ++ (int) throw (MyExeption)
{
    Point t(*this);
    y++;

    if (abs(y) > 100)
        throw new MyExeption("Out of range(MyExeption)");

    return t;
}

Point Point::operator -- (int) throw (MyExeption)
{
    Point t(*this);
    y--;

    if (abs(y) > 100)
        throw new MyExeption("Out of range(MyExeption)");

    return t;
}

double Point::distance() {
    return sqrt(x * x + y * y);
}
