#include "Shape.hpp"
#include <iostream>

Shape::Shape(Color c)
    : color(c)
{}

Shape::Shape(Shape && other) noexcept
    : color(std::move(other.color))
{}

Shape& Shape::operator=(Shape && other) noexcept
{
    color = std::move(other.color);
    return *this;
}


void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}
