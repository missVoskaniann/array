#include "array.h"
#include <iostream>

template <typename T, std::size_t N> 
array<T, N>::array() : arr_size{N} {}

template <typename T, std::size_t N>
array<T, N>::array(const array &oth) : arr_size{N} {
    for (std::size_t i = 0; i < arr_size; ++i) {
        arr[i] = oth.arr[i];
    }
}

template <typename T, std::size_t N> 
array<T, N>& array<T, N>::operator=(const array& oth) {
    if (this != &oth) {
        for (std::size_t i = 0; i < arr_size; ++i) {
            arr[i] = oth.arr[i];
        }
    }
    return *this;
}

template <typename T, std::size_t N> 
array<T, N>::array(array&& oth) noexcept : arr_size{N} {
    for (std::size_t i = 0; i < arr_size; ++i) {
        arr[i] = std::move(oth.arr[i]);
    } 
}
 
template <typename T, std::size_t N>
array<T, N>& array<T, N>::operator=(array&& oth) noexcept {
    if (this != &oth) {
        for (std::size_t i = 0; i < arr_size; ++i) {
            arr[i] = std::move(oth.arr[i]);
        }
    }
    return *this;
}  

template <typename T, std::size_t N> 
T& array<T, N>::at(std::size_t pos) {
    if (pos >= N) {
        throw std::out_of_range("The given position is out of range");
    } 
    return arr[pos];
}


template <typename T, std::size_t N> 
const T& array<T, N>::at(std::size_t pos) const{
    if (pos >= N) {
        throw std::out_of_range("The given position is out of range");
    } 
    return arr[pos];
}

template <typename T, std::size_t N> 
T& array<T, N>::operator[](std::size_t pos) {
    return arr[pos];
}

template <typename T, std::size_t N> 
const T& array<T, N>::operator[](std::size_t pos) const {
    return arr[pos];
}

template <typename T, std::size_t N> 
T& array<T, N>::front() {
    return arr[0];
}

template <typename T, std::size_t N> 
const T& array<T, N>::front() const{
    return arr[0];
}

template <typename T, std::size_t N> 
T& array<T, N>::back() {
    return arr[arr_size - 1];
}

template <typename T, std::size_t N> 
const T& array<T, N>::back() const {
    return arr[arr_size - 1];
}

template <typename T, std::size_t N> 
T* array<T, N>::data() {
    return arr;
}

template <typename T, std::size_t N> 
const T* array<T, N>::data() const {
    return arr;
}

template <typename T, std::size_t N> 
T* array<T, N>::begin() {
    return arr;
}

template <typename T, std::size_t N> 
const T* array<T, N>::begin() const {
    return arr;
}

template <typename T, std::size_t N> 
T* array<T, N>::end() {
    return arr + arr_size;
}

template <typename T, std::size_t N> 
const T* array<T, N>::end() const {
    return arr + arr_size;
}

template <typename T, std::size_t N>
std::reverse_iterator<T*> array<T, N>::rbegin() {
    return std::reverse_iterator<T*>(end());
}

template <typename T, std::size_t N>
std::reverse_iterator<const T*> array<T, N>::rbegin() const{
    return std::reverse_iterator<const T*>(end());
}

template <typename T, std::size_t N>
std::reverse_iterator<T*> array<T, N>::rend() {
    return std::reverse_iterator<T*>(begin());
}

template <typename T, std::size_t N>
std::reverse_iterator<const T*> array<T, N>::rend() const{
    return std::reverse_iterator<const T*>(begin());
}

template <typename T, std::size_t N>
std::reverse_iterator<const T*> array<T, N>::crbegin() const{
    return std::reverse_iterator<const T*>(end());
}

template <typename T, std::size_t N>
std::reverse_iterator<const T*> array<T, N>::crend() const{
    return std::reverse_iterator<const T*>(begin());
}

template <typename T, std::size_t N> 
const std::size_t array<T, N>::size() const {
    return arr_size;
}

template <typename T, std::size_t N> 
const bool array<T, N>::empty() const {
    return arr_size == 0;
}

template <typename T, std::size_t N> 
const std::size_t array<T, N>::max_size() const {
    return arr_size;
}

template <typename T, std::size_t N> 
void array<T, N>::fill(const T& value) {
    for (std::size_t i = 0; i < arr_size; ++i) {
        arr[i] = value;
    }
}

template <typename T, std::size_t N>
void array<T, N>::swap(array& oth) {
    for (std::size_t i = 0; i < arr_size; ++i) {
        T tmp = std::move(arr[i]);
        arr[i] = std::move(oth.arr[i]);
        oth.arr[i] = std::move(tmp);
    }
}

template <typename T, std::size_t N> 
bool operator==(const array<T, N>& lhs, const array<T, N>& rhs) {
    for (std::size_t i = 0; i < N; ++i) {
        if (lhs.arr[i] != rhs.arr[i]) {
            return false;
        }
    }
    return true;
}

template <typename T, std::size_t N>
bool operator!=(const array<T, N>& lhs, const array<T, N>& rhs) {
    return !(lhs == rhs);
}

template <typename T, std::size_t N>
bool operator<(const array<T, N>& lhs, const array<T, N>& rhs) {
    for (std::size_t i = 0; i < N; ++i) {
        if (lhs.arr[i] < rhs.arr[i]) {
            return true;
        } else if (lhs.arr[i] > rhs.arr[i]) {
            return false;
        }
    }
    return false;
}

template <typename T, std::size_t N>
bool operator<=(const array<T, N>& lhs, const array<T, N>& rhs) {
    return !(rhs < lhs);
}

template <typename T, std::size_t N>
bool operator>(const array<T, N>& lhs, const array<T, N>& rhs) {
    return rhs < lhs;
}

template <typename T, std::size_t N>
bool operator>=(const array<T, N>& lhs, const array<T, N>& rhs) {
    return !(lhs < rhs);
}

template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const array<T, N>& arr) {
    os << "{ ";
    for (std::size_t i = 0; i < N; ++i) {
        os << arr[i] << " ";
    }
    os << "}";
    return os;
}

