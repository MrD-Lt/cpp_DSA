#include "../include/my_dsa.h"
#include <iostream>

using namespace std;

// g++ -std=c++20 -g -o main main.cpp  

int main() {
    int test_case = 1;
    mydsa::LinkedList ll1({1,2,3,4,5,6,7,8,9,10});
    mydsa::LinkedList ll2({1,2,3,4,5,6,7,8,9,10});

    mydsa::MyStack st1({1,2,3,4,5,6,7,8,9,10});
    mydsa::MyStack st2({1,2,3,4,5,6,7,8,9,10});
    
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

            // test Iterator
            for (auto it = ll1.begin(); it != ll1.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
            // test min
            cout << min<double>({1,2,3,4,0.5,6,7,8,9,10}) << endl;
            // test max
            cout << max<double>({1,2,3,4,0.5,6,7,8,9,10}) << endl;
            cout << endl;
            reverse(ll1);
            ll1.printlist();
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