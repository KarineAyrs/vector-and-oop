#pragma once
#include<iostream>
#include "figure.h"
using namespace std;
class Circle : public Figure {
private:
	double rad;
	const string r="radius";
public: double area();
		double perimeter();
		double getParam();
		void setParam(double);
		Circle(double);
		void out(std::ostream&);
		string getStrpParam();
		

		void* operator new(size_t);
		void operator delete(void*);
		friend std::ostream& operator<< (std::ostream& out, Circle &cr);
		friend std::istream& operator>>(std::istream &in,Circle &cr);	
};