#pragma once
#include <iostream>

using namespace std;

class CircularLinkedList
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
		node->next = next ? next : head;
		return node;
	}

	Node* nextNode(Node* node)
	{
		return (node->next == head) ? nullptr : node->next;
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
		if (index == 0) {
			removeFirstNode();
			return;
		}

		Node* node = head;

		while (node && --index)
			node = nextNode(node);

		if (index > 0) throw std::exception("out of bounds");

		if (node && node->next) {
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
			if (head != tail)
				tail->next = head = head->next;
			else
				head = tail = nullptr;
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
		if (tail == nullptr) return;

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
			tail->next = head;
			nodes--;
		}
	}

	CircularLinkedList()
	{
		head = tail = nullptr;
		nodes = 0;
	}

	~CircularLinkedList()
	{
		Node* node = head;
		Node* next;

		while (node) {
			next = node->next;
			delete node;
			node = nextNode(next);
		}
	}

	void addNodeBeforeHead(int val)
	{
		Node* newHead = createNode(val, head);
		head = newHead;
		if (tail)
			tail->next = head;
		else
			tail = head;
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

		while (node && --pos && node->next != head)
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
		Node* node = createNode(val, head);

		if (head) {
			tail->next = node;
			tail = node;
		} else {
			node->next = node;
			head = tail = node;
		}
		nodes++;
	}

	void insert(int index, int data)
	{
		if (head == NULL && index > 0) throw std::exception("out of bounds");

		if (index == 0) {
			addNodeBeforeHead(data);
			return;
		}

		Node* node = head;

		while (node && --index && node->next != head)
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
			node = nextNode(node);
		}

		cout << endl;
	}

	int size()
	{
		return nodes;
	}

	bool empty()
	{
		return (head == nullptr);
	}
};


