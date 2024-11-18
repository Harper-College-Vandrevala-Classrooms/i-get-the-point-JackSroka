#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x, y;

public:
    Point(double x_val = 0, double y_val = 0) : x(x_val), y(y_val) {}
    double getX() const { return x; }
    double getY() const { return y; }

    double operator-(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    Point operator/(const Point& other) const {
        double mid_x = (x + other.x) / 2;
        double mid_y = (y + other.y) / 2;
        return Point(mid_x, mid_y);
    }

    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    double x1, y1, x2, y2;

    cout << "Enter coordinates for Point 1 (x y): ";
    cin >> x1 >> y1;

    cout << "Enter coordinates for Point 2 (x y): ";
    cin >> x2 >> y2;

    Point p1(x1, y1);
    Point p2(x2, y2);

    double distance = p1 - p2;
    cout << "Distance between ";
    p1.display();
    cout << " and ";
    p2.display();
    cout << " is: " << distance << endl;

    if (p1 == p2) {
        cout << "Point ";
        p1.display();
        cout << " is equal to Point ";
        p2.display();
        cout << endl;
    }
    else {
        cout << "Point ";
        p1.display();
        cout << " is not equal to Point ";
        p2.display();
        cout << endl;
    }

    if (p1 != p2) {
        cout << "Point ";
        p1.display();
        cout << " is not equal to Point ";
        p2.display();
        cout << endl;
    }
    else {
        cout << "Point ";
        p1.display();
        cout << " is equal to Point ";
        p2.display();
        cout << endl;
    }

    Point midpoint = p1 / p2;
    cout << "Midpoint between ";
    p1.display();
    cout << " and ";
    p2.display();
    cout << " is: ";
    midpoint.display();
    cout << endl;

    return 0;
}