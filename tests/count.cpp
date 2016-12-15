#include "catch.hpp"
#include <stack.hpp>

SCENARIO("empty stack return count")
{
    GIVEN("empty stack")
    {
        stack<int> st;

        WHEN("count()")
        {
            THEN("count must be 0")
            {
                REQUIRE(st.count() == 0);
            }
        }
    }
}

SCENARIO("non-empty stack return count")
{
    GIVEN("non-empty stack")
    {
        stack<int> st;
        st.push(1);
        st.push(2);

        WHEN("count()")
        {
            THEN("count must not be 0")
            {
                REQUIRE(st.count() != 0);
            }
        }
    }
}
