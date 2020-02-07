#pragma once
#include<iostream>
#include "circle.h"
#include "square.h"
using namespace std;

class Geometr {
private: 
	int i=-1;
public:

	double inp_sqr(double);
	double inp_cr(double);

	double area(); 
	double perimetr();
	double mess_box4();
	

};


