#include <iostream>
using namespace std;

#define MAXSIZE 10

class Queue {
private:
	int items[MAXSIZE];
	int front, rear;
public:
	Queue() {
		front = -1;
		rear = -1;
	}

	//check if stack is full
	bool isFull() {
		if(front == 0 && rear == MAXSIZE - 1)
			return true;
		return false;
	}
	
	//check if stack is empty
	bool isEmpty() {
		if(front == -1)
			return true;
		return false;
	}

	// insert element
	void enqueue(int data) {
		if(isFull()) {
			cout << "Queue full! Cannot insert" << endl;
			return;
		}
		
		// for the insertion of first elemnt
		if(front == -1) 
			front = 0;
		
		rear++;
		items[rear] = data;
		cout << data << " inserted" << endl;
	}

	// remove element
	void dequeue() {
		if(isEmpty()) {
			cout << "Queue empty!";
			return;
		}
		
		cout << items[front] << " removed" << endl;

		front++;
		
		// reset queue if no element left in queue
		if(front == rear)
			front = rear = -1;
	}

	// display queue
	void display() {
		if(isEmpty()) {
			cout << "Queue is empty!" << endl;
			return;
		}

		for(int i = front; i <= rear; i++) 
			cout << items[i] << " ";
		cout << endl;
	}
};

int main() {
	Queue q;

	q.enqueue(5);
	q.enqueue(9);
	q.enqueue(3);
	q.dequeue();
	q.enqueue(7);
	q.enqueue(2);
	q.display();
	
	return 0;
}
