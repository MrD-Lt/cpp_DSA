#ifndef LISTNODE_H_
#define LISTNODE_H_
class ListNode {
public:
    double val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(double val): val(val), next(nullptr) {};
    ListNode(double val, ListNode* next): val(val), next(next) {};
};
#endif