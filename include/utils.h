// swap实现
// max, min实现
// reverse实现（迭代器版本和其他）

namespace mydsa {

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

template<typename T>
T min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template<typename T>
T& reverse(T& input) {
    if (input.size()<=1) return input;
    int left = 0;
    int right = input.size() - 1;
    while (left < right) swap(input[left++], input[right--]);
    return input;
}


}