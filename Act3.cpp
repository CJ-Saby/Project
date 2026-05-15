#include <iostream>
#include <limits>
#include <string>
using namespace std;

void initialize(int *row, int *column) {
    string buffer;
    while(true) {
        cout << "Input row: ";
        getline(cin, buffer);
        if(buffer.length() == 0) {
            cout << "There is nothing there!\n";
            continue;
        }
        else {
            try {
            *row = stoi(buffer);
            if(*row < 2) {
                cout << "MUST BE GREATER THAN OR EQUAL TO 2\n";
                continue;
            }
            else break;
            }
            catch(invalid_argument&) {
                std::cout << "Invalid input! try again\n";
                continue;
            }
        }
    }
    while(true) {
        cout << "Input column: ";
        getline(cin, buffer);
        if(buffer.length() == 0) {
            cout << "There is nothing there!\n";
            continue;
        }
        else {
            try {
                *column = stoi(buffer);
                if(*column < 2) {
                    cout << "MUST BE GREATER THAN OR EQUAL TO 2\n";
                    continue;
                }
                else break;
            }
            catch(invalid_argument&) {
                cout << "Invalid input! try again\n";
                continue;
            }
        }
    }
}

void fillarray(int *array, int &row, int &column) {
    cout << "Input for the matrix:\n";
    for(int j = 0;j < row;j++) {
        for(int i = 0;i < column;i++) {
            cin >> array[j * column + i];
            if(cin.fail()) {
                cout << "INVALID INPUT!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                i--;
            }
        }
    }
}

int main() {
    int *array, row, column;
    initialize(&row, &column);
    array = new int[row * column];
    fillarray(array, row, column);
}
