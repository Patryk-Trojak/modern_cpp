#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <functional>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

void printCollectionElements(const Collection& collection)
{
    for(const auto& i : collection)
        if(i)
            i->print();
}

void printAreas(const Collection& collection)
{
    for(const auto& i : collection)
        if(i)
            cout << i->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     const std::function< bool(shared_ptr<Shape>) >& predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

constexpr int fib(int n)
{       
    if (n <= 1) 
    {         
        return 1;      
    } 
    else 
    {         
        return fib(n - 2) + fib(n - 1);       
    }     
}

template<class DerivedType, class... Arguments>
    std::shared_ptr<Shape> make_shape(Arguments&&... args)
{
    std::shared_ptr<DerivedType> shape (new DerivedType(std::forward<Arguments>(args)...));
    return shape;
}

int main()
{
    constexpr int fib45 = fib(45);
    std::cout << fib45 << '\n';

    Collection shapes{
    make_shared<Circle>(2.0), 
    make_shared<Circle>(3.0),
    nullptr,
    make_shared<Circle>(4.0),
    make_shared<Rectangle>(10.0, 5.0),
    make_shared<Square>(3.0),
    make_shared<Circle>(4.0),
    make_shared<Circle>(Color::red),
    make_shared<Rectangle>(Color::red),
    make_shared<Square>(Color::red) };

    auto circle = make_shared<Circle>(2.0);
    auto rect = make_shared<Rectangle>(3.0, 2.0);
    shapes.emplace_back(std::move(circle));
    shapes.emplace_back(std::move(rect));

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);


    auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second){
        if(first == nullptr || second == nullptr)
            return false;
        return (first->getArea() < second->getArea());
    };

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    auto perimeterBiggerThan20 = [](shared_ptr<Shape> s)
    {
        if(s)
            return (s->getPerimeter() > 20);
        return false;
    };

    auto areaLessThanX = [x = 10](shared_ptr<Shape> s)
    {
        if(s)
        return (s->getArea() < 10);
            return false;
    };
    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    return 0;
}

