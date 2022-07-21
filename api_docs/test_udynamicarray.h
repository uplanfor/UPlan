#include <vector>
#include "test.hpp"
#include "UPlan/UDynamicArray.hpp"

static void test01()
{
    UDynamicArray<int> arr;
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(5);
    UDynamicArray<int> arr2 = {1, 3, 5, 7, 9};
    UDynamicArray<int> arr3(arr);
    arr2.swap(arr);
    arr2.push_back(7);
    // arr3.push_back(6);
    printf("size: %d capacity: %d\n", arr3.size(), arr3.capacity());
    for (int i = 0; i != 20; ++i)
    {
        arr2.pop_back();
    }
    for (int i = 1; i != 4; ++i)
    {
        arr2.push_back(5 * i);
    }

    print_container(arr);
    print_container(arr2);
    print_container(arr3);
}

static void test02()
{
    UDynamicArray<int> arr = {6, 7, 8, 9, 10, 11};
    UDynamicArray<int> arr2 = {1, 2, 3, 4, 5};
    // arr.pop_back();
    auto beg = ++arr2.begin();
    auto end = --arr2.end();
    arr.insert(++arr.begin(), beg, end);
    print_container(arr);
    print_container(arr2);

    arr.erase(--arr.end());
    print_container(arr);
    arr.erase(----arr.end());
    print_container(arr);
    // std::vector<int> v;
    // v.insert();
    arr.erase(++++arr.begin(), --arr.end());
    print_container(arr);
}

static void test03()
{
    UDynamicArray<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15};
}
