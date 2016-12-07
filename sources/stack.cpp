#include <stack.hpp>

template<typename T>
inline size_t Stack<T>::Count() const{
	return count_;
}

template<typename T>
void Stack<T>::Push(const T& element){
	if (array_size_ == count_) {
		T* tmp = new T[++array_size_];
	
		for (size_t i = 0; i < array_size_ - 1; ++i) {
			tmp[i] = array_[i];
		}
		
		delete[] array_;
		array_ = tmp;
	}
	array_[count_++] = element;
}

template<typename T>
T Stack<T>::Pop() {
	if (!count_) throw std::logic_error("Stack is empty\n");
	return array_[--count_];
}

template<typename T>
Stack<T>::~Stack(){
	delete[] array_;
}

