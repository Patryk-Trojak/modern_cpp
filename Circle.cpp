#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r)
    : Shape(Color::blue),
      r_(r)
{}

Circle::Circle(Circle && other) noexcept
    : Shape(std::move(other)),
      r_(std::move(other.r_))
{}

Circle& Circle::operator=(Circle&& other) noexcept
{
    Shape::operator=(std::move(other));
    r_ = std::move(other.r_);
    return *this;
}

double Circle::getArea() const noexcept
{
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const noexcept
{
    return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
    return r_;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}

double Circle::getPi()
{
    return 3.14;
}