#pragma once
#include <iostream>

using namespace std;

class DoubleLinkedList
{
	struct Node
	{
		int data;
		Node* prev;
		Node* next;
	};

	Node* head;
	Node* tail;
	int nodes;

	Node* createNode(int val, Node* next, Node* prev)
	{
		Node* newNode = new Node;
		newNode->data = val;
		newNode->next = next;
		newNode->prev = prev;
		return newNode;
	}
public:
	DoubleLinkedList()
	{
		head = tail = nullptr;
		nodes = 0;
	}

	~DoubleLinkedList()
	{
		deleteList();
	}

	void deleteList()
	{
		if (head) {
			Node* node = tail;
			Node* prev;

			while (node) {
				prev = node->prev;
				delete node;
				node = prev;
			}

			head = tail = nullptr;
			nodes = 0;
		}
	}

	void addNode(int val)
	{
		if (head) {
			tail->next = createNode(val, nullptr, tail);
			tail = tail->next;
		} else {
			head = createNode(val, nullptr, nullptr);
			tail = head;
		}
		nodes++;
	}

	void addNodeAfterHead(int val)
	{
		if (head) {
			Node* node;
			head->next = node = createNode(val, head->next, head);
			if (node->next) node->next->prev = node;
			nodes++;
		}
	}

	void addNodeAtGivenPosition(int index, int val)
	{
		if (index == 0) addNodeBeforeHead(val);
		if (index == nodes - 1) addNode(val);
		if (index == 0 || index == nodes - 1) return;

		if (index < nodes) {
			Node* node = head;
			for (int i = 0; i < index; i++) node = node->next;
			Node* newNode = createNode(val, node, node->prev);
			newNode->prev->next = newNode;
			node->prev = newNode;
			nodes++;
		}
	}

	void addNodeBeforeHead(int val)
	{
		Node* node = createNode(val, head, nullptr);
		head->prev = node;
		head = node;
		nodes++;
	}

	void removeSecondNode()
	{
		if (head && head->next) {
			Node* node = head->next;
			head->next = node->next;
			delete node;
			nodes--;
		}
	}

	void remove(int index)
	{
		if (index == 0) removeFirstNode();
		if (index == nodes - 1) removeLastNode();
		if (index == 0 || index == nodes - 1) return;

		if (index < nodes) {
			Node* node = head;
			for (int i = 0; i < index; i++) node = node->next;
			node->prev->next = node->next;
			node->next->prev = node->prev;
			delete node;
			nodes--;
		}
	}

	void removeFirstNode()
	{
		if (head) {
			Node* node = head;
			if (tail == head) tail = nullptr;
			head = head->next;
			delete node;
			nodes--;
		}
	}

	void removeLastNode()
	{
		if (nodes > 1) {
			Node* node = tail->prev;
			delete tail;
			tail = node;
			tail->next = nullptr;
			nodes--;
		} else {
			removeFirstNode();
		}
	}

	void DisplayList()
	{
		if (head) {
			Node* node = head;
			while (node) {
				cout << node->data << " | ";
				node = node->next;
			}
			cout << endl;
		}
	}

	int size()
	{
		return nodes;
	}

	bool empty()
	{
		return (nodes == 0);
	}
};

