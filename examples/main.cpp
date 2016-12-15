#include <stack.hpp>

int main() {
	try {
		stack<int> st;
		st.push(1);
		st.push(2);
		st.push(5);

		st.pop();
		std::cout << st.top() << std::endl;
	}
	catch (std::logic_error& e) {
		std::cout << e.what();
	}

	return 0;
}
