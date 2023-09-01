#pragma once
#include <iostream>
using namespace std;

class List
{
public:
	int value;
	List* next;

	List();
	List(int value);
	List(int value, List* next);


};

