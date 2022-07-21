#include "test.hpp"
#include "UPlan/UStack.hpp"


static void test01()
{
    UStack<int> s;
    s.push(5);
    s.push(6);
    std::cout << s.top() << std::endl;
}


static void test02()
{

}