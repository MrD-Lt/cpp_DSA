#include "../include/linked_list.h"
#include <iostream>

using namespace std;

int main() {
    LinkedList ll1({1,2,3,4,5,6,7,8,9,10});
    LinkedList ll2({1,2,3,4,5,6,7,8,9,10});

    cout << "ll1: ";
    ll1.printlist();
    cout << "ll2: ";
    ll2.printlist();

    cout << "ll1 == ll2: " << (ll1 == ll2) << endl;

    

}