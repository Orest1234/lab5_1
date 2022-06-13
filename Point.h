#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

class MyExeption
{
    string m_error;
public:
    MyExeption() throw()
    {
        m_error = "";
    }
    MyExeption(const string& error) throw()
    {
        m_error = error;
    }
    virtual ~MyExeption() {};
    string const what() const throw () { return m_error; };
};

class PointExeption
        : public exception
{
private:
    string m_error;
public:
    PointExeption(string error)
            : m_error(error)
    {}

    const char* what() const noexcept { return m_error.c_str(); }
};

class Point
{
private:
    double x, y;

public:
    Point();
    Point(double, double)  throw(PointExeption);
    Point(const Point&);
    ~Point();

    double GetX() const { return x; }
    double GetY() const { return y; }
    void SetX(double value);
    void SetY(double value);

    Point& operator = (const Point&);
    operator string() const;

    friend Point operator + (Point&, Point&);
    friend Point operator - (Point&, Point&);

    friend ostream& operator << (ostream&, const Point);
    friend istream& operator >> (istream&, Point&);

    Point& operator ++() throw (MyExeption);
    Point& operator --() throw (MyExeption);
    Point operator ++(int) throw (MyExeption);
    Point operator --(int) throw (MyExeption);

    double distance();
};
