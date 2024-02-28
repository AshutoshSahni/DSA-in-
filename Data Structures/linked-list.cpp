#include <iostream>
using namespace std;

// create a node
class Node {
public:
	int data;
	Node* next;

	//constructor to initialize value to new node
	Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
	Node* head;

public:
	LinkedList() : head(nullptr) {}

	//get list size
	int get_size() {
		if(head == nullptr) return 0;
		
		int size = 0;
		Node* temp = head;
		while(temp != nullptr) {
			size++;
			temp = temp->next;
		}

		return size;
	}

	//insert at the end
	void insert_end(int data) {
		Node* new_node = new Node(data);
		if(head == nullptr) head = new_node;
		else {
			Node* temp = head;
			while(temp->next != nullptr) temp = temp->next;
			temp->next = new_node;
		}
	}

	//insert at front
	void insert_front(int data) {
		Node* new_node = new Node(data);
		if(head == nullptr) head = new_node;
		else {
			new_node->next = head;
			head = new_node;
		}
	}

	//insert at n-th index
	void insert_at(int data, int index) {
		if(head == nullptr || index > get_size()) {
			cout << "INVALID INSERT INDEX!" << endl;
			return;
		}

		Node* new_node = new Node(data);
		Node* temp = head;

		while(--index)
			temp = temp->next;

		new_node->next = temp->next;
		temp->next = new_node;
	}

	//delete from the end
	void delete_end() {
		if(head == nullptr) {
			cout << "Linked List Empty!" << endl;
			return;
		}

		if (head->next == nullptr) {
			delete head;
			head = nullptr;
			return;
		}

		Node* temp = head;

		while(temp->next->next != nullptr) temp = temp->next;
		temp->next = nullptr;
	}

	//delete from front
	void delete_front() {
		if(head == nullptr) {
			cout << "Linked List Empty!" << endl;
			return;
		}

		head = head->next;
	}

	//delete at n-th index
	void delete_at(int index) {
		if(head == nullptr || index > get_size()) {
			cout << "DELETION INDEX INVALID!" << endl;
			return;
		}

		Node* temp = head;
		while(--index)
			temp = temp->next;

		temp->next = temp->next->next;
	}

	// check if particular element is present in linked list
	bool search(int searchElement) {
		if(head == nullptr) {
			cout << "Linked List Empty!" << endl;
			return false;
		}

		Node* temp = head;
		while (temp != nullptr) {
			if(temp->data == searchElement)
				return true;

			temp = temp->next;
		}
		
		return false;
	}

	//display linked list
	void display() {
		if(!head) {
			cout << "list empty!";
			return;
		}

		Node* temp = head;
		while(temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	LinkedList list;
	
	list.insert_end(5);
	list.insert_end(1);
	list.insert_end(8);
	list.insert_end(2);
	list.delete_end();
	list.insert_front(4);
	list.delete_front();
	list.insert_at(7, 2);
	list.delete_at(2);

	if(list.search(9)) 
		cout << "Element exist!" << endl;
	else 
		cout << "Element doesn't exit!" << endl;

	list.display();

	return 0;
}
