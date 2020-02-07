#include "geometr.h"
#include "vector.h"
#include<iostream>
#include <conio.h>
#include "circle.h"
#include "square.h"
#include <string>
using namespace std;

int MAX_SIZE = 10000;

Vector v(MAX_SIZE);

double Geometr::inp_sqr(double par)
{
	Square *cr=new Square(0);
	if (par <= 0) { return 1; }
	cr->setParam(par);
	try {
		v.push_back(cr);
	}
	catch (Vector::RangeException) {
		return -1;
	}
	i++;
	return -2;
}
double Geometr::inp_cr(double par)
{
	
	Circle *cr=new Circle(0);
	if (par <= 0) { return -1; }
	cr->setParam(par);
	try {
		v.push_back(cr);
	}
	catch (Vector::RangeException) {
		return -1;
	}
	i++;
	return -2;
}
double Geometr::area()
{
	if (i == -1) { return -1; }
	else {
		return v[i]->area();
	}
}

double Geometr::perimetr()
{
	if (i == -1) { return -1; }
	else {
		return v[i]->perimeter();
	}
}

double Geometr::mess_box4()
{
	_getch(); exit(0);
}



