#include <iostream>
#include <conio.h>

using namespace std;

class Stack {
public:
    void push(int p){
        if(isFull == false){
            stck[sp] = p;
            sp == 9 ? sp = 0 : sp++;
            sp == 0 ? flagsChecker("FULL") : flagsChecker("");
            isEmpty = false;
        }
    }

    int pop(){
        if(isEmpty == false){
            isFull ? sp = 9 : sp--;
            sp == 0 ? flagsChecker("EMPTY") : flagsChecker("");
            isFull = false;
            return stck[sp];
        }
    }

    void menu() {
        int choice;
        while(true){
            system("cls");
            log();
            cout << "isFull: " << isFull << endl << "isEmpty: " << isEmpty << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "1) Push" << endl;
            cout << "2) Pop" << endl;
            cout << "3) Exit" << endl << endl;
            cin >> choice;
            if(choice == 1){
                if(isFull) {
                    cout << "Stack is full, pop to be able to push again." << endl;
                    cout << "Enter any key to continue...";
                    getch();
                    continue;
                }
                int temp;
                cout << "Enter your number: ";
                cin >> temp;
                push(temp);
            }
            else if(choice == 2){
                if(isEmpty) cout << "Stack is empty, push to be able to pop again." << endl;
                else cout << "Popped " << pop() << " from the stack" << endl;
                cout << "Enter any key to continue...";
                getch();
            }
            else break;
        }
    }

    void log(){
        for(int i=9; i>=0; i--){
            cout << i << "       ";
            if (i >= sp){
                if (isFull) cout << stck[i];
                else cout << "X\t";
            }
            else cout << stck[i] << "\t";
            i == sp ? cout << "<-" << endl : cout << endl;
            cout << "    ---------" << endl;
        }
    }

private:
    int stck[10]; //Stack Storage
    int sp = 0; //Stack Pointer (Always pointing to the next EMPTY cell)
    bool isEmpty = true; //Empty Flag
    bool isFull = false; //Full Flag

    void flagsChecker(string status){
        if(status == "FULL") isFull = true;
        else if(status == "EMPTY") isEmpty = true;
    }
};

int main()
{
    Stack stck;
    stck.menu();
    return 0;
}
