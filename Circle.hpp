#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    Circle(double r);
    Circle(double r, Color color);

    Circle(const Circle & other) = default;
    Circle& operator=(const Circle& other) = default;
    Circle(Circle && other) noexcept;
    Circle& operator=(Circle&& other) noexcept;
    virtual ~Circle() = default;

    using Shape::Shape;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getRadius() const;
    void print() const override;
    [[deprecated("Use other function instead")]] double getPi();

private:
    Circle() = delete; // doesn't allow to call default constructor

    double r_{0};
};
