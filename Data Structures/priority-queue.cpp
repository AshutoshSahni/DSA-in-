#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> pq;

public:
    //to arrage all the elements according to priority
    void heapify(int i) {
        int size = pq.size();
        int largest = i;
        int leftChild = 2*i + 1;
        int rightChild = 2*i + 2;

        if(leftChild < size && pq[leftChild] > pq[largest])
            largest = leftChild;
        if(rightChild < size && pq[rightChild] > pq[largest])
            largest = rightChild;

        if(largest != i) {
            swap(pq[i], pq[largest]);
            heapify(largest);
        }
    }

    //insertion
    void insert(int data) {
        int size = pq.size();

        if(size == 0) pq.push_back(data);
        else {
            pq.push_back(data);
            for(int i = size / 2 - 1; i >= 0; i--)
                heapify(i);
        }
    }

    //deleteion
    void deleteNode(int data) {
        int size = pq.size();
        int i;

        for(i = 0; i < size; i++) {
            if(pq[i] == data)
                break;
        }

        swap(pq[i], pq[size - 1]);
        pq.pop_back();

        for(int i = size/2 - 1; i >= 0; i--)
            heapify(i);
    }

    //print
    void display() {
        int size = pq.size();
        for(int i = 0; i < size; i++)
            cout << pq[i] << " ";
    }
};

int main() {
    PriorityQueue p;
    p.insert(3);
    p.insert(4);
    p.insert(9);
    p.insert(5);
    p.insert(2);
    p.display();
    return 0;
}