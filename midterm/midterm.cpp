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
        string buffer;
        node *head = nullptr;
        node *current;
        
    public:
        void InsertNode() {
            cout << "INSERT NODE\n\n";
            
            int itemp;
            while(true) {
                cout << "Input node #: ";
                getline(cin, buffer);
                if(buffer.length() == 0) {
                    cout << "Empty Input\n";
                }
                else {
                    try {
                        itemp = stoi(buffer);
                        if(itemp <= 0) {
                            cout << "Must be a positive number\n";
                            continue;
                        }
                    }
                    catch(invalid_argument&) {
                        cout << "Invalid Input. Please try again\n";
                        continue;
                    }
                    break;
                }
            }
            node *search = head;
            while(search != nullptr) {
                if(search->node_number == itemp) {
                    cout << "Error: node #" << itemp << " already exists!\n";
                    return;
                }
                search = search->next;
            }
            
            if(head == nullptr) {
                head = new node;
                current = head;
                head->next = nullptr;
            }
            else {
                current = head;
                while(current->next != nullptr) {
                    current = current->next;
                }
                current->next = new node;
                current = current->next;
                current->next = nullptr;
            }
            current->node_number = itemp;
            
            while(true) {
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Node #" << itemp << " successfully inserted.\n";
        }
        
        void DeleteNode() {
            cout << "DELETE NODE\n\n";
            int num;
            while(true) {
                cout << "Input node #: ";
                cin >> num;
                if(cin.fail()) {
                    cout << "Invalid input. Please try again\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else if(num <= 0) {
                    cout << "Must be a positive number\n";
                    continue;
                }
                break;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(head == nullptr) {
                cout << "There aren't any nodes yet\n";
                return;
            }
            else {
                node *back = nullptr;
                node *search = head;
                double dtemp;
                bool found = false;
                while(search != nullptr) {
                    if(search->node_number == num) {
                        found = true;
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
                if(found) {
                    cout << "Deleted Item : " << dtemp << "\n";
                    cout << "Node #" << num << " successfully deleted.\n";
                }
                else {
                    cout << "Node #" << num << " not found.\n";
                }
            }
        }
        
        void DisplayNodeItems() {
            cout << "DISPLAY LIST\n\n";
            cout << "Items in the list\n" << "(Format is \"node number : value\")\n";
            node *conductor = head;
            if(conductor == nullptr) {
                cout << "List is empty\n";
                return;
            }
            else {
                while(conductor != nullptr) {
                    cout << conductor->node_number << " : " << conductor->value << endl;
                    conductor = conductor->next;
                }
            }
        }
};
 
int main() {
    linkedlist list;
    string choice;
 
    while(true) {
        cout << "\nMAIN MENU\n\n";
        cout << "[I] Insert Node\n";
        cout << "[D] Delete Node\n";
        cout << "[L] Display Node Items\n";
        cout << "[E] Exit\n\n";
        cout << "Choice : [ ";
        getline(cin, choice);
        cout << "]\n\n";
 
        if(choice.length() == 0) {
            cout << "Empty input. Please try again.\n";
            continue;
        }
        if(choice.length() > 1) {
            cout << "Invalid choice. Please enter I, D, L, or E only.\n";
            continue;
        }
 
        char c = toupper(choice[0]);
 
        if(c == 'I') {
            list.InsertNode();
        }
        else if(c == 'D') {
            list.DeleteNode();
        }
        else if(c == 'L') {
            list.DisplayNodeItems();
        }
        else if(c == 'E') {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice. Please enter I, D, L, or E only.\n";
        }
    }
 
    return 0;
}
