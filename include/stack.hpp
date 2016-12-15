#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Stack {
	T* array_;
	size_t array_size_;
	size_t count_;
public:
	Stack():array_(nullptr), array_size_(0), count_(0) {};
	~Stack();

	auto count() const noexcept -> size_t;
	auto empty() const noexcept -> bool;
	auto push(const T&) /*strong*/ -> void;
	auto pop() /*strong*/ -> void;
	auto top() /*strong*/ -> T;
};


template<typename T>
auto Stack<T>::count() const noexcept -> size_t{
	return count_;
}

template<typename T>
auto Stack<T>::empty() const noexcept -> bool{
	return !count_;
}

template<typename T>
auto Stack<T>::push(const T& element) /*strong*/-> void{
    
    	T* backup(nullptr);
	bool mem_alloc = false;
	
	if (array_size_ == count_) {
		
		T* tmp(nullptr);
		backup = array_;
		
		try {
			tmp = new T[++array_size_];

            		for (size_t i = 0; i < array_size_ - 1; ++i) {
                		tmp[i] = array_[i];
			}
		}
		catch (...) {
			delete[] tmp;
			--array_size_;
			throw;
		}
		
		array_ = tmp;
		flag = true;
	}
    
    
  	try{
	    array_[count_] = element;
    	}
    	catch(...){
        	if(mem_alloc) { 
			delete[] array_;
        		array_ = backup;
			--array_size_;
		}
        	throw;    
    	}

    	if (mem_alloc) 
		delete[] backup;
    	++count_;
}

template<typename T>
auto Stack<T>::pop() /*strong*/ -> void{
	if (count_)
		--count_;
	else
		throw std::logic_error("Stack is empty.");
}

template<typename T>
auto Stack<T>::top() /*strong*/ -> T {
    	if (count_)
        	return array_[count_ - 1];
    	else
		throw std::logic_error("Stack is empty.");
}

template<typename T>
Stack<T>::~Stack() {
	delete[] array_;
}

