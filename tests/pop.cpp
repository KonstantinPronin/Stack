#include "catch.hpp"
#include <stack.hpp>

SCENARIO("decrease count after poping element")
{
    GIVEN("stack")
    {
        Stack<int> st;
        st.Push(1);
        st.Push(2);
        size_t count = st.Count();

        WHEN("pop an element")
        {
            st.Pop();

            THEN("count --")
            {
                REQUIRE(st.Count() == count - 1);
            }
        }
    }
}

SCENARIO("return last element after pop()")
{
    GIVEN("stack")
    {
        Stack<int> st;
        st.Push(1);
        st.Push(2);

        WHEN("pop an element")
        {
            int res = st.Pop();

            THEN("popped element must be 2")
            {
                REQUIRE(res == 2);
            }
        }
    }
}

SCENARIO("if stack is empty, pop method must throw an exception")
{
    GIVEN("empty stack")
    {
        Stack<int> st;

        WHEN("trying to pop an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(st.Pop(), std::logic_error&);
            }
        }
    }
}
