#pragma once
#include "circle.h"
#include"square.h"

using namespace std;

template <class T> class MemManager {
	T* buf;
	int top;
	int size;
	int end;
public:
	MemManager(int size);
	T* getFreeMem();
	void freeMem(T*obj);
};

template <class T> MemManager<T>::MemManager(int size)
{
	buf = (T*)malloc(size*sizeof(T));
	this->size = size;
	top = 0;
}

template <class T> T* MemManager<T> ::getFreeMem()
{
	//if(head!=end) end++;
	return &buf[top++];
}

template <class T> void MemManager<T>::freeMem(T* obj)
{
	top--;
}
