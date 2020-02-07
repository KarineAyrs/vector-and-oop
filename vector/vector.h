#pragma once
#include "figure.h"
using namespace std;
class Vector {
protected:
	Figure **f;
	int size;
	int count = 0;
public:
	Vector(int s); 
	~Vector(); 

	int getSize() { return this->size; }
	void push_back(Figure* fig); 
	Figure* pop_back(); 
	Figure* get_param(int); 
	void record_param(int, Figure*);
	bool is_emty();

	Figure*& operator[](int);

	friend std::ostream& operator<< (std::ostream& out, Vector &v);
	friend std::istream& operator>>(std::istream &in, Vector &sq);

	class SizeException{
	public:
		int s;
		SizeException(int s) {
			this->s = s;
		}
	};
	class RangeException {
	public:
		int ind, size;
		RangeException(int ind, int size) {
			this->ind = ind; this->size = size;
		}
	};

	class TypeException {
	public:
		int type;
		TypeException(int type) {
			this->type = type;
		}
	};
	class ParamException {
	public:
		int param;
		ParamException(int param) {
			this->param = param;
		}
	};
};
