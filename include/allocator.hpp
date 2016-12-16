#include <iostream>
#include <string>
#include <exception>
#include <new>
#include <algorithm>
#include <utility>

template <typename T>
class allocator {
public:
	allocator(size_t size = 0);
	allocator(allocator const&) = delete;
	virtual ~allocator();
	
	auto swap(allocator& other) noexcept -> void;
	auto operator=(allocator const&) -> allocator& = delete;

	T * array_;
	size_t size_;
	size_t count_;
};

template <typename T>
allocator<T>::allocator(size_t size):size_(size), count_(0) {
	array_ = static_cast<T*> (::operator new[](size_ * sizeof(T)));
}

template <typename T>
allocator<T>::~allocator() {
	delete[] array_;
}

template <typename T>
auto allocator<T>::swap(allocator& other) noexcept -> void {
	std::swap(array_, other.array_);
	std::swap(size_, other.size_);
	std::swap(count_, other.count_);
}

