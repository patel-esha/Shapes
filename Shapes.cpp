#include <iostream>
#include <math.h>
#include "Shapes.h"
#define PI 3.14159f
using namespace std;



bool Shape2D::operator>(const Shape2D &rhs) const
{
    const Shape2D *compareTo = &rhs;
    return Area() > compareTo->Area();
}

bool Shape2D::operator<(const Shape2D &rhs) const
{
    const Shape2D *compareTo = &rhs;
    return Area() < compareTo->Area();

}

bool Shape2D::operator==(const Shape2D &rhs) const
{
    const Shape2D *compareTo = &rhs;
    return Area() == compareTo->Area();

}

void Shape2D::ShowArea() const
{
    cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
}




void Square::Scale(float scaleFactor)
{
    _sideLength *= scaleFactor;
}

void Square::Display() const
{
    cout << "The area of the Square is : " << Square::Area() << endl;
    cout << "Length of a side: " << _sideLength << endl;
}

float Square::Area() const
{
    return powf(_sideLength, 2);
}

string Square::GetName2D() const
{
    return "Square";
}




void Triangle::Scale(float scaleFactor)
{
    _baseLength *= scaleFactor;
    _triangleHeight *= scaleFactor;
}

void Triangle::Display() const
{
    cout << "The area of the Triangle is : " << Triangle::Area() << endl;
    cout << "Base: " << _baseLength << endl;
    cout << "Height: " << _triangleHeight << endl;
}

float Triangle::Area() const
{
    return (0.5 * _baseLength * _triangleHeight);
}

string Triangle::GetName2D() const
{
    return "Triangle";
}




void Circle::Scale(float scaleFactor)
{
    _radius *= scaleFactor;
}

void Circle::Display() const
{
    cout << "The area of the Circle is : " << Circle::Area() << endl;
    cout << "Radius: " << _radius << endl;
}

float Circle::Area() const
{
    return (PI * pow(_radius, 2));
}

string Circle::GetName2D() const
{
    return "Circle";
}




void Shape3D::ShowVolume() const
{
    cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
}

bool Shape3D::operator>(const Shape3D &rhs) const
{
    const Shape3D *compareTo = &rhs;
    return Volume() > compareTo->Volume();
}

bool Shape3D::operator<(const Shape3D &rhs) const
{
    const Shape3D *compareTo = &rhs;
    return Volume() < compareTo->Volume();
}

bool Shape3D::operator==(const Shape3D &rhs) const
{
    const Shape3D *compareTo = &rhs;
    return Volume() == compareTo->Volume();
}




void TriangularPyramid::Scale(float scaleFactor)
{
    Triangle::Scale(scaleFactor);
    _height *= scaleFactor;
}

void TriangularPyramid::Display() const
{
    cout << "The volume of the TriangularPyramid is : " << TriangularPyramid::Volume() << endl;
    cout << "The height is: " << _height << endl;
    cout << "The area of the Triangle is : " << Triangle::Area() << endl;
    cout << "Base: " << _baseLength << endl;
    cout << "Height: " << _triangleHeight << endl;
}

float TriangularPyramid::Volume() const
{
    return (Triangle::Area() * _height / 3.0f);
}

string TriangularPyramid::GetName3D() const
{
    return "TriangularPyramid";
}




void Cylinder::Scale(float scaleFactor)
{
    Circle::Scale(scaleFactor);
    _height *= scaleFactor;
}

void Cylinder::Display() const
{
    cout << "The volume of the Cylinder is : " << Cylinder::Volume() << endl;
    cout << "The height is: " << _height << endl;
    cout << "The area of the Circle is : " << Circle::Area() << endl;
    cout << "Radius: " << _radius << endl;

}

float Cylinder::Volume() const
{
    return (PI * pow(_radius, 2) * _height);
}

string Cylinder::GetName3D() const
{
    return "Cylinder";
}




void Sphere::Scale(float scaleFactor)
{
    Circle::Scale(scaleFactor);
}

void Sphere::Display() const
{
    cout << "The volume of the Sphere is : " << Sphere::Volume() << endl;
    cout << "The area of the Circle is : " << Circle::Area() << endl;
    cout << "Radius: " << _radius << endl;
}

float Sphere::Volume() const
{
    return (4 * PI * pow(_radius, 3) / 3.0f);
}

string Sphere::GetName3D() const
{
    return "Sphere";
}


