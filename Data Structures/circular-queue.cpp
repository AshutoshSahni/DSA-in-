/* circular queue */

#include <iostream>
using namespace std;

#define MAXSIZE 8

class CircluarQueue {
private:
    int items[MAXSIZE];    
    int front, rear;

public:
    CircluarQueue() {
        front = -1;
        rear = -1;
    }

    // check if circular queue is full
    bool isFull() {
        if(front == 0 && rear == MAXSIZE - 1)
            return true;
        return false;
    }

    // check if circular queue is empty
    bool isEmpty() {
        if(front == -1) 
            return true;
        return false;
    }

    //insert element
    void enqueue(int data) {
        if(isFull()) {
            cout << "Queue full! Cannot insert" << endl;
            return;
        }

        // for the first element insertion
        if(front == -1) front = 0;
        rear = (rear + 1) % MAXSIZE;
        items[rear] = data;
        cout << data << " inserted" << endl;
    }

    //delete element
    void dequeue() {
        if(isEmpty()) {
            cout << "Queue Empty! Cannot remove" << endl;
            return;
        }

        cout << items[front] << " removed" << endl;
        front = (front + 1) % MAXSIZE;
        if (front == rear) front = rear = -1;
    }

    //print circular queue
    void display() {
        if(isEmpty()) {
            cout << "Queue Empty!" << endl;
            return;
        }

        int i;
        for(i = front; i != rear; i = (i + 1) % MAXSIZE) 
            cout << items[i] << " ";
        cout << items[i];
        
    }
};

int main() {
    CircluarQueue cq;
    cq.enqueue(5);
    cq.enqueue(8);
    cq.enqueue(1);
    cq.enqueue(3);
    cq.dequeue();
    cq.enqueue(2);
    cq.dequeue();
    cq.display();

    return 0;
}