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
	size_t Count() const;
	void Push(const T&);
	T Pop();
	~Stack();
};


