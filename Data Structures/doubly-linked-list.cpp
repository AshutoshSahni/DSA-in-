#include <iostream>
using namespace std;

// create node
class Node
{
public:
	int data;
	Node *next;
	Node *prev;

	Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// linked list operations
class DoublyLinkedList
{
private:
	Node *head;

public:
	DoublyLinkedList() : head(nullptr) {}

	// get size
	int get_size()
	{
		if (head == nullptr)
			return 0;

		int size = 0;
		Node *temp = head;
		while (temp != nullptr)
		{
			size++;
			temp = temp->next;
		}

		return size;
	}

	// insert at the end
	void insert_back(int data)
	{
		Node *new_node = new Node(data);

		if (get_size() == 0)
			head = new_node;
		else
		{
			Node *temp = head;
			while (temp->next != nullptr)
				temp = temp->next;

			temp->next = new_node;
			new_node->prev = temp;
		}
	}

	// insert at front
	void insert_front(int data)
	{
		Node *new_node = new Node(data);

		if (head == nullptr)
			head = new_node;
		else
		{
			new_node->next = head;
			head->prev = new_node;
			head = new_node;
		}
	}

	// insert at n-th index
	void insert_at(int data, int index)
	{
		int lastIdx = get_size() - 1;
		if ((index < 0) || (index - lastIdx) > 1)
		{
			cout << "INVALID INDEX" << endl;
			return;
		}

		index--;
		Node *new_node = new Node(data);
		Node *temp = head;
		while (index--)
			temp = temp->next;

		new_node->prev = temp;
		new_node->next = temp->next;
		temp->next->prev = new_node;
		temp->next = new_node;
	}

	// remove from the end
	void remove_back()
	{
		if (head == nullptr)
		{
			cout << "Nothing to remove. List empty!" << endl;
			return;
		}

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}

		Node *temp = head;

		while (temp->next->next != nullptr)
			temp = temp->next;

		temp->next->prev = nullptr;
		temp->next = nullptr;
	}

	// remove from the front
	void remove_front()
	{
		if (head == nullptr)
		{
			cout << "Nothing to remove. List empty!";
			return;
		}

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}

		head->next->prev = nullptr;
		head = head->next;
	}

	// remove at particular index
	void remove_at(int index)
	{
		if (head == nullptr)
		{
			cout << "Nothing to remove. List empty!" << endl;
			return;
		}

		if (index > get_size() - 1)
		{
			cout << "INDEX OUT OF RANGE!" << endl;
			return;
		}

		if (index == 0)
		{
			head->next->prev = nullptr;
			head = head->next;
			return;
		}

		Node *temp = head;
		while (--index)
			temp = temp->next;

		if(temp->next->next != nullptr) {
			temp->next->next->prev = temp;
			temp->next = temp->next->next;
		} else {
			temp->next->prev = nullptr;
			temp->next = nullptr;
		}
	}

	// display linked list
	void display()
	{
		if (get_size() == 0)
		{
			cout << "List empty!" << endl;
			return;
		}

		Node *temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main()
{
	DoublyLinkedList l;

	l.insert_back(1);
	l.insert_back(2);
	l.insert_back(3);
	l.insert_front(9);
	l.insert_front(8);
	l.insert_at(4, 2);
	l.remove_back();
	l.remove_front();
	l.remove_at(2);

	l.display();

	return 0;
}
