#include <iostream>
#include <vector>
using namespace std;

class LIST {
protected:
    vector<int> list;
public:
    virtual void store() = 0;
    virtual void retrieve() = 0;
};

class stack : public LIST {
public:
    int data;

    void store(){
        cout << "Enter the value you wish to push onto the stack: ";
        cin >> data;
        list.push_back(data);
        cout << data << " pushed onto the stack" << endl;
    }
    void retrieve(){
        int last_element = list.back();
        if (last_element){
            cout << "Popped element: " << last_element << endl;
            list.pop_back();
        } else {
            cout << "Stack empty! No elements can be retrieved" << endl;
        }
    }
};

class queue : public LIST {
public:
    int data;

    void store(){
        cout << "Enter the value you wish to enqueue: ";
        cin >> data;
        list.push_back(data);
        cout << data << " enqueued" << endl;
    }

    void retrieve() {
    if (!list.empty()) {
        cout << list.front() << " dequeued";
        list.erase(list.begin());
        cout << endl;
    } else {
        cout << "Queue is empty! No elements can be retrieved" << endl;
    }
}

};

int main() {
    stack Stack;
    queue Queue;

    int choice;
    cout << "\nChoose an operation:\n"
             << "1. Store in Stack\n"
             << "2. Retrieve from Stack\n"
             << "3. Store in Queue\n"
             << "4. Retrieve from Queue\n"
             << "5. Exit\n";

    while (true) {
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                Stack.store();
                break;
            case 2:
                Stack.retrieve();
                break;
            case 3:
                Queue.store();
                break;
            case 4:
                Queue.retrieve();
                break;
            case 5:
                cout << "Exiting program\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5.\n";
                break;
        }
    }

    return 0;
}



