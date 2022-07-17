#include <iostream>
#include <vector>
#include "UPlan/UVector.hpp"

template <class Container>
void print_container(Container &con)
{
    for (auto it = con.cbegin(); it != con.cend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test01()
{
    std::vector<int> v;
    UVector<int> mv(5, 6);
    print_container(mv);
}

void test02()
{
}


int main()
{
    test01();
    // test02();
    system("pause");
    return 0;
}