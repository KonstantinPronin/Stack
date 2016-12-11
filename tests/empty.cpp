#include "catch.hpp"
#include <stack.hpp>


SCENARIO("empty stack")
{
    GIVEN("Empty stack")
    {
        Stack<int> st;
        WHEN("Calling empty()")
        {
            THEN("empty() must return true")
            {
                REQUIRE(st.empty() == true);
            }
        }
    }

    GIVEN("Not empty stack")
    {
        Stack<int> st;
        st.push(1);
        WHEN("Calling empty()")
        {
            THEN("empty() must return false")
            {
                REQUIRE(st.empty() == false);
            }
        }
    }
}
