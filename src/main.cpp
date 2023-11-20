#include "../include/linked_list.h"
#include "../include/my_stack.h"
#include <iostream>

using namespace std;

int main() {
    int test_case = 0;
    cin >> test_case;
    LinkedList ll1({1,2,3,4,5,6,7,8,9,10});
    LinkedList ll2({1,2,3,4,5,6,7,8,9,10});

    MyStack st1({1,2,3,4,5,6,7,8,9,10});
    MyStack st2({1,2,3,4,5,6,7,8,9,10});
    
    switch (test_case) {
        case 1:
            cout << "ll1: ";
            ll1.printlist();
            cout << "ll2: ";
            ll2.printlist();

            cout << "ll1 == ll2: " << (ll1 == ll2) << endl;

            ll1.head->val = 100;
            cout << "ll1: ";
            ll1.printlist();
            cout << "ll2: ";
            ll2.printlist();

            break;
        
        case 2:
            cout << "st1: ";
            st1.printstack();
            cout << "st2: ";
            st2.printstack();
            
            st1.pop();
            cout << "st1: ";
            st1.printstack();
            cout << "st2: ";
            st2.printstack();

            break;

        default:
            break;
    }
    



}