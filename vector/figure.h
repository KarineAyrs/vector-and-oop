#pragma once
#include <iostream>
using namespace std;
class Figure {
public: virtual double area() = 0;
		virtual double perimeter() = 0;
		virtual void out(std::ostream &) = 0;
};