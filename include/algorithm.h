#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "utils.h"
#include "listnode.h"
#include "linked_list.h"

// 反转链表 ✅

// n个一组反转链表实现 ❎

// 计算器（仅支持四则运算+括号）
// 输入字符或者数字，求出下一个组合



namespace mydsa {

//反转链表(ListNode版)
ListNode* reverse(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* prev = nullptr;
    auto curr = head;
    while (curr != nullptr) {
        auto next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}   

// n个一组反转链表实现



//反转链表(LinkedList版)
void reverse(LinkedList& linked_list) {
    auto prev_head = linked_list.head;
    linked_list.head = reverse(linked_list.head);
    linked_list.tail = prev_head;
}



}

#endif