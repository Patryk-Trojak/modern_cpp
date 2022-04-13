#pragma once

enum class Color : unsigned char
{
    red,
    green,
    blue
};

class Shape
{
public:
    Shape(Color c);
    Shape(const Shape & other) = default;
    Shape& operator=(const Shape& other) = default;
    Shape(Shape && other) noexcept;
    Shape& operator=(Shape&& other) noexcept;
    virtual ~Shape() {}

    virtual double getArea() const noexcept = 0;
    virtual double getPerimeter() const noexcept = 0;
    virtual void print() const;

    Color color{Color::blue};
};
