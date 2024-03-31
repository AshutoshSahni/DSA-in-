#include <bits/stdc++.h>
using namespace std;

class Heap
{
private:
    vector<int> heap;

public:
    // swap
    void swap(int *a, int *b)
    {
        int temp = *b;
        *b = *a;
        *a = temp;
    }

    // heapify the tree
    void heapify(int i)
    {
        int size = heap.size();
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && heap[largest] < heap[left])
            largest = left;
        if (right < size && heap[largest] < heap[right])
            largest = right;

        if (i != largest)
        {
            swap(&heap[largest], &heap[i]);
            heapify(largest);
        }
    }

    // insertion
    void insert(int data)
    {
        if (heap.size() == 0)
            heap.push_back(data);
        else
        {
            heap.push_back(data);
            for (int i = heap.size() / 2 - 1; i >= 0; i--)
                heapify(i);
        }
    }

    // delete node
    void remove(int data)
    {
        int size = heap.size();
        int i = 0;
        for (; i < size; i++)
        {
            if (heap[i] == data)
                break;
        }
       
       if(i == size)
       {
        cout << "Element not found in heap!" << endl;
        return;
       }

       swap(&heap[i], &heap[size - 1]);
       heap.pop_back();
    }

    // print the heap
    void print()
    {
        if (heap.size() == 0)
        {
            cout << "Heap empty!" << endl;
            return;
        }

        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main()
{
    Heap h;
    h.insert(3);
    h.insert(4);
    h.insert(9);
    h.insert(5);
    h.insert(2);
    h.print();
    h.remove(4);
    h.print();

    return 0;
}