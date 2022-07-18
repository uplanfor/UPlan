#include "test.hpp"
#include <forward_list>
#include "UPlan/UForwardList.hpp"

static void test01()
{
    UForwardList<int> list1;
    UForwardList<int> list2(5);
    UForwardList<int> list3(5, 9);
    list1.push_front(1);
    list3.push_front(4);
    UForwardList<int> list4(list3);

    list3.insert_after(list3.before_begin(), -1);
    // list4.erase_after(list4.before_begin());

    print_container(list1);
    print_container(list2);
    print_container(list3);
    print_container(list4);
}


static void test02()
{
    UForwardList<int> list1(7);
    UForwardList<int> list2(5);
    // list1.resize(0);
    // list2.resize(9, -1);

    print_container(list1);
    print_container(list2);
}

static void test03()
{

}