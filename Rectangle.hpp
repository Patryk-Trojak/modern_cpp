#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other) = default;
    Rectangle& operator=(const Rectangle& other) = default;
    Rectangle(Rectangle && other) noexcept;
    Rectangle& operator=(Rectangle&& other) noexcept;
    virtual ~Rectangle() = default;
    using Shape::Shape;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    virtual double getX() const final;
    double getY() const;
    void print() const override;

private:
    Rectangle() = delete;

    double x_{0};
    double y_{0};
};
