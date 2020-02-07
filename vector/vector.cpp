#include "vector.h"
#include "figure.h"
#include "square.h"
#include "circle.h"
using namespace std;
Vector::Vector(int s)
{
	if (s <= 0 || s>= 2147483647-1)throw SizeException(s);
	this->size = s; 
	f = (Figure**)malloc(s*sizeof(Figure*));	
}

Vector::~Vector()
{
	free(f);
}

void Vector::push_back(Figure * fig) 
{
	if (count >= size) throw RangeException(count, size);
		f[count++] = fig; 	
}

Figure * Vector::pop_back()
{
	if (count <= 0) throw RangeException(count, size);
	return f[--count];
}

Figure * Vector::get_param(int i)
{
	if (i >= size || i < 0 || i>count) throw RangeException(i, size);
	return f[i];
}

void Vector::record_param(int i, Figure *fig) 
{
	if (i >= size || i < 0) throw RangeException(i, size);
		f[i] = fig;
		if(i-count==1)count++; 		
}

bool Vector::is_emty()
{
	if (count == 0) return true;
	return false;
}

Figure *& Vector::operator[](int index)
{
	if (index >= size || index < 0) {} //throw RangeException(index, size);
	return f[index];
}

std::ostream & operator<<(std::ostream & out, Vector & v)
{
	for (int i = 0; i < v.getSize(); i++) {
		v[i]->out(out);
	}
	return out;
}

std::istream & operator>>(std::istream & in, Vector & v)
{
	double type, param;
	in >> type >> param;
	if (param < 0) { throw Vector::ParamException(param); }
	if (type == 1) {  
		Square *sq = new Square(param);
		v.push_back(sq);
	}
	if (type == 2) {
		Circle *cr = new Circle(param);
		v.push_back(cr);
	}
	if (type != 1 && type != 2) throw Vector::TypeException(type);
	return in;
}


