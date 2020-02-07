#include<iostream>
#include"circle.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "memman.h"

using namespace std;
static MemManager<Circle> mem(1e7 + 1);

double Circle::area()
{
	return M_PI*rad*rad;
}

double Circle::perimeter()
{
	return 2 * rad*M_PI;
}

double Circle::getParam()
{
	return rad;
}

void Circle::setParam(double s)
{
	rad = s;
}

Circle::Circle(double r)
{
	rad = r;
}

void Circle::out(std:: ostream& sout)
{
	sout << *this;
}

string Circle::getStrpParam()
{
	return r;
}

void * Circle::operator new(size_t)
{
	return mem.getFreeMem();
}

void Circle::operator delete(void *p)
{
	mem.freeMem((Circle*)p);
}

std::ostream & operator<<(std::ostream & out, Circle & cr)
{
	return out << 2 << " " << cr.getParam() << " ";
}

std::istream & operator>>(std::istream & in, Circle & cr)
{
	double p;
	int type;
	in >>type>> p;
	cr.setParam(p);
	return in;
}
