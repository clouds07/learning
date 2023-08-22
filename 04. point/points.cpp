// class example
#include <iostream>

using namespace std;

class point {
public:
    point();
    point(double, double);
    double getx() const {return x;}
    double gety() const {return y;}

    void setx(double val) {x = val;}
    void sety(double val) {y = val;}

    point operator+(const point& p1);
//private:
    double x, y;
};

point::point()
{
    x = 0.0;
    y = 0.0;
}

point::point(double x_, double y_)
{
    x = x_;
    y = y_;
}

point point:: operator+ (const point& p)
{
    const point& sum = point(this->x + p.x, this->y + p.y);
    return sum;
}

inline point operator+ (point& p1, point& p2)
{
    point sum = {p1.x + p2.x, p1.y + p2.y};
    return sum;
}

ostream& operator<< (ostream& out, const point& p)
{
    out << "(" << p.x << ", " << p.y << ")";

    return out;
}


int main(void)
{
    point a = {2.5, 3.5};
    point b = {7.25, 1.5};
    point c = a + b;

    cout << "a = " << a << "\tb = " << b << endl;
    cout << "c = " << c << endl;
}
