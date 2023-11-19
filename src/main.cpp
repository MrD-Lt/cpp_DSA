#include "../include/linked_list.h"
#include <iostream>

using namespace std;

int main() {
    auto node1 = new ListNode(1);
    auto node2 = new ListNode(2);
    node1->next = node2;
    LinkedList ll1(node1);
    ll1.printlist();
    LinkedList ll2({1,2,3,4,5,6,7,8,9,10});
    ll2.printlist();
    cout << &ll2 << endl;
    cout << &ll1 << endl;
    ll1 = ll2;
    ll2.head->val = 9999;
    ll2.printlist();
    ll1.printlist();
    cout << &ll2 << endl;
    cout << &ll1 << endl;

    cout << ll2.size() << endl;
}