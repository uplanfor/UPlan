#ifndef _TEST_HPP
#define _TEST_HPP
#include <iostream>

template<typename Container>
void print_container(const Container &con)
{
    for (auto it = con.cbegin(); it != con.cend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


template<typename Container>
void debug_container(const Container &con)
{
    for (auto it = con.cbegin(); it != con.cend(); ++it)
    {
        std::cout << "val " << *it << " address " << &*it << " ";
        system("pause");
    }
    std::cout << std::endl;
}
#endif // !_TEST_HPP