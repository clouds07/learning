#include <iostream>

struct Point2D {
    int x, y;
};

class Character {
public:
    Character(Point2D& ref) : ref_home(ref) {
    }
    ~Character() {}
private:
    Point2D m_position;     // <- Composition
    Point2D m_direction;    // <- Composition
    Point2D& ref_home;      // <- Aggregation
};

int main() {
    Point2D m_point;
    Character m_char(m_point);  // <- Aggregation

    return 0;
}
