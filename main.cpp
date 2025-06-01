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
        for (int i = pos; i <= last; i++) {
            list[i] = list[i + 1];
        }
        --last;
    }
}

void locateItem(ELEMENT_TYPE list[], ELEMENT_TYPE searchData, int last) {

    if (isEmpty(last)) {
        cout << "The list is empty" << endl;
    }
    else {
        int index = 0;
        //READABILITY IS IMPORTANT SO STICK WITH CURLY BRACES
        while (index != last + 1 && list[index] != searchData) {
            ++index;
        }
        if (index != last + 1) {
            cout << "Item Requested is item " << index + 1 << endl;
        }
        else {
            cout << "Item does not exist" << endl;
        }

    }
}

void printList(ELEMENT_TYPE list[], int last) {

    if (isEmpty(last)) {
        cout << "NIL" << endl;
    }
    else {
        for (int i = 0; i <= last; i++) {
            cout << list[i] << endl;
        }
    }
}

int main() {
    ELEMENT_TYPE list[MAX_SIZE];
    int last = -1;
    addElement(list, 13, 0, last);
    addElement(list, 2, 1, last);
    printList(list, last);
    locateItem(list, 13, last);

}