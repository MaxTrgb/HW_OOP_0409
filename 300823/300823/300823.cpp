#include <iostream>
using namespace std;
#include "List.h"

void putNodeToTail(List*& head, int value) {
	List* n = new List(value);

	if (head == nullptr)
	{
		head = n;
		return;
	}

	List* tmp = new List();

	tmp = head;

	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	tmp->next = n;
}

void display(List*& head) {

	List* tmp = new List();

	tmp = head;

	while (tmp != nullptr)
	{
		cout << tmp->value << " ";

		tmp = tmp->next;
	}
}
int countNegative(List* head) {
	List* tmp = new List();

	tmp = head;

	int neg = 0;

	while (tmp != nullptr)
	{
		if (tmp->value < 0)
		{
			neg++;
		}

		tmp = tmp->next;
	}
	return neg;
}
void increaseVal(List* head, int increment) {
	List* tmp = new List();

	tmp = head;

	while (tmp != nullptr)
	{
		tmp->value += increment;
		tmp = tmp->next;
	}
}
void removeElement(List* &head, int toRemove) {

	if (head->value == toRemove)
	{
		head = head->next;
	}

	List* tmp = new List();

	tmp = head;

	while (tmp->next != nullptr)
	{
		if (tmp->next->value == toRemove && tmp->next->next == nullptr)
		{
			tmp->next = nullptr;
			break;
		}
		if (tmp->next->value == toRemove)
		{
			tmp->next = tmp->next->next;
		}
		tmp = tmp->next;
	}
}
void inputElem(List*& head, int afterNum, int placeNum) {

	List* tmp = new List();

	tmp = head;

	while (tmp != nullptr)
	{
		if (tmp->value == afterNum)
		{
			tmp->next = new List(placeNum, tmp->next);
			
		}
		tmp = tmp->next;
	}
}


int main()
{
	srand(time(NULL));

	List* list = new List();

	for (int i = 1; i < 10; i++)
	{
		putNodeToTail(list, rand() % 10 + 1);
		putNodeToTail(list, rand() % (10 + 1) * -1);
	}

	cout << "List of numbers: " << endl;
	display(list);	cout << endl;

	cout << "\nNumber of negative values: ";
	cout << countNegative(list) << endl;

	cout << "\nIncreasing value:" << endl;
	increaseVal(list, 10);
	display(list); cout << endl;

	int remove;
	cout << "\nEnter value to remove: "; cin >> remove;
	cout << "\nRemoving element " << "'" << remove << "'" << ":" << endl;
	removeElement(list, remove);
	display(list); cout << endl;

	int afterNum = 0;
	int placeNum = 0;

	cout << "\nEnter number to input: "; cin >> placeNum;
	cout << "After number: "; cin >> afterNum;
	inputElem(list, afterNum, placeNum);
	display(list); cout << endl;

}