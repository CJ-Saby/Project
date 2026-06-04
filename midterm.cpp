#include <iostream>
#include <string>
#include <limits>
using namespace std;

class linkedlist {
    private:
        struct node {
            int node_number;
            double value;
            node *next;
        };
        string buffer; //string to convert to int
        node *head = nullptr; //first pointer
        node *current; //will point to the current pointer, important for traversal
        
    public:
        void InsertNode() {
            cout << "INSERT NODE\n\n";
            
            while(true) { //loop for input of the node #
                int itemp; //temporary variable for storing the value
                cout << "Input node #: ";
                getline(cin, buffer);
                if(buffer.length() == 0) {
                    cout << "Empty Input\n";
                }
                else {
                    try {
                        itemp = stoi(buffer); //converts string into int
                        if(itemp <= 0) {
                            cout << "Must be a positive number\n";
                            continue;
                        }
                    }
                    catch(invalid_argument&) { //catches any invalid input
                        cout << "Invalid Input. Please try again\n";
                        continue;
                    }
                    break;
                }
            }
            node *search = head;
            while(search != nullptr) { //searches for duplicates of node #
                if(search->node_number == itemp) {
                    cout << "Error: node #" << itemp << " already exists!\n";
                    return; //aborts the function
                }
                search = search->next;
            }
            
            //memory allocation
            if(head == nullptr) {
                head = new node;
                current = head;
                head->next = nullptr;
            }
            else {
                //making current look at the last node
                current = head;
                while(current->next != nullptr) {
                    current = current->next;
                }
                current->next = new node;
                current = current->next;
                current->next = nullptr;
            }
            current->node_number = itemp;
            
            while(true) { //input for the value
                cout << "Item        : ";
                cin >> current->value;
                if(cin.fail()) {
                    cout << "Invalid input. Please try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else if(current->value <= 0) {
                    cout << "Must be a positive number\n";
                    continue;
                }
                break;
            }
        }
        
        void DeleteNode() {
            cout << "DELETE NODE\n\n";
            int num;
            while(true) { //input validation loop
                cout << "Input node #: ";
                cin >> num;
                if(cin.fail()) {
                    cout << "Invalid input. Please try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else if(num <= 0) { //checks if input is positive
                    cout << "Must be a positive number\n";
                    continue;
                }
                break;
            }
            if(head == nullptr) { //if there are no nodes it goes here
                cout << "There aren't any nodes yet\n";
                return;
            }
            else {
                node *back = nullptr;
                node *search = head;
                double dtemp;
                while(search != nullptr) { //searches for the specified node #
                    if(search->node_number == num) { //idfk how to explain this ngl
                        if(search->next == nullptr && back == nullptr) {
                            dtemp = search->value;
                            head = nullptr;
                            delete search;
                            break;
                        }
                        else if(search->next == nullptr && back != nullptr) {
                            dtemp = search->value;
                            back->next = nullptr;
                            delete search;
                            break;
                        }
                        else if(search->next != nullptr && back == nullptr) {
                            dtemp = search->value;
                            head = search->next;
                            delete search;
                            break;
                        }
                        else {
                            node *front = search->next;
                            back->next = front;
                            dtemp = search->value;
                            delete search;
                            break;
                        }
                    }
                    back = search;
                    search = search->next;
                }
            }
        }
        
        void DisplayNodeItems() {
            cout << "DISPLAY LIST\n\n";
            cout << "Items in the list\n" << "(Format is \"node number : value\"\n";
            node *conductor = head;
            if(conductor == nullptr) {
                cout << "List is empty";
                return;
            }
            else {
                while(conductor->next != nullptr) { //traverses every node
                    cout << conductor->node_number << " : " << conductor->value << endl;
                    conductor = conductor->next; //advances to next pointer
                }
            }
        }
};
