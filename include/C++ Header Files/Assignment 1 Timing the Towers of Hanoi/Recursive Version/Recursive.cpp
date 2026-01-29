// Hollyn White
// CS372: Data Structures
// File name: Recursive.cpp
// Assignment 1: Timing the Towers of Hanoi

#include <iostream>
#include <chrono>
using namespace std;

void moveDisks(int, int, int, int);

int main() {
    cout << "Recursively\n\n";

    const int FROMPEG = 1;
    const int TOPEG = 3;
    const int TEMPPEG = 2;
    for (int numdisks : {5, 10, 15, 20, 25, 30, 35}) {
        auto start = chrono::high_resolution_clock::now();
        moveDisks(numdisks, FROMPEG, TOPEG, TEMPPEG);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;

        cout << "Number of discs: " << numdisks << "\nElapsed Time: "
            << elapsed.count() << "\n\n";
    }
    return 0;
}

void moveDisks(int num, int fromPeg, int toPeg, int tempPeg) {
    if (num > 0) {
        moveDisks(num - 1, fromPeg, tempPeg, toPeg);
        moveDisks(num - 1, tempPeg, toPeg, fromPeg);
    }
}
