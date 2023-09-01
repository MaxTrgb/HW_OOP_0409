#include "List.h"
List::List() {
	value = 0;
	next = nullptr;
}
List::List(int value) {
	this->value = value;
	next = nullptr;
}
List::List(int value, List* next) {
	this->value = value;
	this->next = next;
}
