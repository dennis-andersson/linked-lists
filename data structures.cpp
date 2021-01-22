
#include <iostream>

#include "LinkedList.hpp"
#include "CircularLinkedList.hpp"
#include "DoubleLinkedList.hpp"

using namespace std;

int main()
{
	//LinkedList xs;
	//CircularLinkedList xs;
	DoubleLinkedList xs;

	for (int i = 0; i <= 10; i++) xs.addNode(i);

	cout << "Original list" << endl;
	xs.DisplayList();

	cout << "There are " << xs.size() << " nodes. Which node do you want to delete? ";
	int index;
	cin >> index;
	xs.remove(index);
	xs.DisplayList();

	cout << "Removed second node" << endl;
	xs.removeSecondNode();
	xs.DisplayList();

	cout << "Removed fifth node" << endl;
	xs.remove(5);
	xs.DisplayList();

	cout << "Removed first node" << endl;
	xs.removeFirstNode();
	xs.DisplayList();

	cout << "Removed last node" << endl;
	xs.removeLastNode();
	xs.DisplayList();

	cout << "Added a new head" << endl;
	xs.addNodeBeforeHead(99);
	xs.DisplayList();

	cout << "Added a node after head" << endl;
	xs.addNodeAfterHead(42);
	xs.DisplayList();

	cout << "Added a new tail" << endl;
	xs.addNode(99);
	xs.DisplayList();

	cout << "Delete entire list" << endl;
	xs.deleteList();
	xs.DisplayList();

	return 0;
}


