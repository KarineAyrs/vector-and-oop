#pragma once
#include<iostream>
#include "figure.h"
using namespace std;
class Square : public Figure{
private:
	double side;
	const string s = "side";
public: double area() ;
		double perimeter();
		double getParam();
		void setParam(double);
		Square(double);
		void out(std::ostream&);
		string getStringParam();
		

		void* operator new(size_t);
		void operator delete(void*);
		friend std::ostream& operator<< (std::ostream &out, Square &sq);
		friend std::istream& operator>>(std::istream &in, Square &sq);
};

