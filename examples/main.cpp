#include <stack.hpp>

int main() {
	try {
		Stack<int> st;
		st.Push(1);
		st.Push(2);
		st.Push(5);

		std::cout << st.Pop() << std::endl;
		std::cout << st.Pop() << std::endl;
		std::cout << st.Pop() << std::endl;
		std::cout << st.Pop() << std::endl;
	}
	catch (std::logic_error& e) {
		std::cout << e.what();
	}

	return 0;
}
