#include "allocator.hpp"


template <typename T>
class stack{
	allocator<T> alloc_;
public:
	stack() : alloc_() {};
	~stack() {};

	auto count() const noexcept->size_t;
	auto empty() const noexcept -> bool;
	auto push(const T&) /*strong*/ -> void;
	auto pop() /*strong*/ -> void;
	auto top() /*strong*/ -> T;
};


template<typename T>
auto stack<T>::count() const noexcept -> size_t {
	return alloc_.count();
}

template<typename T>
auto stack<T>::empty() const noexcept -> bool {
	return !alloc_.count();
}

template<typename T>
auto stack<T>::push(const T& element) /*strong*/-> void {	

	if (alloc_.full()) {
		if (!alloc_.resize()) 
			throw std::logic_error("Fail with memory allocation");
		try {
			alloc_.construct(alloc_.get() + alloc_.count(), element);
		}	
		catch (...) {
			alloc_.resize(-1);
			throw;
		}
		
	}
	else {
		try {
			alloc_.construct(alloc_.get() + alloc_.count(), element);
		}
		catch (...) {
			throw;
		}
	}
	alloc_.count_increase();
}

template<typename T>
auto stack<T>::pop() /*strong*/ -> void {
	if (!alloc_.empty())
		alloc_.count_decrease();
	else
		throw std::logic_error("Stack is empty.");
}

template<typename T>
auto stack<T>::top() /*strong*/ -> T {
	if (!alloc_.empty())
		return *(alloc_.get() + alloc_.count() - 1);
	else
		throw std::logic_error("Stack is empty.");
}

