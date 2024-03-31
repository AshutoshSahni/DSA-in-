#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int value) : data(value), next(nullptr){};
};

class CircularLinkedList
{
private:
	Node *head;

public:
	CircularLinkedList() : head(nullptr){};

	// return size of circular linked list
	int get_size()
	{
		int count = 0;
		if (head != nullptr)
		{
			Node *temp = head;
			do
			{
				count++;
				temp = temp->next;
			} while (temp != head);
		}
		return count;
	}

	// insert at the end
	void insert_back(int data)
	{
		Node *new_node = new Node(data);

		if (head == nullptr)
		{
			head = new_node;
			new_node->next = head;
			return;
		}

		Node *temp = head;

		while (temp->next != head)
			temp = temp->next;

		temp->next = new_node;
		new_node->next = head;
	}

	// insert at first
	void insert_front(int data)
	{
		Node *new_node = new Node(data);
		if (head == nullptr)
		{
			head = new_node;
			new_node->next = head;
			return;
		}

		Node *temp = head;
		while (temp->next != head)
			temp = temp->next;

		temp->next = new_node;
		new_node->next = head;
		head = new_node;
	}

	// insert at given index
	void insert_at(int index, int data)
	{
		if (index > get_size())
		{
			cout << "INVALID INDEX!" << endl;
			return;
		}

		Node *new_node = new Node(data);
		Node *temp = head;

		while (--index)
			temp = temp->next;

		new_node->next = temp->next;
		temp->next = new_node;
	}

	// remove last element
	void remove_back()
	{
		if (head == nullptr)
		{
			cout << "list empty!";
			return;
		}

		if (get_size() == 1)
		{
			delete head;
			head = nullptr;
			return;
		}

		Node *temp = head;
		while (temp->next->next != head)
			temp = temp->next;

		temp->next = head;
	}

	// remove first element
	void remove_first()
	{
		if (head == nullptr)
		{
			cout << "List is empty!" << endl;
			return;
		}

		Node *toRemove = head;
		if (head->next == head)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node *temp = head;
			while (temp->next != head)
			{
				temp = temp->next;
			}
			temp->next = head->next;
			head = head->next;
			delete toRemove;
		}
	}

	// remove at particular index
	void remove_at(int index)
	{
		if (index > (get_size() - 1))
		{
			cout << "INVALID INDEX!";
			return;
		}

		Node *temp = head;
		while (--index)
			temp = temp->next;

		Node *toRemove = temp->next;
		temp->next = temp->next->next;
		delete toRemove;
	}

	// display list
	void display()
	{
		if (head == nullptr)
		{
			cout << "list empty!" << endl;
			return;
		}

		Node *temp = head;
		while (temp->next != head)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data;
		cout << endl;
	}
};

// driver code
int main()
{
	CircularLinkedList c;
	c.insert_back(2);
	c.insert_back(3);
	c.insert_back(4);
	c.insert_front(1);
	c.remove_first();
	c.insert_at(2, 5);
	c.remove_back();
	c.display();

	return 0;
}