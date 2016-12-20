#include <iostream>
#include <string>
#include <exception>
#include <new>
#include <algorithm>
#include <utility>

template <typename T>
class allocator {
	T * array_;
	size_t size_;
	size_t count_;
public:
	explicit allocator(size_t size = 0);
	allocator(const allocator&);
	virtual ~allocator();
	
	auto swap(allocator& other) noexcept -> void;
	auto resize(int size = 1) noexcept -> bool;
	auto construct(T* ptr, const T& value) /*basic*/ -> void;
	auto destroy(T* ptr) noexcept -> void;
	auto get() noexcept -> T*;
	auto get() const noexcept  -> const T*;
	auto count() const noexcept -> size_t;
	auto full() const noexcept -> bool;
	auto empty() const noexcept -> bool;
	auto count_increase() noexcept -> void;
	auto count_decrease() noexcept -> void;

	auto operator=(allocator const&) -> allocator& = delete;
};

template <typename T>
allocator<T>::allocator(size_t size):size_(size), count_(0) {
	array_ = static_cast<T*> (::operator new[](size_ * sizeof(T)));
}

template <typename T>
allocator<T>::allocator(const allocator& other):size_(other.size_), count_(other.count_) {
	array_ = static_cast<T*> (::operator new[](size_ * sizeof(T)));
	std::copy(other.array_, other.array_ + count_, array_);
}

template <typename T>
allocator<T>::~allocator() {
	for (size_t i = 0; i < count_; ++i)
        	array_[i].~T(); 
    	::operator delete[] (array_);
}

template <typename T>
auto allocator<T>::swap(allocator& other) noexcept -> void {
	std::swap(array_, other.array_);
	std::swap(size_, other.size_);
	std::swap(count_, other.count_);
}

template <typename T>
auto allocator<T>::resize(int size) noexcept -> bool {
	if (!size) return true;
	if ((size_ + size) < 0) return false;
	
	T* tmp(nullptr);

	try {
		tmp = static_cast<T*> (::operator new[]((size_ + size) * sizeof(T)));
		if(count_ > (size_ + size)) std::copy(array_, array_ + size_ + size, tmp);
		else std::copy(array_, array_ + count_, tmp);
	} 
	catch (...) {
		delete[] tmp;
		return false;
	}

	array_ = tmp;
	size_ += size;
	return true;
}

template<typename T>
auto allocator<T>::construct(T* ptr, const T& value) /*basic*/ -> void {
	try {
	    new(ptr) T(value);
	}
	catch (...) {}
}

template<typename T>
auto allocator<T>::destroy(T* ptr) noexcept -> void {
	ptr -> ~T();
}

template<typename T>
auto allocator<T>::get() noexcept -> T* {
	return array_;
}

template<typename T>
auto allocator<T>::get() const  noexcept -> const T* {
	return array_;
}

template<typename T>
auto allocator<T>::count() const  noexcept -> size_t {
	return count_;
}

template<typename T>
auto allocator<T>::full() const noexcept -> bool {
	return (size_ == count_);
}

template<typename T>
auto allocator<T>::empty() const  noexcept -> bool {
	return !count_;
}

template<typename T>
auto allocator<T>::count_increase() noexcept -> void{
	if (!full()) ++count_;
	else return;
}

template<typename T>
auto allocator<T>::count_decrease() noexcept -> void{
	if (!empty()) --count_;
	else return;
}

