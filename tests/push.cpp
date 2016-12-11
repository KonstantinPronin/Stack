#include "catch.hpp"
#include <stack.hpp>

SCENARIO("push element")
{
    GIVEN("stack")
    {
        Stack<int> st;
        st.push(1);
        st.push(2);
        size_t count = st.count();

        WHEN("push element")
        {
            st.push(3);

            THEN("count of elements must increase by one")
            {
                REQUIRE(st.count() == count + 1);
            }
        }
    }
}
