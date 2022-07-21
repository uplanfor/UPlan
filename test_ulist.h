#include "test.hpp"
#include "UPlan/UList.hpp"


static void test01()
{
    {
        UList<int> list1;
        UList<int> list2(5);
        UList<int> list3(5, 10);
        UList<int> list4(list2);
        UList<int> list5 = {1, 3, 5, 7, 9};
        print_container(list1);
        print_container(list2);
        print_container(list3);
        print_container(list4);
        print_container(list5);
    }

    UList<int> list1;
    UList<int> list2(5, 6);
    for (int i = 0; i != 100; i += 5)
    {
        list1.pop_back();
        list2.pop_front();
    }
    for (int i = 5; i != 10; ++i)
    {
        list1.push_front(i * 2);
        list2.push_back(i * 3);
    }
    list1.swap(list2);
    print_container(list1);
    print_container(list2);
}


static void test02()
{

}