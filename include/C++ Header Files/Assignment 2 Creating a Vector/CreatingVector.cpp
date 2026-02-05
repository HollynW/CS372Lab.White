// Hollyn White
// Class: CS372 Data Structures
// Assignment 2: Your First Containers: Vectors, Arrays, 
// and Here's A Different Type of Bag
// File: CreatingVector.cpp

#include <iostream>
#include <chrono>
using namespace std;

class Vector 
{
private:
    int* data;
    int capacity;
    int size;

    void resize() 
    {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    Vector() 
    {
        capacity = 2;
        size = 0;
        data = new int[capacity];
    }

    ~Vector() 
    {
        delete[] data;
    }

    void push_back(int value)
    {
        if (size == capacity)
        {
            resize();
        }
        data[size++] = value;
    }
};

int main() 
{
    cout << "How long it takes to add these elements to the underlying dynamic array (milliseconds).\n\n";
    for (int n = 2; n <= (1 << 14); n *= 2) 
    {  
        Vector v;
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++) 
        {
            v.push_back(i);
        }

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> elapsed = end - start;
        cout << "Number: " << n
            << "\nTime: " << elapsed.count() << " ms\n\n";
    }
    return 0;
}
