#include <iostream>
#include <exception>
#include "Point.h"

using namespace std;

class MyUnexpectedExeption {};

void _unexpexted_to_my()
{
    throw MyUnexpectedExeption();
}

Point makePoint() {
    Point t;
    try
    {
        cin >> t;
    }
    catch (exception& exception)
    {
        cerr << "Standart error: " << exception.what() << endl;
    }
    return t;
}

int main()
{
    set_unexpected(_unexpexted_to_my);

    Point z1 = makePoint();
    Point z2 = makePoint();
    try
    {
        Point t(101, 101);
        cout << t << endl;
        cout << t.distance() << endl;
    }
    catch (PointExeption exception)
    {
        cerr << "Standart error: " << exception.what() << endl;
    }

    try
    {
        cout << z1++ << endl;
    }
    catch (MyExeption* exception)
    {
        cerr << "Standart error: " << exception->what() << endl;
    }

    return 0;
}
