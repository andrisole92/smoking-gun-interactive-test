#include <iostream>
class Point2D {

public:
    float x;
    float y;

    Point2D(float x1, float y1) {
        x = x1;
        y = y1;
    }
};

class Rectangle2D {
public:
    Point2D bottomLeft;
    Point2D topRight;

    Rectangle2D(Point2D p1, Point2D p2) : bottomLeft(p1), topRight(p2) {
        bottomLeft = p1;
        topRight = p2;

    }

    Rectangle2D(const Rectangle2D &r2) : bottomLeft(r2.bottomLeft), topRight(r2.topRight) {
        bottomLeft = r2.bottomLeft;
        topRight = r2.topRight;
    }

    bool containsPoint(Point2D p3) const {
        if (p3.x > bottomLeft.x && p3.x <= topRight.x && p3.y >= bottomLeft.y && p3.y <= topRight.y) {
            return true;
        } else {
            return false;
        }
    }

    bool intersects(const Rectangle2D& r3) const {
        // x-axis
        if (topRight.x >= r3.bottomLeft.x || r3.topRight.x >= bottomLeft.x)
            return true;
        // y-axis
        if (topRight.y >= r3.bottomLeft.y || r3.topRight.y >= bottomLeft.y)
            return true;
        // def
        return false;
    }

};

int main() {
    Point2D p1(3, 3);
    Point2D p2(1, 1);
    Point2D p3(0, -1);

    Rectangle2D rect1(Point2D(0, 0), Point2D(10, 10));
    Rectangle2D rect2(rect1);

    std::cout << rect1.topRight.y << "\n";
    std::cout << rect1.containsPoint(p1) << "\n"; // True
    std::cout << rect1.containsPoint(p2) << "\n"; // True
    std::cout << rect1.containsPoint(p3) << "\n"; // False
    std::cout << rect1.intersects(rect2) << "\n"; // True
    std::cout << (rect1.topRight.y > rect2.bottomLeft.y) << "\n"; // True
    return 0;
}
