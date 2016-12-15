#include "catch.hpp"
#include <stack.hpp>

SCENARIO("return last element after top()")
{
    GIVEN("stack")
    {
        stack<int> st;
        st.push(1);
        st.push(2);

        WHEN("top an element")
        {
            int res = st.top();

            THEN("topped element must be 2")
            {
                REQUIRE(res == 2);
            }
        }
    }
}

SCENARIO("return element from empty stack")
{
	GIVEN("empty stack"){
		stack<int> st;
	
		WHEN("top an element"){
			THEN("must be error"){
				REQUIRE_THROWS_AS(st.top(), std::logic_error&);			
			}
		}
	

	}

}
