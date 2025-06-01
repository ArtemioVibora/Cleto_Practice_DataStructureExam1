#include <iostream>

using namespace std;

const int MAX_SIZE = 3;
typedef int ELEMENT_TYPE;

bool isFull(int last) {
    if (last == MAX_SIZE - 1) {
        return true;
    }
    return false;
}

bool isEmpty(int last) {
    if (last == -1) {
        return true;
    }
    return false;
}

void addElement(ELEMENT_TYPE list[], int data, int pos, int &last) {
    if (isFull(last)) {
        cout << "The list is full" << endl;
    }
    else {
        for (int i = last; i >= pos; i--) {
            list[i + 1] = list[i];
        }
        list[pos] = data;
        ++last;
    }
}

void deleteElement(ELEMENT_TYPE list[], int pos, int &last) {
    if (isEmpty(last)) {
        cout << "The list is empty" << endl;
    }
    else {
        for (int i = pos; i < last; i++) {
            list[i] = list[i + 1];
        }
        --last;
    }
}