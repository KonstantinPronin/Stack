#include "catch.hpp"
#include <stack.hpp>

SCENARIO("decrease count after poping element")
{
    GIVEN("stack")
    {
        stack<int> st;
        st.push(1);
        st.push(2);
        size_t count = st.count();

        WHEN("pop an element")
        {
            st.pop();

            THEN("count --")
            {
                REQUIRE(st.count() == count - 1);
            }
        }
    }
}

SCENARIO("if stack is empty, pop method must throw an exception")
{
    GIVEN("empty stack")
    {
        stack<int> st;

        WHEN("trying to pop an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(st.pop(), std::logic_error&);
            }
        }
    }
}
