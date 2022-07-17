#include <iostream>
#include <array>
#include "test.hpp"
#include "UPlan/UArray.hpp"


static void test01()
{
    UArray<int, 5> arr = {1, 2, 3, 4, 5};
    print_container(arr);
}

