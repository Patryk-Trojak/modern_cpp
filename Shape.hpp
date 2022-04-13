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
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

    Color color;
};
