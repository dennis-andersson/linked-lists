#pragma once
#include <iostream>

using namespace std;

class LinkedList
{
	struct Node
	{
		int data;
		Node* next;
	};

private:
	Node* head;
	Node* tail;
	int nodes;

	Node* createNode(int value, Node* next = nullptr)
	{
		Node* node = new Node;
		node->data = value;
		node->next = next;
		return node;
	}

public:
	// Task 1: Delete 2nd node
	void removeSecondNode()
	{
		if (head && head->next) {
			Node* node = head->next;
			head->next = node->next;
			delete node;
			nodes--;
		}
	}

	// Task 2: Delete specified node
	void remove(int index)
	{
		Node* node = head;

		for (int i = 0; node && --index; i++)
			node = node->next;

		if (index > 0) throw std::exception("out of bounds");

		if (node) {
			Node* next = node->next->next;
			delete node->next;
			node->next = next;
			nodes--;
		}
	}

	// Task 3: Delete first node
	void removeFirstNode()
	{
		if (head) {
			Node* node = head;
			head = head->next;
			delete node;
			nodes--;
		}
	}

	// Task 4: Delete entire list by deleting last node at a time
	void deleteList()
	{
		while (head) removeLastNode();
	}

	void removeLastNode()
	{
		if (!tail) return;

		if (head == tail) {
			delete tail;
			head = tail = nullptr;
			nodes--;
			return;
		}

		Node* node = head;

		while (node && node->next != tail)
			node = node->next;

		if (node) {
			delete tail;
			tail = node;
			tail->next = nullptr;
			nodes--;
		}
	}

	LinkedList()
	{
		head = tail = nullptr;
		nodes = 0;
	}

	~LinkedList()
	{
		Node* node = head;
		Node* next;

		while (node) {
			next = node->next;
			delete node;
			node = next;
		}
	}

	void addNodeBeforeHead(int val)
	{
		Node* newHead = createNode(val, head);
		head = newHead;
		if (!tail) tail = head;
		nodes++;
	}

	void addNodeAtGivenPosition(int pos, int val)
	{
		if (pos < 0) throw std::exception("bad index");

		if (pos == 0) {
			addNodeBeforeHead(val);
			return;
		}

		Node* node = head;

		while (node && --pos)
			node = node->next;

		if (pos > 0) throw std::exception("out of bounds");

		Node* newNode = createNode(val, node->next);
		node->next = newNode;
		nodes++;
	}

	void addNodeAfterHead(int val)
	{
		if (head) {
			Node* newNode = createNode(val, head->next);
			head->next = newNode;
			nodes++;
		} else {
			addNode(val);
		}
	}

	void addNode(int val)
	{
		Node* node = createNode(val, nullptr);

		if (head) {
			tail->next = node;
			tail = node;
		} else {
			head = tail = node;
		}
		nodes++;
	}

	void insert(int index, int data)
	{
		if (head == nullptr && index > 0) throw std::exception("out of bounds");

		if (index == 0) {
			addNodeBeforeHead(data);
			return;
		}

		Node* node = head;

		while (node && --index)
			node = node->next;

		if (index > 0) throw std::exception("out of bounds");

		Node* newNode = createNode(data, node->next);
		node->next = newNode;
		nodes++;
	}

	void DisplayList()
	{
		Node* node = head;

		while (node) {
			cout << node->data << " | ";
			node = node->next;
		}

		cout << endl;
	}

	int size()
	{
		return nodes;
	}

	bool empty()
	{
		return (head == NULL);
	}
};

