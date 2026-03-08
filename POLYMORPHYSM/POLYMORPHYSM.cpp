#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string name;
    string type;

public:
    Shape(string n, string t) {
        name = n;
        type = t;
    }

    virtual void Show() {
        cout << "Назва фігури: " << name << endl;
        cout << "Тип фігури: " << type << endl;
    }

    virtual double GetArea() = 0;
};

class Rectangle : public Shape {
    double width, height;

public:
    Rectangle(double w, double h) : Shape("Прямокутник", "Чотирикутник") {
        width = w;
        height = h;
    }

    void Show() override {
        Shape::Show();
        cout << "Ширина: " << width << endl;
        cout << "Висота: " << height << endl;
    }

    double GetArea() override {
        return width * height;
    }
};

class Circle : public Shape {
    double radius;

public:
    Circle(double r) : Shape("Коло", "Кругла фігура") {
        radius = r;
    }

    void Show() override {
        Shape::Show();
        cout << "Радіус: " << radius << endl;
    }

    const double PI = 3.1415;

    double GetArea() override {
        return PI * radius * radius;
    }
};

class RightTriangle : public Shape {
    double a, b;

public:
    RightTriangle(double a1, double b1) : Shape("Прямокутний трикутник", "Трикутник") {
        a = a1;
        b = b1;
    }

    void Show() override {
        Shape::Show();
        cout << "Катет a: " << a << endl;
        cout << "Катет b: " << b << endl;
    }

    double GetArea() override {
        return (a * b) / 2;
    }
};

class Triangle : public Shape {
    double base, height;

public:
    Triangle(double b, double h) : Shape("Трикутник", "Трикутник") {
        base = b;
        height = h;
    }

    void Show() override {
        Shape::Show();
        cout << "Основа: " << base << endl;
        cout << "Висота: " << height << endl;
    }

    double GetArea() override {
        return (base * height) / 2;
    }
};

class Trapezoid : public Shape {
    double a, b, height;

public:
    Trapezoid(double a1, double b1, double h) : Shape("Трапеція", "Чотирикутник") {
        a = a1;
        b = b1;
        height = h;
    }

    void Show() override {
        Shape::Show();
        cout << "Основа a: " << a << endl;
        cout << "Основа b: " << b << endl;
        cout << "Висота: " << height << endl;
    }

    double GetArea() override {
        return ((a + b) * height) / 2;
    }
};

void TestShape(Shape& s) {
    s.Show();
    cout << "Площа: " << s.GetArea() << endl;
    cout << "----------------------" << endl;
}

int main() {

    Rectangle rect(5, 4);
    Circle circle(3);
    RightTriangle rt(3, 4);
    Triangle tr(6, 5);
    Trapezoid trap(4, 6, 5);

    TestShape(rect);
    TestShape(circle);
    TestShape(rt);
    TestShape(tr);
    TestShape(trap);

    return 0;
}