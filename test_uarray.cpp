#include <iostream>
#include "UPlan/UArray.hpp"
#include <array>


int main()
{
    UArray<int, 5> arr;
    arr[0] = 3;
    arr[1] = 4;
    arr[2] = 5;
    arr[3] = 6;
    arr[4] = 7;
    UArray<int, 5> arr2;
    arr2.fill(5);
    arr2.swap(arr);

    for (const auto i : arr)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    for (const auto i : arr2)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    std::array<int, 6> a = {1, 2};
    system("pause");
    return 0;
}