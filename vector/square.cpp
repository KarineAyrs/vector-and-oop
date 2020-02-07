#include <iostream>
#include "square.h"
#include "memman.h"

using namespace std;

static MemManager<Square> mem(1e7+1);

double Square::area()
{
	return side*side;
}

Square::Square(double s)
{
	side = s;
}

void Square::out(std::ostream &fout)
{
	fout << *this;
}

string Square::getStringParam()
{
	return s;
}

double Square::perimeter()
{
	return 4 * side;
}

double Square::getParam()
{
	return side;
}

void Square::setParam(double s)
{
	side=s;
}

void * Square::operator new(size_t)
{
		return mem.getFreeMem();
}

void Square::operator delete(void *p)
{
	mem.freeMem((Square*)p);
}

std::ostream & operator<<(std::ostream &out, Square & sq)
{
	return out << 1 << " "<<sq.getParam()<<" ";
}

std::istream & operator>>(std::istream & in,  Square & sq)
{
	double p;
	in >> p;
	sq.setParam(p);
	return in;
}
