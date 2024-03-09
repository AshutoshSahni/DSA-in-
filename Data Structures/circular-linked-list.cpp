#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int value) : data(value), next(nullptr) {};
};

class CircularLinkedList {
private:
	Node* head;
public:
	CircularLinkedList() : head(nullptr) {};
	
	// insert at the end
	void insert_back(int data) {
		Node* new_node = new Node(dat);
		
		if(head == nullptr) {
			head = new_node;
			new_node->next = head;
			return;
		}

		Node* temp = head;

		while(temp->next != head) temp = temp->next;
		
		temp->next = new_node;
		new_node->next = head;
	}

	// display list
	void display() {
		if(head == nullptr) {
			cout << "list empty!" << endl;
			return;
		}
	}
}
