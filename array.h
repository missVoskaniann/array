#ifndef ARRAY_H
#define ARRAY_H
#include <cstddef>
#include <iterator>
#include <ostream>

template <typename T, std::size_t N>
class array {
public:
    array();
    array(const array &oth);
    array& operator=(const array& oth);
    array(array&& oth) noexcept;
    array& operator=(array&& oth) noexcept;

    T& at(std::size_t pos);
    const T& at(std::size_t pos) const;
    T& operator[](std::size_t pos);
    const T& operator[](std::size_t pos) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    T* data();
    const T* data() const;

    T* begin();
    const T* begin() const;
    T* end();
    const T* end() const;
    std::reverse_iterator<T*> rbegin();
    std::reverse_iterator<const T*> rbegin() const;
    std::reverse_iterator<T*> rend();
    std::reverse_iterator<const T*> rend() const;
    std::reverse_iterator<const T*> crbegin() const; 
    std::reverse_iterator<const T*> crend() const;
    
    const std::size_t size() const;
    const bool empty() const;
    const std::size_t max_size() const;

    void fill(const T& value);
    void swap(array& oth);


private:
    T arr[N];
    const std::size_t arr_size;

    template <typename U, std::size_t M>
    friend bool operator==(const array<U, M>& lhs, const array<U, M>& rhs);
    template <typename U, std::size_t M>
    friend bool operator!=(const array<U, M>& lhs, const array<U, M>& rhs);
    template <typename U, std::size_t M>
    friend bool operator<(const array<U, M>& lhs, const array<U, M>& rhs);
    template <typename U, std::size_t M>
    friend bool operator<=(const array<U, M>& lhs, const array<U, M>& rhs);
    template <typename U, std::size_t M>
    friend bool operator>(const array<U, M>& lhs, const array<U, M>& rhs);
    template <typename U, std::size_t M>
    friend bool operator>=(const array<U, M>& lhs, const array<U, M>& rhs);
    template <typename U, std::size_t M>
    friend std::ostream& operator<<(std::ostream& os, const array<U, M>& arr);
};

template <typename T, std::size_t N>
bool operator==(const array<T, N>& lhs, const array<T, N>& rhs);

template <typename T, std::size_t N>
bool operator!=(const array<T, N>& lhs, const array<T, N>& rhs);

template <typename T, std::size_t N>
bool operator<(const array<T, N>& lhs, const array<T, N>& rhs);

template <typename T, std::size_t N>
bool operator<=(const array<T, N>& lhs, const array<T, N>& rhs);

template <typename T, std::size_t N>
bool operator>(const array<T, N>& lhs, const array<T, N>& rhs);

template <typename T, std::size_t N>
bool operator>=(const array<T, N>& lhs, const array<T, N>& rhs);

template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const array<T, N>& arr);

#include "array.tpp"
#endif // ARRAY_H
