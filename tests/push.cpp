#include "catch.hpp"
#include <stack.hpp>

SCENARIO("push element")
{
    GIVEN("stack")
    {
        Stack<int> st;
        st.Push(1);
        st.Push(2);
        size_t count = st.Count();

        WHEN("push element")
        {
            st.Push(3);

            THEN("count of elements must increase by one")
            {
                REQUIRE(st.Count() == count + 1);
            }
        }
    }
}
