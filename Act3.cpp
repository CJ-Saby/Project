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

void displaymatrix(int *array, int &row, int &column) {
    // compute row sums
    int *rowSum = new int[row];
    for(int j = 0; j < row; j++) {
        rowSum[j] = 0;
        for(int i = 0; i < column; i++) {
            rowSum[j] += array[j * column + i];
        }
    }

    // compute column sums
    int *colSum = new int[column];
    for(int i = 0; i < column; i++) {
        colSum[i] = 0;
        for(int j = 0; j < row; j++) {
            colSum[i] += array[j * column + i];
        }
    }

    // compute diagonals if square
    int mainDiag = 0, antiDiag = 0;
    if(row == column) {
        for(int k = 0; k < row; k++) {
            mainDiag += array[k * column + k];
            antiDiag += array[k * column + (column - 1 - k)];
        }
    }

    cout << "\nRow-Column Matrix\n";

    // display matrix rows + row sum at end
    for(int j = 0; j < row; j++) {
        for(int i = 0; i < column; i++) {
            cout << array[j * column + i] << " ";
        }
        cout << rowSum[j] << "\n";
    }

    // display column sums on last row
    for(int i = 0; i < column; i++) {
        cout << colSum[i] << " ";
    }

    // if square, display main diagonal sum at the corner
    if(row == column) {
        cout << mainDiag;
    }
    cout << "\n";

    // display anti-diagonal sum if square
    if(row == column) {
        cout << "Anti-diagonal sum: " << antiDiag << "\n";
    }

    delete[] rowSum;
    delete[] colSum;
}

int main() {
    string choice;
    while(true) {
        int *array, row, column;
        initialize(&row, &column);
        array = new int[row * column];
        fillarray(array, row, column);
        displaymatrix(array, row, column);

        delete[] array;

        // consume leftover newline from cin >> in fillarray
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while(true) {
            cout << "\nTry Again? Y/N: ";
            getline(cin, choice);
            if(choice == "Y" || choice == "y" || choice == "N" || choice == "n") break;
            cout << "Invalid input! Enter Y or N only.\n";
        }

        if(choice == "N" || choice == "n") break;
    }
    return 0;
}
