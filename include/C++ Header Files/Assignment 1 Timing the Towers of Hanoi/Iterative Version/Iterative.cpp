// Hollyn White
// CS372: Data Structures
// File name: Iterative.cpp
// Assignment 1: Timing the Towers of Hanoi

#include <iostream>
#include <chrono>
#include <stack>
#include <cmath>
using namespace std;

void moveDisks(int, stack<int>&, stack<int>&, stack<int>&);
void MoveDisksHelper(stack<int>&, stack<int>&, char, char);

int main() {
    cout << "Iteratively\n\n";
    for (int numdisks : {5, 10, 15, 20, 25, 30, 35}) {
        stack<int> source;
        stack<int> dest;
        stack<int> aux;
        auto start = chrono::high_resolution_clock::now();
        moveDisks(numdisks, source, aux, dest);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;

        cout << "Number of discs: " << numdisks << "\nElapsed Time: "
            << elapsed.count() << "\n\n";
    }
    return 0;
}

void moveDisks(int num, stack<int>& fromPeg, stack<int>& tempPeg, stack<int>& toPeg) {
    char s = 'S', d = 'D', a = 'A';
    if (num % 2 == 0) { // Swap in num disks is even.
        char temp = d;
        d = a;
        a = temp;
    }
    int numberOfMoves = pow(2, num) - 1;
    for (int i = num; i >= 1; i--) {
        fromPeg.push(i);
    }
    // now do moves:
    for (int i = 1; i <= numberOfMoves; i++) {
        if (i % 3 == 0) {
            MoveDisksHelper(tempPeg, toPeg, a, d);
        }
        else if (i % 3 == 2) {
            MoveDisksHelper(fromPeg, tempPeg, s, a);
        }
        else if (i % 3 == 1) {
            MoveDisksHelper(fromPeg, toPeg, s, d);
        }
    }
}

void MoveDisksHelper(stack<int>& source, stack<int>& dest, char s, char d) {
    int top1;
    int top2;
    if (source.empty()) {
        top2 = dest.top();
        dest.pop();
        source.push(top2);
    }
    else if (dest.empty()) {
        top1 = source.top();
        source.pop();
        dest.push(top1);
    }
    else if (source.top() > dest.top()) {
        top1 = source.top();
        source.pop();
        top2 = dest.top();
        dest.pop();
        source.push(top1);
        source.push(top2);
    }
    else {
        top2 = dest.top();
        dest.pop();
        top1 = source.top();
        source.pop();
        dest.push(top2);
        dest.push(top1);
    }
}

