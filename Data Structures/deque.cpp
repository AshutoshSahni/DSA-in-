#include <iostream>
using namespace std;

#define MAXSIZE 8

class Deque {
private:
	int arr[MAXSIZE];
	int front, rear;

public:
	Deque() {
		front = -1;
		rear = -1;
	}

	bool isFull();
	bool isEmpty();
	void push_front(int data);
	void push_rear(int data);
	void pop_front();
	void pop_rear();
	int get_front();
	int get_rear();
	void display();
};

// is deque full
bool Deque::isFull() {
	return ((front == 0 && rear == MAXSIZE - 1) || (front == rear + 1));
}

// is deque empty
bool Deque::isEmpty() {
	return (front == -1);
}

// insert from front
void Deque::push_front(int data) {
	if(isFull()) cout << "Overflow!" << endl;
	else if(front == -1) front = rear = 0;
	else if(front == 0) front = MAXSIZE - 1;
	else front--;

	arr[front] = data;
	cout << "inserted at front: " << data << endl;
}

// insert from rear
void Deque::push_rear(int data) {
	if(isFull()) cout << "Overflow!" << endl;
	else if(front == -1) front = rear = 0;
	else if(rear == MAXSIZE - 1) rear = 0;
	else rear++;

	arr[rear] = data;
	cout << "inserted at rear: " << data << endl;
}

// delete from front
void Deque::pop_front() {
	if(isEmpty()) cout << "Underflow!" << endl;
	else if(front == rear) front = rear = -1;
	else if(front == MAXSIZE - 1) front = 0;
	else front++;

	cout << "element popped from front" << endl;
}

// delete from rear
void Deque::pop_rear() {
	if(isEmpty()) cout << "Underflow!" << endl;
	else if(front == rear) front = rear = -1;
	else if(rear == 0) rear = MAXSIZE - 1;
	else rear--;

	cout << "element popped from rear" << endl;
}

// return the element at 'front'
int Deque::get_front() {
	if(isEmpty()) {
		cout << "Deque empty!" << endl;
		return -1;
	}
	return arr[front];
}

// return element at 'rear'
int Deque::get_rear() {
	if(isEmpty()) {
		cout << "Deque empty!" << endl;
		return -1;
	}
	return arr[rear];
}

// print deque
void Deque::display() {
	if(isEmpty()) {
		cout << "Deque empty!" << endl;
		return;
	}

	for(int i = front; i != (rear + 1) % MAXSIZE; i = (i + 1) % MAXSIZE)
		cout << arr[i] << " ";
	cout << endl;
}

/* driver code */
int main() {
	Deque d;
	d.push_front(20);
	d.push_front(10);
	d.push_rear(30);
	d.push_rear(50);
	d.push_rear(80);
	d.display();
	d.get_front();
	d.get_rear();
	d.pop_front();
	d.pop_rear();
	d.display();

	return 0;
}






