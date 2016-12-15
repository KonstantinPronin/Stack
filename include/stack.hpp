#include "allocator.hpp"


template <typename T>
class stack:protected allocator<T>{

public:
	stack() : allocator<T>() {};
	~stack() {};

	auto count() const noexcept->size_t;
	auto empty() const noexcept -> bool;
	auto push(const T&) /*strong*/ -> void;
	auto pop() /*strong*/ -> void;
	auto top() /*strong*/ -> T;
};


template<typename T>
auto stack<T>::count() const noexcept -> size_t {
	return allocator<T>::count_;
}

template<typename T>
auto stack<T>::empty() const noexcept -> bool {
	return !allocator<T>::count_;
}

template<typename T>
auto stack<T>::push(const T& element) /*strong*/-> void {

	if (allocator<T>::size_ == allocator<T>::count_) {
		allocator<T> tmp(allocator<T>::size_ + 1);
		
		try {
			std::copy(allocator<T>::array_, allocator<T>::array_ + allocator<T>::count_, tmp.array_);
			tmp.count_ = allocator<T>::count_;
			tmp.array_[tmp.count_++] = element;
		}	
		catch (...) {
			throw;
		}
		allocator<T>::swap(tmp);
	
	}
	else {
		try {
			allocator<T>::array_[allocator<T>::count_] = element;
		}
		catch (...) {
			throw;
		}
		++allocator<T>::count_;
	}
}

template<typename T>
auto stack<T>::pop() /*strong*/ -> void {
	if (allocator<T>::count_)
		--allocator<T>::count_;
	else
		throw std::logic_error("Stack is empty.");
}

template<typename T>
auto stack<T>::top() /*strong*/ -> T {
	if (allocator<T>::count_)
		return allocator<T>::array_[allocator<T>::count_ - 1];
	else
		throw std::logic_error("Stack is empty.");
}


