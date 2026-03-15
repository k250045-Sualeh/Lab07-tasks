#include <iostream>
using namespace std;

class Shape {
protected:
    int x, y;         
    string color;
    int borderThickness;

public:
    Shape(int px, int py, string c, int bt = 1) {
        x = px;
        y = py;
        color = c;
        borderThickness = bt;
    }

    
    virtual void draw() {
        cout << "Drawing a generic shape at (" << x << "," << y << ")" << endl;
    }

    virtual float calculateArea() {
        return 0;
    }

    virtual float calculatePerimeter() {
        return 0;
    }
};


class Circle : public Shape {
private:
    float radius;

public:
    Circle(int cx, int cy, string c, float r)
        : Shape(cx, cy, c) {
        radius = r;
    }

    void draw() {
        cout << "Drawing Circle at (" << x << "," << y << ") with radius " << radius << endl;
    }

    float calculateArea() {
        return 3.14 * radius * radius;
    }

    float calculatePerimeter() {
        return 2 * 3.14 * radius;
    }
};


class Rectangle : public Shape {
private:
    float width, height;

public:
    Rectangle(int tx, int ty, string c, float w, float h)
        : Shape(tx, ty, c) {
        width = w;
        height = h;
    }

    void draw() {
        cout << "Drawing Rectangle at (" << x << "," << y << ") width " 
             << width << " height " << height << endl;
    }

    float calculateArea() {
        return width * height;
    }

    float calculatePerimeter() {
        return 2 * (width + height);
    }
};


class Triangle : public Shape {
private:
    float a, b, c;

public:
    Triangle(int px, int py, string col, float s1, float s2, float s3)
        : Shape(px, py, col) {
        a = s1;
        b = s2;
        c = s3;
    }

    void draw() {
        cout << "Drawing Triangle at (" << x << "," << y << ")" << endl;
    }

    float calculatePerimeter() {
        return a + b + c;
    }


    float calculateArea() {
        float base = a;
        float height = b;  
        return 0.5 * base * height;
    }
};

class Polygon : public Shape {
private:
    int sides;
    float sideLength;

public:
    Polygon(int px, int py, string col, int s, float sl)
        : Shape(px, py, col) {
        sides = s;
        sideLength = sl;
    }

    void draw() {
        cout << "Drawing Polygon with " << sides << " sides at (" 
             << x << "," << y << ")" << endl;
    }

    float calculatePerimeter() {
        return sides * sideLength;
    }

    float calculateArea() {
        
        return (sides * sideLength * sideLength) / 4;
    }
};

int main() {
    Circle c1(5, 5, "Red", 7);
    Rectangle r1(0, 0, "Blue", 10, 6);
    Triangle t1(2, 3, "Green", 3, 4, 5);
    Polygon p1(1, 1, "Yellow", 5, 4);

    cout << "--- Circle ---" << endl;
    c1.draw();
    cout << "Area: " << c1.calculateArea() << endl;
    cout << "Perimeter: " << c1.calculatePerimeter() << endl;

    cout << "\n--- Rectangle ---" << endl;
    r1.draw();
    cout << "Area: " << r1.calculateArea() << endl;
    cout << "Perimeter: " << r1.calculatePerimeter() << endl;

    cout << "\n--- Triangle ---" << endl;
    t1.draw();
    cout << "Area: " << t1.calculateArea() << endl;
    cout << "Perimeter: " << t1.calculatePerimeter() << endl;

    cout << "\n--- Polygon ---" << endl;
    p1.draw();
    cout << "Area: " << p1.calculateArea() << endl;
    cout << "Perimeter: " << p1.calculatePerimeter() << endl;

    return 0;
}