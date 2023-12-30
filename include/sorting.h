#ifndef SORTING_H_
#define SORTING_H_

#include <functional>
#include "utils.h"


/*
实现十大经典排序算法：
1. 冒泡排序 2. 选择排序 3. 插入排序
4. 希尔排序 5. 归并排序 6. 快速排序
7. 堆排序 8. 计数排序 9. 桶排序 10. 基数排序
Implement the following sorting algorithms:
1. Bubble sort 2. Selection sort 3. Insertion sort
4. Shell sort 5. Merge sort 6. Quick sort
7. Heap sort 8. Counting sort 9. Bucket sort 10. Radix sort
*/

namespace mydsa{

/*
Bubble sort
Time Complexity: 
    Best: O(n)
    Average: O(n^2)
    Worst: O(n^2)
Space Complexity: O(1)
Stable: Yes
*/

template<typename T>
void bubble_sort(T& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

template<typename T, typename Compare>
void bubble_sort(T& nums, Compare comp) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comp(nums[j], nums[j+1])) {
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

/*
Selection sort
Time Complexity: 
    Best: O(n^2)
    Average: O(n^2)
    Worst: O(n^2)
Space Complexity: O(1)
Stable: No
*/

template<typename T>
void selection_sort(T& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[min_idx]) {
                min_idx = j;
            }
        }
        swap(nums[i], nums[min_idx]);
    }
}

template<typename T, typename Compare>
void selection_sort(T& nums, Compare comp) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (comp(nums[j], nums[min_idx])) {
                min_idx = j;
            }
        }
        swap(nums[i], nums[min_idx]);
    }
}


}
#endif