#include <algorithm>
#include <iostream>
#include "listnode.h"
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

class LinkedList{
private:
    int length;
public:
    ListNode* head;
    ListNode* tail;
    LinkedList(): head(nullptr), tail(nullptr), length(0) {}
    LinkedList(double head_val): head(new ListNode(head_val)), tail(this->head), length(1) {}
    LinkedList(std::initializer_list<double> ilist) : head(nullptr), tail(nullptr), length(0) {
        for (double val : ilist) {append(val);}
    }
    LinkedList(ListNode* node): head(nullptr), tail(nullptr), length(0) {
        auto curr = node;
        ListNode* last = nullptr;
        while (curr != nullptr) {
            auto new_node = new ListNode(curr->val);
            if (last != nullptr) last->next = new_node;
            else this->head = new_node;
            last = new_node;
            if (curr->next == nullptr) tail = new_node;
            this->length++;
            curr = curr->next;
        }
    }
    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), length(0) {
        if (other.head == nullptr) {return;}
        auto curr_other = other.head;
        auto curr_new = new ListNode(curr_other->val);
        head = curr_new;
        this->length = 1;
        curr_other = curr_other->next;
        while (curr_other != nullptr) {
            curr_new->next = new ListNode(curr_other->val);
            curr_new = curr_new->next;
            this->length++;
            curr_other = curr_other->next;
        }
        this->tail = curr_new;
    }

    LinkedList& operator=(LinkedList other) { 
        std::swap(head, other.head); 
        std::swap(tail, other.tail); 
        std::swap(length, other.length); 
        return *this;
    }

    LinkedList operator+(const LinkedList& head_to_add) {
        LinkedList result;
        ListNode* curr = this->head;
        while (curr != nullptr) {
            result.append(curr->val);
            curr = curr->next;
        }
        curr = head_to_add.head;
        while (curr != nullptr) {
            result.append(curr->val); 
            curr = curr->next;
        }
        return result;
    }

    bool operator==(const LinkedList& other) {
        if (this->length != other.length) return false;
        auto curr_this = this->head;
        auto curr_other = other.head;
        while (curr_this != nullptr) {
            //if (&curr_this != &curr_other) return false;
            if (curr_this->val != curr_other->val) return false;
            curr_this = curr_this->next;
            curr_other = curr_other->next;
        }
        return true;
    }

    void append(double val) {
        auto to_append = new ListNode(val);
        if (this->tail == nullptr) { 
            this->head = to_append;
            this->tail = to_append;
        } 
        else {
            this->tail->next = to_append;
            this->tail = to_append;
        }
        this->length++;
    }

    void printlist() {
        auto curr = this->head;
        while (curr != nullptr) {
            if (curr->next == nullptr) std::cout << "(" << curr->val << ") " << std::endl;
            else std::cout << "(" << curr->val << ") -> ";
            curr = curr->next;
        }
    }

    int size() {return this->length;};

    ~LinkedList() {
        ListNode* curr = this->head;
        while (curr != nullptr) {
            auto next_node = curr->next;
            delete curr;
            curr = next_node;
        }
    }
};

#endif