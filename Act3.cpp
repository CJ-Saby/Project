#include <iostream>
#include <limits>
using namespace std;

void initialize(int *row, int *column) {
    while(true) {
        cout << "Input row: ";
        cin >> *row;
        if(cin.fail()) {
            cout << "INVALID INPUT!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if(*row < 2) {
            cout << "MUST BE GREATER THAN OR EQUAL TO 2\n";
            continue;
        }
        else break;
    }
    while(true) {
        cout << "Input column: ";
        cin >> *column;
        if(cin.fail()) {
            cout << "INVALID INPUT!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if(*row < 2) {
            cout << "MUST BE GREATER THAN OR EQUAL TO 2\n";
            continue;
        }
        else break;
    }
}

int main() {
    int *array, row, column;
    initialize(&row, &column);
}
