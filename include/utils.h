#ifndef UTILS_H_
#define UTILS_H_

#include <initializer_list>
#include <iostream>


/**
 * @namespace mydsa
 * @brief Namespace for MyDSA (My Data Structures and Algorithms) library.
 * 
 * This namespace contains various utility functions and templates for data structures and algorithms.
 */
namespace mydsa {

template<typename ForwardIterator>
ForwardIterator max_element(ForwardIterator first, ForwardIterator last) {
    if (first == last) return last;
    ForwardIterator max_ele = first;
    first++;
    for (; first != last; first++) {
        if (*max_ele < *first) {
            max_ele = first;
        }
    }
    return max_ele;
}

template<typename ForwardIterator>
ForwardIterator min_element(ForwardIterator first, ForwardIterator last) {
    if (first == last) return last;
    ForwardIterator min_ele = first;
    first++;
    while (first != last) {
        if (*min_ele > *first) {
            min_ele = first;
        }
        first++;
    }
    return min_ele;
}

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
const T& max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

template <class T, class Compare>
const T& max(const T& a, const T& b, Compare comp) {
    return comp(a, b) ? b : a;
}

template <class T>
T max(std::initializer_list<T> ilist) {
    return *max_element(ilist.begin(), ilist.end());
}

template<typename T>
const T& min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template <class T, class Compare>
const T& min(const T& a, const T& b, Compare comp) {
    return comp(a, b) ? a : b;
}

template <class T>
T min(std::initializer_list<T> ilist) {
    return *min_element(ilist.begin(), ilist.end());
}

template<typename T>
T& reverse(T& input) {
    if (input.size()<=1) return input;
    int left = 0;
    int right = input.size() - 1;
    while (left < right) swap(input[left++], input[right--]);
    return input;
}

template<typename T>
void print(const T& input) {
    for (auto it = input.begin(); it != input.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

}

#endif