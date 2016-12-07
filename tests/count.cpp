#include "catch.hpp"
#include <stack.hpp>

SCENARIO("empty stack return count")
{
    GIVEN("empty stack")
    {
        Stack<int> st;

        WHEN("count()")
        {
            THEN("count must be 0")
            {
                REQUIRE(st.Count() == 0);
            }
        }
    }
}

SCENARIO("non-empty stack return count")
{
    GIVEN("non-empty stack")
    {
        Stack<int> st;
        st.Push(1);
        st.Push(2);

        WHEN("count()")
        {
            THEN("count must not be 0")
            {
                REQUIRE(st.Count() != 0);
            }
        }
    }
}
