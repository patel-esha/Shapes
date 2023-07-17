#ifndef LAB6_SHAPES_H
#define LAB6_SHAPES_H

using namespace std;

// Abstract Base Class: Base Class
class Shape
{
public:
    virtual ~Shape() {}
    virtual void Scale(float scaleFactor) = 0;  // needs to be specified by derived
    virtual void Display() const = 0; // needs to be specified by derived
};


// Abstract Base Class: Derived 2D Class
class Shape2D : virtual public Shape
{
public:
    virtual ~Shape2D() {}

    virtual float Area() const = 0; // needs to be specified by derived
    void ShowArea() const; // accessor
    virtual string GetName2D() const = 0;  // needs to be specified by derived
    // comparison operators are overloaded so that a 2D shape can compare
    // itself to other shapes' areas
    bool operator>(const Shape2D &rhs) const;
    bool operator<(const Shape2D &rhs) const;
    bool operator==(const Shape2D &rhs) const;
};


class Square : virtual public Shape2D
{
public:
    float _sideLength;

    void Scale(float scaleFactor);
    void Display() const;

    float Area() const;
    string GetName2D() const;

    Square() : _sideLength(0) {};
    Square(float length) : _sideLength(length) {};

    ~Square() {}
};


class Triangle : virtual public Shape2D
{
public:
    float _baseLength;
    float _triangleHeight;

    void Scale(float scaleFactor);
    void Display() const;

    float Area() const;
    string GetName2D() const;

    Triangle() : _baseLength(0), _triangleHeight(0) {};
    Triangle(float baseLength, float height) : _baseLength(baseLength), _triangleHeight(height) {};

    ~Triangle() {}
};


class Circle : virtual public Shape2D
{
public:
    float _radius;

    void Scale(float scaleFactor);
    void Display() const;

    float Area() const;
    string GetName2D() const;

    Circle() : _radius(0) {};
    Circle(float radius) : _radius(radius) {};

    ~Circle() {}
};


class Shape3D : virtual public Shape
{
public:
    virtual ~Shape3D() {}

    virtual float Volume() const = 0; // needs to be specified by derived
    void ShowVolume() const;
    virtual string GetName3D() const = 0; // needs to be specified by derived
    // the comparison operators will be defined in terms of the volume function
    bool operator>(const Shape3D &rhs) const;
    bool operator<(const Shape3D &rhs) const;
    bool operator==(const Shape3D &rhs) const;
};


class TriangularPyramid : virtual public Shape3D, virtual private Triangle
{
private:
    float _height;

public:
    void Scale(float scaleFactor);
    void Display() const;

    float Volume() const;
    string GetName3D() const;

    TriangularPyramid() : _height(0) {};
    TriangularPyramid(float pyramidHeight, float baseLength, float baseHeight)
            : Triangle(baseLength, baseHeight), _height(pyramidHeight) {}

    ~TriangularPyramid() {}
};


class Cylinder : virtual public Shape3D, virtual private Circle
{
private:
    float _height;

public:
    void Scale(float scaleFactor);
    void Display() const;

    float Volume() const;
    string GetName3D() const;

    Cylinder() : _height(0) {};
    Cylinder(float height, float radius)
            : Circle(radius), _height(height) {};

    ~Cylinder() {}
};


class Sphere : virtual public Shape3D, virtual private Circle
{
public:
    void Scale(float scaleFactor);
    void Display() const;

    float Volume() const;
    string GetName3D() const;

    Sphere() : Circle(0.0f) {};
    Sphere(float radius) : Circle(radius) {}; // forward this to the Circle constructor

    ~Sphere() {}
};


#endif //LAB6_SHAPES_H
