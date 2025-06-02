#include <iostream>

using namespace std;

const int MAX_SIZE = 10;
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

void addElement(ELEMENT_TYPE list[], ELEMENT_TYPE data, int pos, int &last) {
    if (isFull(last)) {
        cout << "The list is full" << endl;
    }
    else if (pos > last + 1) {
        cout << "Cannot add element due to position exceeding last" << endl;
        cout << "Last is " << last + 1 << endl;
    }
    else {
        //If last == -1 and pos = 0
        //For loop would not work
        //if last == 0 and pos == 0
        //For loop would work with only 1 iteration

        for (int i = last; i >= pos; i--) {
            //list[i + 1] == 1 if i = 0
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
    else if (pos > last) {
        cout << "Cannot delete data of which the index does not exist" << endl;
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

int promptData() {
    int data;
    cout << "Enter data: ";
    while (!(cin >> data)) {
        cin.clear();
        cin.ignore(80, '\n');
        cout << "Enter data: ";
    }

    return data;
}

int promptPosition() {
    int pos;
    cout << "Enter position: ";
    while (!(cin >> pos) || pos > MAX_SIZE || pos < 0) {
        cin.clear();
        cin.ignore(80, '\n');
        cout << "Enter position: ";
    }
    return pos;
}

void optionsDisplay(int last) {
    cout << endl;
    cout << "--------------------------------" << endl;
    cout << "<1> Add" << endl;
    cout << "<2> Delete" << endl;
    cout << "<3> Locate" << endl;
    cout << "<4> Print All" << endl;
    cout << "<5> Exit" << endl;
    cout << "--------------------------------" << endl;
    cout << "There are " << last + 1 << " in the list." << endl;

}

void runProgram() {
    ELEMENT_TYPE list[MAX_SIZE];
    int last = -1;
    int pos, data, searchData;
    int input = 0;
    while (input != 5) {
        optionsDisplay(last);
        cout << ">>>>";
        while (!(cin >> input)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error!" << endl;
            optionsDisplay(last);
            cout << ">>>>";
        }
        switch (input) {
            case 1:
                cout << "You picked Add" << endl;
                data = promptData();
                pos = promptPosition();
                addElement(list, data, pos, last);
                break;
            case 2:
                cout << "You picked Delete" << endl;
                pos = promptData();
                deleteElement(list, pos, last);
                break;
            case 3:
                cout << "You picked Locate" << endl;
                searchData = promptData();
                locateItem(list, searchData, last);
                break;
            case 4:
                cout << "You picked PrintAll" << endl;
                printList(list, last);
                break;
            default:
                break;
        }


    }

}


int main() {
    runProgram();

}