#ifndef MY_STACK_H_
#define MY_STACK_H_

#include <cstring>
#include <iostream>

class MyStack {
private:
    double* arr;    
    int capacity; 
    int top_ptr;      

public:
    MyStack() : capacity(0), top_ptr(-1), arr(nullptr) {}
    MyStack(int size) : capacity(size), top_ptr(-1) {
        arr = new double[capacity]; 
        memset(arr, 0, size*sizeof(double));
        top_ptr = size - 1;
    }

    MyStack(std::initializer_list<double> ilist) : capacity(ilist.size()), top_ptr(0) {
        arr = new double[capacity];
        for (double val : ilist) arr[top_ptr++] = val;
    }

    MyStack(MyStack&& other) noexcept : arr(other.arr), capacity(other.capacity), top_ptr(other.top_ptr) {
        other.arr = nullptr;
        other.capacity = 0;
        other.top_ptr = -1;
    }

    double top() {
        if (isEmpty()) {
            std::cout << "Stack is EMPTY" << std::endl;
            return 0;
        }
        return arr[top_ptr-1];
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is EMPTY" << std::endl;
            return;
        }
        top_ptr--;
    }

    void push(double value) {
        if (top_ptr == capacity - 1) {
            std::cout << "Stack is FULL" << std::endl;
            return;
        }
        arr[++top_ptr] = value;
    }

    void expand(int size) {
        if (size <= capacity) {
            std::cout << "New size must be greater than current size." << std::endl;
            return;
        }
        double* newArr = new double[size];
        memcpy(newArr, arr, capacity * sizeof(double));
        delete[] arr;
        arr = newArr;
        capacity = size;
    }

    bool isEmpty() {return top_ptr == -1;}

    MyStack& operator=(MyStack& lother) {
        std::swap(this->arr, lother.arr);
        std::swap(this->capacity, lother.capacity);
        std::swap(this->top_ptr, lother.top_ptr);
        return *this;
    }

    MyStack& operator=(MyStack&& rother) noexcept{
        if (this != &rother) {
            delete[] this->arr; 
            this->arr = rother.arr;
            this->capacity = rother.capacity;
            this->top_ptr = rother.top_ptr;

            rother.arr = nullptr;
            rother.capacity = 0;
            rother.top_ptr = -1;
        }
        return *this;
    }

    void printstack() {
        for (int i = 0; i < top_ptr; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    ~MyStack() {
        delete[] arr; 
    }

};

#endif