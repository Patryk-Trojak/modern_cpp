#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    Circle(double r);
    Circle(const Circle & other) = default;
    using Shape::Shape;

    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;
    [[deprecated("Use other function instead")]] double getPi();
    
private:
    Circle() = delete; // doesn't allow to call default constructor

    double r_{0};
};
