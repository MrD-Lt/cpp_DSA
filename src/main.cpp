#include "../include/my_dsa.h"
#include <iostream>
#include <vector>

using namespace std;

// g++ -std=c++20 -g -o main main.cpp  
// valgrind --leak-check=full ./main

int main() {
    int test_case = 1;
    cin >> test_case;
    mydsa::LinkedList ll1({1,2,3,4,5,6,7,8,9,10});
    mydsa::LinkedList ll2({1,2,3,4,5,6,7,8,9,10});

    mydsa::MyStack st1({1,2,3,4,5,6,7,8,9,10});
    mydsa::MyStack st2({1,2,3,4,5,6,7,8,9,10});
    
    switch (test_case) {
        case 1: // test LinkedList
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
            reverse(ll1);
            ll1.printlist();

            // test min and max
            cout << "min: " << mydsa::min<double>({-1,2,3,4,5,-6,7,8,9,10}) << endl;
            cout << "max: " << mydsa::max<double>({-1,2,3,4,5,-6,7,28.5,9,10}) << endl;
            break;
        
        case 2: // test MyStack
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

        case 3: // test sorting algorithms
            vector<double> v1({2,1,3,-1,5,6,0,-20,18,32});
            mydsa::bubble_sort(v1);
            mydsa::print(v1);
            mydsa::selection_sort(v1,greater<int>());
            mydsa::print(v1);
            break;

    }
    



}